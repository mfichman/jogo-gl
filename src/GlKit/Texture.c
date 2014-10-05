/*
 * Copyright (c) 2014 Matt Fichman
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

#include "GlKit/Texture.h"
#include "Gl/GlDefs.h"
#include "Boot/Boot.h"
#include "Os/Os.h"

GlKit_Texture GlKit_Texture__init() {
    // Initialize the OpenGL texture
    GlKit_Texture ret = Boot_calloc(sizeof(struct GlKit_Texture));
    GLuint id = 0;
    ret->_vtable = GlKit_Texture__vtable;
    ret->_refcount = 1;
    glGenTextures(1, &id);
    ret->id = id;
    return ret;
}

void GlKit_Texture__destroy(GlKit_Texture self) {
    GLuint id = self->id;
    glDeleteTextures(1, &id);
    Boot_free(self);
}
