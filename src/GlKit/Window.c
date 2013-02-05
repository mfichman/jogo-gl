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
#include "Boot/Module.h"
#include "Os/Module.h"
#include <stdlib.h>

#if defined(WINDOWS)
#include <windows.h>
#include <glut/glut.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#elif defined(DARWIN)
#include <GlKit/glfw.h>
#elif defined(LINUX)
#include <glut/glut.h>
#endif

#include <stdio.h>


GlKit_Window GlKit_Window__init(GlKit_VideoMode mode) {
    // Initialize and open the Window using the given video mode.
    Int width = mode->width;
    Int height = mode->height;
    Int alpha = mode->color_bits == 32 ? 8 : 0;
    Int depth = mode->depth_bits;
    Int type = 0;
    GlKit_Window ret = Boot_calloc(sizeof(struct GlKit_Window));
    ret->_vtable = GlKit_Window__vtable;
    ret->_refcount = 1;

    if (mode->window_mode == GlKit_WindowMode_FULLSCREEN) {
        type = GLFW_FULLSCREEN;
    } else if (mode->window_mode == GlKit_WindowMode_WINDOWED) {
        type = GLFW_WINDOW;
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
    if (!glfwOpenWindow(width, height, 8, 8, 8, alpha, depth, 0, type)) {
        fprintf(stderr, "Could not open Window\n");
        abort();
    }
    return ret; 
}

void GlKit_Window__destroy(GlKit_Window self) {
    glfwCloseWindow();
    Boot_free(self);
}

void GlKit_Window_display(GlKit_Window self) {
    glfwSwapBuffers();
}

void GlKit_Window_position__s(GlKit_Window self, Math_Vec2i pos) {
    abort(); 
}

void GlKit_Window_size__s(GlKit_Window self, Math_Vec2i size) {
    abort();
}

void GlKit_Window_visible__s(GlKit_Window self, Bool visible) {
//    Int save = glutGetWindow(); 
//    glutSetWindow(self->handle);
//    if (visible) {
//        glutShowWindow();
//    } else {
//        glutHideWindow();
//    } 
//    glutSetWindow(save);
}

void GlKit_Window_current__s(GlKit_Window self, Bool visible) {
//    glutSetWindow(self->handle);
}

void GlKit_Window_position__g(GlKit_Window self, Math_Vec2i ret) {
//    Int save = glutGetWindow(); 
//    glutSetWindow(self->handle);
//    ret->x = glutGet(GLUT_WINDOW_X);
//    ret->y = glutGet(GLUT_WINDOW_Y);
//    glutSetWindow(save);
}

void GlKit_Window_size__g(GlKit_Window self, Math_Vec2i ret) {
//    Int save = glutGetWindow(); 
//    glutSetWindow(self->handle);
//    ret->x = glutGet(GLUT_WINDOW_WIDTH);
//    ret->y = glutGet(GLUT_WINDOW_HEIGHT);
//    glutSetWindow(save);
}

Bool GlKit_Window_visible__g(GlKit_Window self) {
    abort();
}

Bool GlKit_Window_current__g(GlKit_Window self) {
//    return glutGetWindow() == self->handle;
    return 0;
}

void GlKit_poll() {
    // Read all queued messages, but do not block on any messages, as this will
    // block the I/O manager.  This function should be called from a coroutine.
    glfwPollEvents();
}

