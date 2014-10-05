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

#include "GlKit/Buffer.h"
#include "Gl/GlDefs.h"
#include "Boot/Boot.h"
#include "Os/Os.h"

GlKit_Buffer GlKit_Buffer__init(GlKit_BufferTarget target) {
    // Initialize the OpenGL buffer
    GlKit_Buffer ret = Boot_calloc(sizeof(struct GlKit_Buffer));
    GLuint id = 0;
    ret->_vtable = GlKit_Buffer__vtable;
    ret->_refcount = 1;
    glGenBuffers(1, &id);
    ret->id = id;
    ret->data = Boot_calloc(GlKit_Buffer_DEFAULT_SIZE);
    ret->capacity = GlKit_Buffer_DEFAULT_SIZE;
    ret->target = target;

    return ret;
}

void GlKit_Buffer__destroy(GlKit_Buffer self) {
    GLuint id = self->id;
    glDeleteBuffers(1, &id);
    Boot_free(self->data);
    Boot_free(self);
}

void GlKit_Buffer_val4f(GlKit_Buffer self, Float x, Float y, Float z, Float w) {
    GlKit_Buffer_val1f(self, x);
    GlKit_Buffer_val1f(self, y);
    GlKit_Buffer_val1f(self, z);
    GlKit_Buffer_val1f(self, w);
}

void GlKit_Buffer_val3f(GlKit_Buffer self, Float x, Float y, Float z) {
    GlKit_Buffer_val1f(self, x);
    GlKit_Buffer_val1f(self, y);
    GlKit_Buffer_val1f(self, z);
}

void GlKit_Buffer_val2f(GlKit_Buffer self, Float x, Float y) {
    GlKit_Buffer_val1f(self, x);
    GlKit_Buffer_val1f(self, y);
}

void GlKit_Buffer_val1f(GlKit_Buffer self, Float x) {
    // Add a new data to the buffer, and resize if necessary to fit
    GLfloat fx = x;
    if ((self->capacity - self->size) < sizeof(fx)) {
        Int capacity = self->capacity * 2;  
        Byte* data = Boot_malloc(capacity);
        Boot_memcpy(data, self->data, self->size);
        Boot_free(self->data);
        self->data = data;
        self->capacity = capacity;
    }
    Boot_memcpy(self->data+self->size, &fx, sizeof(fx));
    self->size += sizeof(fx);
    self->state = GlKit_BufferState_DIRTY;
}

void GlKit_Buffer_sync(GlKit_Buffer self) {
    // Sets the state of the buffer, syncronizing with the hardware if the
    // state is set to 'synced' and the buffer is currently dirty.
    if (self->state == GlKit_BufferState_DIRTY) {
        GLenum target = 0;
        if (GlKit_BufferTarget_VERTEX == self->target) {
            target = GL_ARRAY_BUFFER;
        } else if (GlKit_BufferTarget_ELEMENT == self->target) {
            target = GL_ELEMENT_ARRAY_BUFFER;
        } else {
            Os_cpanic("Invalid BufferState");
        }
        glBindBuffer(target, self->id);
        glBufferData(target, self->size, self->data, GL_STATIC_DRAW);        
        glBindBuffer(target, 0);
        self->state = GlKit_BufferState_SYNCED;
    }
}

void GlKit_Buffer_clear(GlKit_Buffer self) {
    self->size = 0;
    self->state = GlKit_BufferState_DIRTY;
}
