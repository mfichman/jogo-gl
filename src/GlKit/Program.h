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

typedef Int GlKit_ProgramStatus;

typedef struct GlKit_Program* GlKit_Program;
struct GlKit_Program {
    Int _refcount;
    VoidPtr _vtable;
    Int id;
    Int fragment_shader_id;
    Int vertex_shader_id;
    GlKit_ProgramStatus status;
    String log;
};

Int GlKit_Program_get_uniform_location(GlKit_Program self, String name);
void GlKit_Program_bind_attrib_location(GlKit_Program self, Int index, String name);
void GlKit_Program_check_status(GlKit_Program self);
extern GlKit_ProgramStatus GlKit_ProgramStatus_ERROR;
extern GlKit_ProgramStatus GlKit_ProgramStatus_LINKED;
extern Int GlKit_Program_POSITION_ATTRIB;
extern Int GlKit_Program_NORMAL_ATTRIB;
extern Int GlKit_Program_TEXCOORD_ATTRIB;

