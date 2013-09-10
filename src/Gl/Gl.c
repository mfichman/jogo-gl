#include "Gl\GlDefs.h"
#include "Primitives.h"
void Gl_accum(Int op, Float value) {
    glAccum(op, value);
}
void Gl_alpha_func(Int glfunc, Float ref) {
    glAlphaFunc(glfunc, ref);
}
void Gl_array_element(Int i) {
    glArrayElement(i);
}
void Gl_begin(Int mode) {
    glBegin(mode);
}
void Gl_bind_texture(Int target, Int texture) {
    glBindTexture(target, texture);
}
void Gl_blend_color(Float red, Float green, Float blue, Float alpha) {
    glBlendColor(red, green, blue, alpha);
}
void Gl_blend_equation(Int mode) {
    glBlendEquation(mode);
}
void Gl_blend_equation_separate(Int modergb, Int modealpha) {
    glBlendEquationSeparate(modergb, modealpha);
}
void Gl_blend_func(Int sfactor, Int dfactor) {
    glBlendFunc(sfactor, dfactor);
}
void Gl_call_list(Int list) {
    glCallList(list);
}
void Gl_clear(Int mask) {
    glClear(mask);
}
void Gl_clear_accum(Float red, Float green, Float blue, Float alpha) {
    glClearAccum(red, green, blue, alpha);
}
void Gl_clear_color(Float red, Float green, Float blue, Float alpha) {
    glClearColor(red, green, blue, alpha);
}
void Gl_clear_depth(Float depth) {
    glClearDepth(depth);
}
void Gl_clear_index(Float c) {
    glClearIndex(c);
}
void Gl_clear_stencil(Int s) {
    glClearStencil(s);
}
void Gl_color3b(Byte red, Byte green, Byte blue) {
    glColor3b(red, green, blue);
}
void Gl_color3d(Float red, Float green, Float blue) {
    glColor3d(red, green, blue);
}
void Gl_color3f(Float red, Float green, Float blue) {
    glColor3f(red, green, blue);
}
void Gl_color3i(Int red, Int green, Int blue) {
    glColor3i(red, green, blue);
}
void Gl_color3s(Int red, Int green, Int blue) {
    glColor3s(red, green, blue);
}
void Gl_color3ub(Byte red, Byte green, Byte blue) {
    glColor3ub(red, green, blue);
}
void Gl_color3ui(Int red, Int green, Int blue) {
    glColor3ui(red, green, blue);
}
void Gl_color3us(Int red, Int green, Int blue) {
    glColor3us(red, green, blue);
}
void Gl_color4b(Byte red, Byte green, Byte blue, Byte alpha) {
    glColor4b(red, green, blue, alpha);
}
void Gl_color4d(Float red, Float green, Float blue, Float alpha) {
    glColor4d(red, green, blue, alpha);
}
void Gl_color4f(Float red, Float green, Float blue, Float alpha) {
    glColor4f(red, green, blue, alpha);
}
void Gl_color4i(Int red, Int green, Int blue, Int alpha) {
    glColor4i(red, green, blue, alpha);
}
void Gl_color4s(Int red, Int green, Int blue, Int alpha) {
    glColor4s(red, green, blue, alpha);
}
void Gl_color4ub(Byte red, Byte green, Byte blue, Byte alpha) {
    glColor4ub(red, green, blue, alpha);
}
void Gl_color4ui(Int red, Int green, Int blue, Int alpha) {
    glColor4ui(red, green, blue, alpha);
}
void Gl_color4us(Int red, Int green, Int blue, Int alpha) {
    glColor4us(red, green, blue, alpha);
}
void Gl_color_mask(Bool red, Bool green, Bool blue, Bool alpha) {
    glColorMask(red, green, blue, alpha);
}
void Gl_color_material(Int face, Int mode) {
    glColorMaterial(face, mode);
}
void Gl_convolution_parameterf(Int target, Int pname, Float params) {
    glConvolutionParameterf(target, pname, params);
}
void Gl_convolution_parameteri(Int target, Int pname, Int params) {
    glConvolutionParameteri(target, pname, params);
}
void Gl_copy_color_sub_table(Int target, Int start, Int x, Int y, Int width) {
    glCopyColorSubTable(target, start, x, y, width);
}
void Gl_copy_color_table(Int target, Int internalformat, Int x, Int y, Int width) {
    glCopyColorTable(target, internalformat, x, y, width);
}
void Gl_copy_convolution_filter1d(Int target, Int internalformat, Int x, Int y, Int width) {
    glCopyConvolutionFilter1D(target, internalformat, x, y, width);
}
void Gl_copy_convolution_filter2d(Int target, Int internalformat, Int x, Int y, Int width, Int height) {
    glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);
}
void Gl_copy_pixels(Int x, Int y, Int width, Int height, Int type) {
    glCopyPixels(x, y, width, height, type);
}
void Gl_copy_tex_image1d(Int target, Int level, Int internalformat, Int x, Int y, Int width, Int border) {
    glCopyTexImage1D(target, level, internalformat, x, y, width, border);
}
void Gl_copy_tex_image2d(Int target, Int level, Int internalformat, Int x, Int y, Int width, Int height, Int border) {
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
void Gl_copy_tex_sub_image1d(Int target, Int level, Int xoffset, Int x, Int y, Int width) {
    glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}
void Gl_copy_tex_sub_image2d(Int target, Int level, Int xoffset, Int yoffset, Int x, Int y, Int width, Int height) {
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
void Gl_copy_tex_sub_image3d(Int target, Int level, Int xoffset, Int yoffset, Int zoffset, Int x, Int y, Int width, Int height) {
    glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void Gl_cull_face(Int mode) {
    glCullFace(mode);
}
void Gl_delete_lists(Int list, Int range) {
    glDeleteLists(list, range);
}
void Gl_depth_func(Int glfunc) {
    glDepthFunc(glfunc);
}
void Gl_depth_mask(Bool flag) {
    glDepthMask(flag);
}
void Gl_depth_range(Float znear, Float zfar) {
    glDepthRange(znear, zfar);
}
void Gl_disable(Int cap) {
    glDisable(cap);
}
void Gl_disable_client_state(Int array) {
    glDisableClientState(array);
}
void Gl_draw_arrays(Int mode, Int first, Int count) {
    glDrawArrays(mode, first, count);
}
void Gl_draw_buffer(Int mode) {
    glDrawBuffer(mode);
}
void Gl_edge_flag(Bool flag) {
    glEdgeFlag(flag);
}
void Gl_enable(Int cap) {
    glEnable(cap);
}
void Gl_enable_client_state(Int array) {
    glEnableClientState(array);
}
void Gl_end() {
    glEnd();
}
void Gl_end_list() {
    glEndList();
}
void Gl_eval_coord1d(Float u) {
    glEvalCoord1d(u);
}
void Gl_eval_coord1f(Float u) {
    glEvalCoord1f(u);
}
void Gl_eval_coord2d(Float u, Float v) {
    glEvalCoord2d(u, v);
}
void Gl_eval_coord2f(Float u, Float v) {
    glEvalCoord2f(u, v);
}
void Gl_eval_mesh1(Int mode, Int i1, Int i2) {
    glEvalMesh1(mode, i1, i2);
}
void Gl_eval_mesh2(Int mode, Int i1, Int i2, Int j1, Int j2) {
    glEvalMesh2(mode, i1, i2, j1, j2);
}
void Gl_eval_point1(Int i) {
    glEvalPoint1(i);
}
void Gl_eval_point2(Int i, Int j) {
    glEvalPoint2(i, j);
}
void Gl_finish() {
    glFinish();
}
void Gl_flush() {
    glFlush();
}
void Gl_fogf(Int pname, Float param) {
    glFogf(pname, param);
}
void Gl_fogi(Int pname, Int param) {
    glFogi(pname, param);
}
void Gl_front_face(Int mode) {
    glFrontFace(mode);
}
void Gl_frustum(Float left, Float right, Float bottom, Float top, Float znear, Float zfar) {
    glFrustum(left, right, bottom, top, znear, zfar);
}
GLuint Gl_gen_lists(Int range) {
    return glGenLists(range);
}
GLenum Gl_get_error() {
    return glGetError();
}
void Gl_hint(Int target, Int mode) {
    glHint(target, mode);
}
void Gl_histogram(Int target, Int width, Int internalformat, Bool sink) {
    glHistogram(target, width, internalformat, sink);
}
void Gl_index_mask(Int mask) {
    glIndexMask(mask);
}
void Gl_indexd(Float c) {
    glIndexd(c);
}
void Gl_indexf(Float c) {
    glIndexf(c);
}
void Gl_indexi(Int c) {
    glIndexi(c);
}
void Gl_indexs(Int c) {
    glIndexs(c);
}
void Gl_indexub(Byte c) {
    glIndexub(c);
}
void Gl_init_names() {
    glInitNames();
}
GLboolean Gl_is_enabled(Int cap) {
    return glIsEnabled(cap);
}
GLboolean Gl_is_list(Int list) {
    return glIsList(list);
}
GLboolean Gl_is_texture(Int texture) {
    return glIsTexture(texture);
}
void Gl_light_modelf(Int pname, Float param) {
    glLightModelf(pname, param);
}
void Gl_light_modeli(Int pname, Int param) {
    glLightModeli(pname, param);
}
void Gl_lightf(Int light, Int pname, Float param) {
    glLightf(light, pname, param);
}
void Gl_lighti(Int light, Int pname, Int param) {
    glLighti(light, pname, param);
}
void Gl_line_stipple(Int factor, Int pattern) {
    glLineStipple(factor, pattern);
}
void Gl_line_width(Float width) {
    glLineWidth(width);
}
void Gl_list_base(Int base) {
    glListBase(base);
}
void Gl_load_identity() {
    glLoadIdentity();
}
void Gl_load_name(Int name) {
    glLoadName(name);
}
void Gl_logic_op(Int opcode) {
    glLogicOp(opcode);
}
void Gl_map_grid1d(Int un, Float u1, Float u2) {
    glMapGrid1d(un, u1, u2);
}
void Gl_map_grid1f(Int un, Float u1, Float u2) {
    glMapGrid1f(un, u1, u2);
}
void Gl_map_grid2d(Int un, Float u1, Float u2, Int vn, Float v1, Float v2) {
    glMapGrid2d(un, u1, u2, vn, v1, v2);
}
void Gl_map_grid2f(Int un, Float u1, Float u2, Int vn, Float v1, Float v2) {
    glMapGrid2f(un, u1, u2, vn, v1, v2);
}
void Gl_materialf(Int face, Int pname, Float param) {
    glMaterialf(face, pname, param);
}
void Gl_materiali(Int face, Int pname, Int param) {
    glMateriali(face, pname, param);
}
void Gl_matrix_mode(Int mode) {
    glMatrixMode(mode);
}
void Gl_minmax(Int target, Int internalformat, Bool sink) {
    glMinmax(target, internalformat, sink);
}
void Gl_new_list(Int list, Int mode) {
    glNewList(list, mode);
}
void Gl_normal3b(Byte nx, Byte ny, Byte nz) {
    glNormal3b(nx, ny, nz);
}
void Gl_normal3d(Float nx, Float ny, Float nz) {
    glNormal3d(nx, ny, nz);
}
void Gl_normal3f(Float nx, Float ny, Float nz) {
    glNormal3f(nx, ny, nz);
}
void Gl_normal3i(Int nx, Int ny, Int nz) {
    glNormal3i(nx, ny, nz);
}
void Gl_normal3s(Int nx, Int ny, Int nz) {
    glNormal3s(nx, ny, nz);
}
void Gl_ortho(Float left, Float right, Float bottom, Float top, Float znear, Float zfar) {
    glOrtho(left, right, bottom, top, znear, zfar);
}
void Gl_pass_through(Float token) {
    glPassThrough(token);
}
void Gl_pixel_storef(Int pname, Float param) {
    glPixelStoref(pname, param);
}
void Gl_pixel_storei(Int pname, Int param) {
    glPixelStorei(pname, param);
}
void Gl_pixel_transferf(Int pname, Float param) {
    glPixelTransferf(pname, param);
}
void Gl_pixel_transferi(Int pname, Int param) {
    glPixelTransferi(pname, param);
}
void Gl_pixel_zoom(Float xfactor, Float yfactor) {
    glPixelZoom(xfactor, yfactor);
}
void Gl_point_size(Float size) {
    glPointSize(size);
}
void Gl_polygon_mode(Int face, Int mode) {
    glPolygonMode(face, mode);
}
void Gl_polygon_offset(Float factor, Float units) {
    glPolygonOffset(factor, units);
}
void Gl_pop_attrib() {
    glPopAttrib();
}
void Gl_pop_client_attrib() {
    glPopClientAttrib();
}
void Gl_pop_matrix() {
    glPopMatrix();
}
void Gl_pop_name() {
    glPopName();
}
void Gl_push_attrib(Int mask) {
    glPushAttrib(mask);
}
void Gl_push_client_attrib(Int mask) {
    glPushClientAttrib(mask);
}
void Gl_push_matrix() {
    glPushMatrix();
}
void Gl_push_name(Int name) {
    glPushName(name);
}
void Gl_raster_pos2d(Float x, Float y) {
    glRasterPos2d(x, y);
}
void Gl_raster_pos2f(Float x, Float y) {
    glRasterPos2f(x, y);
}
void Gl_raster_pos2i(Int x, Int y) {
    glRasterPos2i(x, y);
}
void Gl_raster_pos2s(Int x, Int y) {
    glRasterPos2s(x, y);
}
void Gl_raster_pos3d(Float x, Float y, Float z) {
    glRasterPos3d(x, y, z);
}
void Gl_raster_pos3f(Float x, Float y, Float z) {
    glRasterPos3f(x, y, z);
}
void Gl_raster_pos3i(Int x, Int y, Int z) {
    glRasterPos3i(x, y, z);
}
void Gl_raster_pos3s(Int x, Int y, Int z) {
    glRasterPos3s(x, y, z);
}
void Gl_raster_pos4d(Float x, Float y, Float z, Float w) {
    glRasterPos4d(x, y, z, w);
}
void Gl_raster_pos4f(Float x, Float y, Float z, Float w) {
    glRasterPos4f(x, y, z, w);
}
void Gl_raster_pos4i(Int x, Int y, Int z, Int w) {
    glRasterPos4i(x, y, z, w);
}
void Gl_raster_pos4s(Int x, Int y, Int z, Int w) {
    glRasterPos4s(x, y, z, w);
}
void Gl_read_buffer(Int mode) {
    glReadBuffer(mode);
}
void Gl_rectd(Float x1, Float y1, Float x2, Float y2) {
    glRectd(x1, y1, x2, y2);
}
void Gl_rectf(Float x1, Float y1, Float x2, Float y2) {
    glRectf(x1, y1, x2, y2);
}
void Gl_recti(Int x1, Int y1, Int x2, Int y2) {
    glRecti(x1, y1, x2, y2);
}
void Gl_rects(Int x1, Int y1, Int x2, Int y2) {
    glRects(x1, y1, x2, y2);
}
GLint Gl_render_mode(Int mode) {
    return glRenderMode(mode);
}
void Gl_reset_histogram(Int target) {
    glResetHistogram(target);
}
void Gl_reset_minmax(Int target) {
    glResetMinmax(target);
}
void Gl_rotated(Float angle, Float x, Float y, Float z) {
    glRotated(angle, x, y, z);
}
void Gl_rotatef(Float angle, Float x, Float y, Float z) {
    glRotatef(angle, x, y, z);
}
void Gl_scaled(Float x, Float y, Float z) {
    glScaled(x, y, z);
}
void Gl_scalef(Float x, Float y, Float z) {
    glScalef(x, y, z);
}
void Gl_scissor(Int x, Int y, Int width, Int height) {
    glScissor(x, y, width, height);
}
void Gl_shade_model(Int mode) {
    glShadeModel(mode);
}
void Gl_stencil_func(Int glfunc, Int ref, Int mask) {
    glStencilFunc(glfunc, ref, mask);
}
void Gl_stencil_mask(Int mask) {
    glStencilMask(mask);
}
void Gl_stencil_op(Int fail, Int zfail, Int zpass) {
    glStencilOp(fail, zfail, zpass);
}
void Gl_tex_coord1d(Float s) {
    glTexCoord1d(s);
}
void Gl_tex_coord1f(Float s) {
    glTexCoord1f(s);
}
void Gl_tex_coord1i(Int s) {
    glTexCoord1i(s);
}
void Gl_tex_coord1s(Int s) {
    glTexCoord1s(s);
}
void Gl_tex_coord2d(Float s, Float t) {
    glTexCoord2d(s, t);
}
void Gl_tex_coord2f(Float s, Float t) {
    glTexCoord2f(s, t);
}
void Gl_tex_coord2i(Int s, Int t) {
    glTexCoord2i(s, t);
}
void Gl_tex_coord2s(Int s, Int t) {
    glTexCoord2s(s, t);
}
void Gl_tex_coord3d(Float s, Float t, Float r) {
    glTexCoord3d(s, t, r);
}
void Gl_tex_coord3f(Float s, Float t, Float r) {
    glTexCoord3f(s, t, r);
}
void Gl_tex_coord3i(Int s, Int t, Int r) {
    glTexCoord3i(s, t, r);
}
void Gl_tex_coord3s(Int s, Int t, Int r) {
    glTexCoord3s(s, t, r);
}
void Gl_tex_coord4d(Float s, Float t, Float r, Float q) {
    glTexCoord4d(s, t, r, q);
}
void Gl_tex_coord4f(Float s, Float t, Float r, Float q) {
    glTexCoord4f(s, t, r, q);
}
void Gl_tex_coord4i(Int s, Int t, Int r, Int q) {
    glTexCoord4i(s, t, r, q);
}
void Gl_tex_coord4s(Int s, Int t, Int r, Int q) {
    glTexCoord4s(s, t, r, q);
}
void Gl_tex_envf(Int target, Int pname, Float param) {
    glTexEnvf(target, pname, param);
}
void Gl_tex_envi(Int target, Int pname, Int param) {
    glTexEnvi(target, pname, param);
}
void Gl_tex_gend(Int coord, Int pname, Float param) {
    glTexGend(coord, pname, param);
}
void Gl_tex_genf(Int coord, Int pname, Float param) {
    glTexGenf(coord, pname, param);
}
void Gl_tex_geni(Int coord, Int pname, Int param) {
    glTexGeni(coord, pname, param);
}
void Gl_tex_parameterf(Int target, Int pname, Float param) {
    glTexParameterf(target, pname, param);
}
void Gl_tex_parameteri(Int target, Int pname, Int param) {
    glTexParameteri(target, pname, param);
}
void Gl_translated(Float x, Float y, Float z) {
    glTranslated(x, y, z);
}
void Gl_translatef(Float x, Float y, Float z) {
    glTranslatef(x, y, z);
}
void Gl_vertex2d(Float x, Float y) {
    glVertex2d(x, y);
}
void Gl_vertex2f(Float x, Float y) {
    glVertex2f(x, y);
}
void Gl_vertex2i(Int x, Int y) {
    glVertex2i(x, y);
}
void Gl_vertex2s(Int x, Int y) {
    glVertex2s(x, y);
}
void Gl_vertex3d(Float x, Float y, Float z) {
    glVertex3d(x, y, z);
}
void Gl_vertex3f(Float x, Float y, Float z) {
    glVertex3f(x, y, z);
}
void Gl_vertex3i(Int x, Int y, Int z) {
    glVertex3i(x, y, z);
}
void Gl_vertex3s(Int x, Int y, Int z) {
    glVertex3s(x, y, z);
}
void Gl_vertex4d(Float x, Float y, Float z, Float w) {
    glVertex4d(x, y, z, w);
}
void Gl_vertex4f(Float x, Float y, Float z, Float w) {
    glVertex4f(x, y, z, w);
}
void Gl_vertex4i(Int x, Int y, Int z, Int w) {
    glVertex4i(x, y, z, w);
}
void Gl_vertex4s(Int x, Int y, Int z, Int w) {
    glVertex4s(x, y, z, w);
}
void Gl_viewport(Int x, Int y, Int width, Int height) {
    glViewport(x, y, width, height);
}
void Gl_sample_coverage(Float value, Bool invert) {
    glSampleCoverage(value, invert);
}
void Gl_active_texture(Int texture) {
    glActiveTexture(texture);
}
void Gl_client_active_texture(Int texture) {
    glClientActiveTexture(texture);
}
void Gl_multi_tex_coord1d(Int target, Float s) {
    glMultiTexCoord1d(target, s);
}
void Gl_multi_tex_coord1f(Int target, Float s) {
    glMultiTexCoord1f(target, s);
}
void Gl_multi_tex_coord1i(Int target, Int s) {
    glMultiTexCoord1i(target, s);
}
void Gl_multi_tex_coord1s(Int target, Int s) {
    glMultiTexCoord1s(target, s);
}
void Gl_multi_tex_coord2d(Int target, Float s, Float t) {
    glMultiTexCoord2d(target, s, t);
}
void Gl_multi_tex_coord2f(Int target, Float s, Float t) {
    glMultiTexCoord2f(target, s, t);
}
void Gl_multi_tex_coord2i(Int target, Int s, Int t) {
    glMultiTexCoord2i(target, s, t);
}
void Gl_multi_tex_coord2s(Int target, Int s, Int t) {
    glMultiTexCoord2s(target, s, t);
}
void Gl_multi_tex_coord3d(Int target, Float s, Float t, Float r) {
    glMultiTexCoord3d(target, s, t, r);
}
void Gl_multi_tex_coord3f(Int target, Float s, Float t, Float r) {
    glMultiTexCoord3f(target, s, t, r);
}
void Gl_multi_tex_coord3i(Int target, Int s, Int t, Int r) {
    glMultiTexCoord3i(target, s, t, r);
}
void Gl_multi_tex_coord3s(Int target, Int s, Int t, Int r) {
    glMultiTexCoord3s(target, s, t, r);
}
void Gl_multi_tex_coord4d(Int target, Float s, Float t, Float r, Float q) {
    glMultiTexCoord4d(target, s, t, r, q);
}
void Gl_multi_tex_coord4f(Int target, Float s, Float t, Float r, Float q) {
    glMultiTexCoord4f(target, s, t, r, q);
}
void Gl_multi_tex_coord4i(Int target, Int s, Int t, Int r, Int q) {
    glMultiTexCoord4i(target, s, t, r, q);
}
void Gl_multi_tex_coord4s(Int target, Int s, Int t, Int r, Int q) {
    glMultiTexCoord4s(target, s, t, r, q);
}
void Gl_fog_coordf(Float coord) {
    glFogCoordf(coord);
}
void Gl_fog_coordd(Float coord) {
    glFogCoordd(coord);
}
void Gl_secondary_color3b(Byte red, Byte green, Byte blue) {
    glSecondaryColor3b(red, green, blue);
}
void Gl_secondary_color3d(Float red, Float green, Float blue) {
    glSecondaryColor3d(red, green, blue);
}
void Gl_secondary_color3f(Float red, Float green, Float blue) {
    glSecondaryColor3f(red, green, blue);
}
void Gl_secondary_color3i(Int red, Int green, Int blue) {
    glSecondaryColor3i(red, green, blue);
}
void Gl_secondary_color3s(Int red, Int green, Int blue) {
    glSecondaryColor3s(red, green, blue);
}
void Gl_secondary_color3ub(Byte red, Byte green, Byte blue) {
    glSecondaryColor3ub(red, green, blue);
}
void Gl_secondary_color3ui(Int red, Int green, Int blue) {
    glSecondaryColor3ui(red, green, blue);
}
void Gl_secondary_color3us(Int red, Int green, Int blue) {
    glSecondaryColor3us(red, green, blue);
}
void Gl_point_parameterf(Int pname, Float param) {
    glPointParameterf(pname, param);
}
void Gl_point_parameteri(Int pname, Int param) {
    glPointParameteri(pname, param);
}
void Gl_blend_func_separate(Int srcrgb, Int dstrgb, Int srcalpha, Int dstalpha) {
    glBlendFuncSeparate(srcrgb, dstrgb, srcalpha, dstalpha);
}
void Gl_window_pos2d(Float x, Float y) {
    glWindowPos2d(x, y);
}
void Gl_window_pos2f(Float x, Float y) {
    glWindowPos2f(x, y);
}
void Gl_window_pos2i(Int x, Int y) {
    glWindowPos2i(x, y);
}
void Gl_window_pos2s(Int x, Int y) {
    glWindowPos2s(x, y);
}
void Gl_window_pos3d(Float x, Float y, Float z) {
    glWindowPos3d(x, y, z);
}
void Gl_window_pos3f(Float x, Float y, Float z) {
    glWindowPos3f(x, y, z);
}
void Gl_window_pos3i(Int x, Int y, Int z) {
    glWindowPos3i(x, y, z);
}
void Gl_window_pos3s(Int x, Int y, Int z) {
    glWindowPos3s(x, y, z);
}
GLboolean Gl_is_query(Int id) {
    return glIsQuery(id);
}
void Gl_begin_query(Int target, Int id) {
    glBeginQuery(target, id);
}
void Gl_end_query(Int target) {
    glEndQuery(target);
}
void Gl_bind_buffer(Int target, Int buffer) {
    glBindBuffer(target, buffer);
}
GLboolean Gl_is_buffer(Int buffer) {
    return glIsBuffer(buffer);
}
GLboolean Gl_unmap_buffer(Int target) {
    return glUnmapBuffer(target);
}
void Gl_vertex_attrib1d(Int index, Float x) {
    glVertexAttrib1d(index, x);
}
void Gl_vertex_attrib1f(Int index, Float x) {
    glVertexAttrib1f(index, x);
}
void Gl_vertex_attrib1s(Int index, Int x) {
    glVertexAttrib1s(index, x);
}
void Gl_vertex_attrib2d(Int index, Float x, Float y) {
    glVertexAttrib2d(index, x, y);
}
void Gl_vertex_attrib2f(Int index, Float x, Float y) {
    glVertexAttrib2f(index, x, y);
}
void Gl_vertex_attrib2s(Int index, Int x, Int y) {
    glVertexAttrib2s(index, x, y);
}
void Gl_vertex_attrib3d(Int index, Float x, Float y, Float z) {
    glVertexAttrib3d(index, x, y, z);
}
void Gl_vertex_attrib3f(Int index, Float x, Float y, Float z) {
    glVertexAttrib3f(index, x, y, z);
}
void Gl_vertex_attrib3s(Int index, Int x, Int y, Int z) {
    glVertexAttrib3s(index, x, y, z);
}
void Gl_vertex_attrib4nub(Int index, Byte x, Byte y, Byte z, Byte w) {
    glVertexAttrib4Nub(index, x, y, z, w);
}
void Gl_vertex_attrib4d(Int index, Float x, Float y, Float z, Float w) {
    glVertexAttrib4d(index, x, y, z, w);
}
void Gl_vertex_attrib4f(Int index, Float x, Float y, Float z, Float w) {
    glVertexAttrib4f(index, x, y, z, w);
}
void Gl_vertex_attrib4s(Int index, Int x, Int y, Int z, Int w) {
    glVertexAttrib4s(index, x, y, z, w);
}
void Gl_enable_vertex_attrib_array(Int index) {
    glEnableVertexAttribArray(index);
}
void Gl_disable_vertex_attrib_array(Int index) {
    glDisableVertexAttribArray(index);
}
void Gl_delete_shader(Int shader) {
    glDeleteShader(shader);
}
void Gl_detach_shader(Int program, Int shader) {
    glDetachShader(program, shader);
}
GLuint Gl_create_shader(Int type) {
    return glCreateShader(type);
}
void Gl_compile_shader(Int shader) {
    glCompileShader(shader);
}
GLuint Gl_create_program() {
    return glCreateProgram();
}
void Gl_attach_shader(Int program, Int shader) {
    glAttachShader(program, shader);
}
void Gl_link_program(Int program) {
    glLinkProgram(program);
}
void Gl_use_program(Int program) {
    glUseProgram(program);
}
void Gl_delete_program(Int program) {
    glDeleteProgram(program);
}
void Gl_validate_program(Int program) {
    glValidateProgram(program);
}
void Gl_uniform1f(Int location, Float v0) {
    glUniform1f(location, v0);
}
void Gl_uniform2f(Int location, Float v0, Float v1) {
    glUniform2f(location, v0, v1);
}
void Gl_uniform3f(Int location, Float v0, Float v1, Float v2) {
    glUniform3f(location, v0, v1, v2);
}
void Gl_uniform4f(Int location, Float v0, Float v1, Float v2, Float v3) {
    glUniform4f(location, v0, v1, v2, v3);
}
void Gl_uniform1i(Int location, Int v0) {
    glUniform1i(location, v0);
}
void Gl_uniform2i(Int location, Int v0, Int v1) {
    glUniform2i(location, v0, v1);
}
void Gl_uniform3i(Int location, Int v0, Int v1, Int v2) {
    glUniform3i(location, v0, v1, v2);
}
void Gl_uniform4i(Int location, Int v0, Int v1, Int v2, Int v3) {
    glUniform4i(location, v0, v1, v2, v3);
}
GLboolean Gl_is_shader(Int shader) {
    return glIsShader(shader);
}
GLboolean Gl_is_program(Int program) {
    return glIsProgram(program);
}
void Gl_stencil_func_separate(Int face, Int glfunc, Int ref, Int mask) {
    glStencilFuncSeparate(face, glfunc, ref, mask);
}
void Gl_stencil_op_separate(Int face, Int fail, Int zfail, Int zpass) {
    glStencilOpSeparate(face, fail, zfail, zpass);
}
void Gl_stencil_mask_separate(Int face, Int mask) {
    glStencilMaskSeparate(face, mask);
}
