/*
 * Copyright (c) 2013 Matt Fichman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, APEXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <Primitives.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(WINDOWS)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <Gl/gl3w.h>
#include <Gl/glcorearb.h>
#include <GL/gl.h>
#include <GL/glu.h>
#elif defined(DARWIN)
//#include <Gl/gl3w.h> True OpenGl 3+ support not enabled
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif defined(LINUX)
#endif

void Gl_check() {
    GLenum err = glGetError();
    switch (err) {
    case GL_NO_ERROR: return;
    case GL_INVALID_ENUM: fprintf(stderr, "GL_INVALID_ENUM\n"); abort();
    case GL_INVALID_VALUE: fprintf(stderr, "GL_INVALID_VALUE\n"); abort();
    case GL_INVALID_OPERATION: fprintf(stderr, "GL_INVALID_OPERATION\n"); abort();
    case GL_OUT_OF_MEMORY: fprintf(stderr, "GL_OUT_OF_MEMORY\n"); abort();
    //case GL_STACK_UNDERFLOW: fprintf(stderr, "GL_STACK_UNDERFLOW\n"); abort();
    //case GL_STACK_OVERFLOW: fprintf(stderr, "GL_STACK_OVERFLOW\n"); abort();
    default: fprintf(stderr, "Unknown OpenGL error\n"); abort();
    }
}

void Gl_perspective(Float fovy, Float aspect, Float n, Float f) {
    gluPerspective(fovy, aspect, n, f);
}

void Gl_viewport(Int x, Int y, Int width, Int height) {
    glViewport(x, y, width, height);
}

void Gl_matrix_mode(Int val) {
    glMatrixMode(val);
}

void Gl_clear(Int mask) {
    glClear(mask);
}

void Gl_clear_color(Float red, Float blue, Float green, Float alpha) {
    glClearColor(red, blue, green, alpha);
}

void Gl_clear_depth(Float depth) {
    glClearDepth(depth);
}

void Gl_enable(Int val) {
    glEnable(val);
}

void Gl_translatef(Float x, Float y, Float z) {
    glTranslatef((float)x, (float)y, (float)z);
}

void Gl_load_identity() {
    glLoadIdentity();
}

void Gl_begin(Int val) {
    glBegin(val);
}

void Gl_end() {
    glEnd();
}
    
void Gl_vertex3f(Float x, Float y, Float z) {
    glVertex3f((float)x, (float)y, (float)z);
}

void Gl_depth_func(Int val) {
    glDepthFunc(val);
}

void Gl_flush() {
    glFlush();
}

void Gl_init() {
#ifndef DARWIN
    if (gl3wInit()) {
        fprintf(stderr, "Failed to initialize OpenGL\n");
        abort(); 
    }
#endif
}

Bool Gl_supported(Int major, Int minor) {
#ifndef DARWIN
    return gl3wIsSupported(major, minor);
#else
/*
    GLint supported_major = 0;
    GLint supported_minor = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &supported_major);
    glGetIntegerv(GL_MINOR_VERSION, &supported_minor);
    printf("%s\n", glGetString(GL_VERSION));
    printf("%d %d\n", supported_major, supported_minor);
    if (supported_major < major) {
        return 0;
    }
    if (supported_minor < minor) {
        return 0;
    }
    return 1;
*/

    return 0;


#endif
}

