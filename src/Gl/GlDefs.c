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

#include "Primitives.h"
#include "String.h"
#include "GlKit/Matrix.h"
#ifdef DARWIN
#include <OpenGL/GL.h>
#else
#error Not implemented
#endif

void Gl_shader_source(Int id, String data) {
    GLchar const* strings = (GLchar const*)data->data;
    GLint lengths = data->length;
    glShaderSource(id, 1, &strings, &lengths);
}


Int Gl_get_uniform_location(Int id, String name) {
    return glGetUniformLocation(id, (GLchar*)name->data);
}

void Gl_bind_attrib_location(Int id, Int index, String name) {
    glBindAttribLocation(id, index, (GLchar*)name->data);
}

void Gl_uniform_matrix(Int index, GlKit_Matrix matrix) {
    GLsizei const count = 1;
    GLboolean const transpose = 1;
    GLfloat data[16]; 
    GLdouble* in = (GLdouble*)matrix;
    for (Int i = 0; i < 16; ++i) {
        data[i] = in[i];
    } 
    glUniformMatrix4fv(index, count, transpose, data);
}
