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

typedef Int GlKit_BufferState;
typedef Int GlKit_BufferTarget;

typedef struct GlKit_Buffer* GlKit_Buffer;
struct GlKit_Buffer {
    VoidPtr _vtable;
    U64 _refcount;
    GlKit_BufferState state;
    GlKit_BufferTarget target;
    Int id;  
    Int size;
    Int capacity;
    Char* data; 
};

GlKit_Buffer GlKit_Buffer__init();
void GlKit_Buffer__destroy(GlKit_Buffer self);
void GlKit_Buffer_val4f(GlKit_Buffer self, Float x, Float y, Float z, Float w);
void GlKit_Buffer_val3f(GlKit_Buffer self, Float x, Float y, Float z);
void GlKit_Buffer_val2f(GlKit_Buffer self, Float x, Float y);
void GlKit_Buffer_val1f(GlKit_Buffer self, Float x);
void GlKit_Buffer_state__s(GlKit_Buffer self, GlKit_BufferState state);
void GlKit_Buffer_clear(GlKit_Buffer self);
extern Int GlKit_Buffer_DEFAULT_SIZE;
extern void GlKit_Buffer__vtable();

extern GlKit_BufferTarget GlKit_BufferTarget_VERTEX;
extern GlKit_BufferTarget GlKit_BufferTarget_ELEMENT;
extern GlKit_BufferState GlKit_BufferState_SYNCED;
extern GlKit_BufferState GlKit_BufferState_DIRTY;

