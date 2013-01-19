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
#include <windows.h>

Char const* class_name = "JogoWindow";

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

#ifdef WINDOWS
Gl_Window Gl_Window__init(Gl_VideoMode mode) {
    // Initialize the Windows
    WNDCLASS class;
    DWORD style = WS_VISIBLE|WS_SYSMENU;  // FixMe: Make invisible to start
    RECT rect = { 0, 0, mode->width, mode->height };
    HANDLE module = GetModuleHandle(0);
    DWORD x = 0;
    DWORD y = 0;
    DWORD width = mode->width;
    DWORD height = mode->height;
    HDC dc = GetDC(0);
    Gl_Window ret = Boot_calloc(sizeof(struct Gl_Window));
    ret->_vtable = Gl_Window__vtable;
    ret->_refcount = 1;

    x = (GetDeviceCaps(dc, HORZRES) - width)/2;
    y = (GetDeviceCaps(dc, VERTRES) - height)/2;
    ReleaseDC(0, dc);

    // Register window class
    class.style = 0;
    class.lpfnWndProc = Gl_Window__wndproc;
    class.cbClsExtra = 0;
    class.cbWndExtra = 0;
    class.hInstance = GetModuleHandle(0);
    class.hIcon = 0;
    class.hCursor = 0;
    class.hbrBackground = 0;
    class.lpszMenuName = 0;
    class.lpszClassName = class_name;
    RegisterClass(&class);

    // Create the Window
    AdjustWindowRect(&rect, style, 0);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
    ret->handle = CreateWindow(class_name, "", style, x, y, width, height, 0, 0, module, ret);
    ret->device = GetDC(ret->handle);
    if (!ret->device) {
        printf("GetDC: ");
        Boot_abort();
    }

    // Select pixel format
    Gl_Window_find_pixel_format(ret, mode);

    ret->context = wglCreateContext(ret->device);
    if (!ret->context) {
        printf("wglCreateContext: ");
        Boot_abort();
    }

    if (!wglMakeCurrent(ret->device, ret->context)) {
        printf("wglMakeCurrent: ");
        Boot_abort();
    }

    return ret; 
}

void Gl_Window__destroy(Gl_Window self) {
    DestroyWindow(self->handle);
    Boot_free(self);
}

void Gl_Window_display(Gl_Window self) {
    if (!SwapBuffers(self->device)) {
        printf("SwapBuffers: ");
        Boot_abort();
    }
}

void Gl_Window_find_pixel_format(Gl_Window self, Gl_VideoMode mode) {
    PIXELFORMATDESCRIPTOR pfd;
    int index = 0;
    memset(&pfd, 0, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.iLayerType = PFD_MAIN_PLANE;
    pfd.cColorBits = mode->color_bits;
    pfd.cDepthBits = mode->depth_bits;
    pfd.cStencilBits = mode->stencil_bits;
    pfd.cAlphaBits = (mode->color_bits == 32) ? 8 : 0;

    index = ChoosePixelFormat(self->device, &pfd);
    if (index == 0) {
        Boot_abort();
    }
    if (!SetPixelFormat(self->device, index, &pfd)) {
        Boot_abort();
    }
    printf("Found pixel format\n");
}

LRESULT CALLBACK Gl_Window__wndproc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (WM_CREATE == msg) {
        LONG_PTR window = (LONG_PTR)((CREATESTRUCT*)lparam)->lpCreateParams;
        SetWindowLongPtr(handle, GWLP_USERDATA, window);
    }

    // Process window event
    return DefWindowProc(handle, msg, wparam, lparam);
}

void Gl_Window_position__s(Gl_Window self, Math_Vec2i pos) {
    SetWindowPos(self->handle, 0, pos->x, pos->y, 0, 0, SWP_NOSIZE|SWP_NOZORDER);
}

void Gl_Window_size__s(Gl_Window self, Math_Vec2i size) {
    RECT rect = {0, 0, size->x, size->y};
    DWORD style = GetWindowLong(self->handle, GWL_STYLE);
    Int width = 0;
    Int height = 0;
    AdjustWindowRect(&rect, style, 0);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top; 
    SetWindowPos(self->handle, 0, 0, 0, width, height, SWP_NOMOVE|SWP_NOZORDER);
}

void Gl_Window_visible__s(Gl_Window self, Bool visible) {
    ShowWindow(self->handle, visible ? SW_SHOW : SW_HIDE);
}

void Gl_Window_current__s(Gl_Window self, Bool visible) {
    if (visible) {
        if (!wglMakeCurrent(self->device, self->context)) {
            Boot_abort();
        } 
    } else if (Gl_Window_current__g(self)) {
        if (!wglMakeCurrent(self->device, self->context)) {
            Boot_abort();
        }
    }
}

void Gl_Window_position__g(Gl_Window self, Math_Vec2i ret) {
    RECT rect;
    GetWindowRect(self->handle, &rect);
    ret->x = rect.left;
    ret->y = rect.top;
}

void Gl_Window_size__g(Gl_Window self, Math_Vec2i ret) {
    RECT rect;
    GetWindowRect(self->handle, &rect);
    ret->x = rect.right - rect.left;
    ret->y = rect.bottom - rect.top;
}

Bool Gl_Window_visible__g(Gl_Window self) {
    return IsWindowVisible(self->handle);
}

Bool Gl_Window_current__g(Gl_Window self) {
    return self->context == wglGetCurrentContext();
}

void Gl_poll() {
    // Read all queued messages, but do not block on any messages, as this will
    // block the I/O manager.  This function should be called from a coroutine.
    MSG msg;
    while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#endif
