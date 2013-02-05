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

#ifndef GL_MATRIX_H
#define GL_MATRIX_H

#include "Primitives.h"
typedef struct GlKit_Matrix* GlKit_Matrix;
struct GlKit_Matrix {
    Float m00
    Float m01
    Float m02
    Float m03

    Float m10
    Float m11
    Float m12
    Float m13

    Float m20
    Float m21
    Float m22
    Float m23

    Float m30
    Float m31
    Float m32
    Float m33
};

void GlKit_Matrix_uniform(GlKit_Matrix self, Int location) {
    GLfloat data[] = {
       self->m00, self->m01, self->m02, self->m03,
       self->m10, self->m11, self->m12, self->m13,
       self->m20, self->m21, self->m22, self->m23,
       self->m30, self->m31, self->m32, self->m33,
    };
    glUniformMatrix4fv(location, 1, GL_FALSE, data);
}

#endif
