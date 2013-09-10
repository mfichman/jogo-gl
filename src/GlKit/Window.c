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

#include "Window.h"
#include "Boot/Boot.h"
#include "Os/Os.h"
#include "Gl/GlDefs.h"
#include "GlKit/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#ifdef WINDOWS
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#endif


GlKit_Window GlKit_Window__init(GlKit_VideoMode mode) {
    // Initialize and open the Window using the given video mode.
    Int width = mode->width;
    Int height = mode->height;
    //Int alpha = mode->color_bits == 32 ? 8 : 0;
    //Int depth = mode->depth_bits;
#ifndef DARWIN
    GLenum err = 0;
#endif
    GLFWmonitor* monitor = 0;

    GlKit_Window ret = Boot_calloc(sizeof(struct GlKit_Window));
    ret->_vtable = GlKit_Window__vtable;
    ret->_refcount = 1;

    if (mode->window_mode == GlKit_WindowMode_FULLSCREEN) {
        monitor = glfwGetPrimaryMonitor();
    } else if (mode->window_mode == GlKit_WindowMode_WINDOWED) {
        //
    } else {
        Os_cpanic("Unsupported window mode");
    }
    if (mode->color_bits != 24 && mode->color_bits != 32) {
        Os_cpanic("Unsupported bit depth");
    }

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        abort();
    }
    ret->handle = glfwCreateWindow(width, height, "", monitor, 0);
    if (!ret->handle) {
        fprintf(stderr, "Could not open Window\n");
        abort();
    }
    GlKit_Window_current__s(ret, 1);

#ifndef DARWIN
    glewExperimental = 1; 
    err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "%s", glewGetErrorString(err));
        abort();
    }
#endif

    return ret; 
}

void GlKit_Window__destroy(GlKit_Window self) {
    glfwDestroyWindow(self->handle);
    Boot_free(self);
}

void GlKit_Window_display(GlKit_Window self) {
    glfwSwapBuffers(self->handle);
}

void GlKit_Window_position__s(GlKit_Window self, Math_Vec2i pos) {
    glfwSetWindowPos(self->handle, pos->x, pos->y);
}

void GlKit_Window_size__s(GlKit_Window self, Math_Vec2i size) {
    glfwSetWindowSize(self->handle, size->x, size->y);
}

void GlKit_Window_visible__s(GlKit_Window self, Bool visible) {
    if (visible) {
        glfwShowWindow(self->handle);
    } else {
        glfwHideWindow(self->handle);
    } 
}

void GlKit_Window_current__s(GlKit_Window self, Bool current) {
    if (current) {
        glfwMakeContextCurrent(self->handle);
    } else {
        glfwMakeContextCurrent(0);
    } 
}

void GlKit_Window_position__g(GlKit_Window self, Math_Vec2i ret) {
    int x = ret->x;
    int y = ret->y;
    glfwGetWindowPos(self->handle, &x, &y);
}

void GlKit_Window_size__g(GlKit_Window self, Math_Vec2i ret) {
    int x = ret->x;
    int y = ret->y;
    glfwGetWindowSize(self->handle, &x, &y);
}

Bool GlKit_Window_visible__g(GlKit_Window self) {
    abort();
    return 1;
}

Bool GlKit_Window_current__g(GlKit_Window self) {
    return glfwGetCurrentContext() == self->handle;
}

Bool GlKit_Window_closed__g(GlKit_Window self) {
    return glfwWindowShouldClose(self->handle);
}

void GlKit_poll() {
    // Read all queued messages, but do not block on any messages, as this will
    // block the I/O manager.  This function should be called from a coroutine.
    glfwPollEvents();
}

