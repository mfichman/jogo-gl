/*****************************************************************************
 * Simple, Fast Renderer (SFR)                                               *
 * CS249b                                                                    *
 * Matt Fichman                                                              *
 * February, 2011                                                            *
 *****************************************************************************/
 
uniform sampler2D shadowMap;
uniform sampler2D diffuseBuffer;
uniform sampler2D specularBuffer;
uniform sampler2D normalBuffer;
uniform sampler2D positionBuffer;
uniform sampler2D depthBuffer;

uniform float atten0; 
uniform float atten1;
uniform float atten2;
uniform vec3 Ld;
uniform vec3 Ls;
uniform float spotCutoff;
uniform float spotPower;
uniform vec3 direction;

uniform mat4 unprojectMatrix; // Back to view coordinates
uniform mat4 lightMatrix; // From eye coordinates to light space

varying vec3 lightPosition;
varying vec4 position;

/* Deferred spot light shader */
void main() {
	// Sample the depth and reconstruct the fragment view coordinates. 
	// Perform the viewport transform on the clip position. 
	// Make sure the depth is unpacked into clip coordinates.
	vec2 normalized = position.xy/position.w;
	vec2 viewport = vec2((normalized.x + 1.)/2., (normalized.y + 1.)/2.);
	float depth = texture2D(depthBuffer, viewport).r;
	vec4 eyePosition = unprojectMatrix * vec4(normalized, 2. * depth - 1., 1.);
	eyePosition = eyePosition/eyePosition.w;
	
	// Sample the materials using the screen position
	vec3 Kd = texture2D(diffuseBuffer, viewport).rgb;
	vec4 temp = texture2D(specularBuffer, viewport);
	vec3 Ks = temp.rgb;
	float alpha = temp.a;

    // Get the world position
    vec3 world = texture2D(positionBuffer, viewport).xyz * 2. - 1.;
    vec4 shadow = lightMatrix * vec4(world, 1.);
    shadow /= shadow.w;
    float shadowDepth = texture2D(shadowMap, shadow.xy).r;

	// Sample the normal and the view vector
	vec3 N = texture2D(normalBuffer, viewport).xyz * 2. - 1.;
	vec3 V = normalize(-eyePosition.xyz);
	vec3 R = reflect(-V, N);
	vec3 L = lightPosition - eyePosition.xyz;
	float D = length(L);
	float atten = 1./(atten0 + atten1 * D + atten2 * D * D);
	L = normalize(L);

	float Rd = dot(N, L);
    float spotEffect = clamp(dot(direction, -L), 0., 1.);

	if (Rd > 0. && spotEffect > spotCutoff) { //&& shadow.z <= shadowDepth) {

		// Calculate the diffuse color coefficient
		vec3 diffuse = Kd * Ld * Rd;

		// Calculate the specular color coefficient
		vec3 specular = Ks * Ls * pow(max(0., dot(L, R)), alpha);

		// Calculate the shadow coord
		gl_FragColor = vec4(diffuse + specular, 1.);
		gl_FragColor.xyz *= atten * pow(spotEffect, spotPower);
	} else {
		gl_FragColor = vec4(0., 0., 0., 1.);
	}

	gl_FragDepth = depth;
}
