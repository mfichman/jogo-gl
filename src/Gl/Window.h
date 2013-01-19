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
#ifdef WINDOWS
#include <windows.h>
#endif

typedef struct Math_Vec2i* Math_Vec2i;
struct Math_Vec2i {
    Int x;
    Int y; 
};

typedef struct Gl_VideoMode* Gl_VideoMode;
struct Gl_VideoMode {
    Int width;
    Int height;
    Int color_bits;
    Int depth_bits;
    Int stencil_bits;
};

typedef struct Gl_Window* Gl_Window;
struct Gl_Window {
    Ptr _vtable;
    U64 _refcount;
#if defined(WINDOWS)
    HWND handle;
    HDC device;
    HGLRC context;
#elif defined(LINUX)
#error Unsupported
#elif defined(DARWIN)
#error Unsupported
#else
#error Unsupported
#endif
};

Gl_Window Gl_Window__init(Gl_VideoMode mode);
void Gl_Window__destroy(Gl_Window self);
void Gl_Window_display(Gl_Window self);
void Gl_Window_find_pixel_format(Gl_Window self, Gl_VideoMode mode);
void Gl_Window_position__s(Gl_Window self, Math_Vec2i position);
void Gl_Window_size__s(Gl_Window self, Math_Vec2i size);
void Gl_Window_visible__s(Gl_Window self, Bool visible);
void Gl_Window_current__s(Gl_Window self, Bool current);
void Gl_Window_position__g(Gl_Window self, Math_Vec2i ret);
void Gl_Window_size__g(Gl_Window self, Math_Vec2i ret);
Bool Gl_Window_visible__g(Gl_Window self);
Bool Gl_Window_current__g(Gl_Window self);
extern void Gl_Window__vtable();
void Gl_poll();

#ifdef WINDOWS
LRESULT CALLBACK Gl_Window__wndproc(HWND, UINT, WPARAM, LPARAM);
#endif

#endif
