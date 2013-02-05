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

#include "GlKit/Shader.h"
#include "GlKit/Gl.h"
#include "String.h"

#include <stdio.h>

void GlKit_Shader_check_status(GlKit_Shader self) {
    // Check the status of the shader and get the error log.
    GLint success = 0;
    GLint program_len = 0;
    GLint vshader_len = 0;
    GLint fshader_len = 0;
    Char* buf = 0;
    glGetProgramiv(self->id, GL_LINK_STATUS, &success);
    if (success) {
        self->status = GlKit_ShaderStatus_LINKED;
        return;
    }
    self->status = GlKit_ShaderStatus_ERROR;
        
    glGetShaderiv(self->vertex_shader_id, GL_INFO_LOG_LENGTH, &vshader_len);
    glGetShaderiv(self->fragment_shader_id, GL_INFO_LOG_LENGTH, &fshader_len);
    glGetShaderiv(self->id, GL_INFO_LOG_LENGTH, &program_len);
    self->log = String_alloc(program_len + vshader_len + fshader_len);  
    self->log->length = program_len + vshader_len + fshader_len;
    buf = self->log->data;

    if (vshader_len) {
       glGetShaderInfoLog(self->vertex_shader_id, vshader_len, &vshader_len, buf);
       buf += vshader_len;
    }
    if (fshader_len) {
       glGetShaderInfoLog(self->fragment_shader_id, fshader_len, &fshader_len, buf);
       buf += fshader_len;
    }
    if (program_len) {
       glGetProgramInfoLog(self->id, program_len, &program_len, buf);
       buf += program_len;
    }
}
