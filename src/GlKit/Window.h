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

#ifndef GL_WINDOW_H
#define GL_WINDOW_H

#include "Primitives.h"
#include "Math/Vec2i.h"

typedef Int GlKit_WindowMode;

typedef struct GlKit_VideoMode* GlKit_VideoMode;
struct GlKit_VideoMode {
    Int width;
    Int height;
    Int color_bits;
    Int depth_bits;
    GlKit_WindowMode window_mode;
};

typedef struct GlKit_Window* GlKit_Window;
struct GlKit_Window {
    VoidPtr _vtable;
    U64 _refcount;
    Int handle; 
};

GlKit_Window GlKit_Window__init(GlKit_VideoMode mode);
void GlKit_Window__destroy(GlKit_Window self);
void GlKit_Window_display(GlKit_Window self);
void GlKit_Window_position__s(GlKit_Window self, Math_Vec2i position);
void GlKit_Window_size__s(GlKit_Window self, Math_Vec2i size);
void GlKit_Window_visible__s(GlKit_Window self, Bool visible);
void GlKit_Window_current__s(GlKit_Window self, Bool current);
void GlKit_Window_position__g(GlKit_Window self, Math_Vec2i ret);
void GlKit_Window_size__g(GlKit_Window self, Math_Vec2i ret);
Bool GlKit_Window_visible__g(GlKit_Window self);
Bool GlKit_Window_current__g(GlKit_Window self);
void GlKit_Window_init_poll(GlKit_Window self);
void GlKit_Window_reshape(int width, int height);
void GlKit_Window_idle();
extern void GlKit_Window__vtable();

void GlKit_poll();

extern GlKit_WindowMode GlKit_WindowMode_FULLSCREEN;
extern GlKit_WindowMode GlKit_WindowMode_WINDOWED;

#endif
