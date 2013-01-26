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
#include <stdlib.h>

#if defined(WINDOWS)
#include <windows.h>
#include <glut/glut.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#elif defined(DARWIN)
#include <glut/glut.h>
#elif defined(LINUX)
#include <glut/glut.h>
#endif


Gl_Window Gl_Window__init(Gl_VideoMode mode) {
    Gl_Window ret = Boot_calloc(sizeof(struct Gl_Window));
    ret->_vtable = Gl_Window__vtable;
    ret->_refcount = 1;

    int argcp = 1;
    char* argv[] = {"test"};
    glutInit(&argcp, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGBA);
    glutInitWindowSize(mode->width, mode->height);
    glutInitWindowPosition(0, 0);
    ret->handle = glutCreateWindow("Jogo");

    glutReshapeFunc(Gl_Window_reshape);
    glutDisplayFunc(Gl_Window_idle);
    glutIdleFunc(Gl_Window_idle);

    return ret; 
}

void Gl_Window__destroy(Gl_Window self) {
    glutDestroyWindow(self->handle);
    Boot_free(self);
}

void Gl_Window_display(Gl_Window self) {
    glutSwapBuffers();
}

void Gl_Window_position__s(Gl_Window self, Math_Vec2i pos) {
    abort(); 
}

void Gl_Window_size__s(Gl_Window self, Math_Vec2i size) {
    abort();
}

void Gl_Window_visible__s(Gl_Window self, Bool visible) {
    Int save = glutGetWindow(); 
    glutSetWindow(self->handle);
    if (visible) {
        glutShowWindow();
    } else {
        glutHideWindow();
    } 
    glutSetWindow(save);
}

void Gl_Window_current__s(Gl_Window self, Bool visible) {
    glutSetWindow(self->handle);
}

void Gl_Window_position__g(Gl_Window self, Math_Vec2i ret) {
    Int save = glutGetWindow(); 
    glutSetWindow(self->handle);
    ret->x = glutGet(GLUT_WINDOW_X);
    ret->y = glutGet(GLUT_WINDOW_Y);
    glutSetWindow(save);
}

void Gl_Window_size__g(Gl_Window self, Math_Vec2i ret) {
    Int save = glutGetWindow(); 
    glutSetWindow(self->handle);
    ret->x = glutGet(GLUT_WINDOW_WIDTH);
    ret->y = glutGet(GLUT_WINDOW_HEIGHT);
    glutSetWindow(save);
}

Bool Gl_Window_visible__g(Gl_Window self) {
    abort();
}

Bool Gl_Window_current__g(Gl_Window self) {
    return glutGetWindow() == self->handle;
}

void Gl_Window_reshape(int width, int height) {
}

void Gl_Window_idle() {
}

void Gl_poll() {
    // Read all queued messages, but do not block on any messages, as this will
    // block the I/O manager.  This function should be called from a coroutine.
#ifdef DARWIN
    glutCheckLoop();
#else
    glutMainLoopEvent();     
#endif
}

