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

typedef Int GlKit_ShaderStatus;

typedef struct GlKit_Shader* GlKit_Shader;
struct GlKit_Shader {
    Int _refcount;
    VoidPtr _vtable;
    Int id;
    Int fragment_shader_id;
    Int vertex_shader_id;
    GlKit_ShaderStatus status;
    String log;
};

Int GlKit_Shader_get_uniform_location(GlKit_Shader self, String name);
void GlKit_Shader_bind_attrib_location(GlKit_Shader self, Int index, String name);
void GlKit_Shader_check_status(GlKit_Shader self);
extern GlKit_ShaderStatus GlKit_ShaderStatus_ERROR;
extern GlKit_ShaderStatus GlKit_ShaderStatus_LINKED;
extern Int GlKit_Shader_POSITION_ATTRIB;
extern Int GlKit_Shader_NORMAL_ATTRIB;
extern Int GlKit_Shader_TEXCOORD_ATTRIB;

