#!/bin/env python

import re
# This scripts takes an OpenGL spec header file (gl3.h) and generates the
# native bindings for it (Gl.jg and Gl.c)

out = open('Gl.jg', 'w')
c = open('Gl.c', 'w')

c.write('#include "OpenGL/gl.h"\n')
c.write('#include "OpenGL/glu.h"\n')
c.write('#include "Primitives.h"\n')

def jogo_type_name(name):
    # Converts an OpenGL type name to the equivalent Jogo type name
    if name == 'GLuint': return 'Int'
    elif name == 'GLint': return 'Int'
    elif name == 'GLfloat': return 'Float'
    elif name == 'GLdouble': return 'Float'
    elif name == 'GLboolean': return 'Bool'
    elif name == 'GLenum': return 'Int'
    elif name == 'GLsizei': return 'Int'
    elif name == 'GLbyte': return 'Byte'
    elif name == 'GLubyte': return 'Byte'
    elif name == 'GLshort': return 'Int'
    elif name == 'GLushort': return 'Int'
    elif name == 'GLbitfield': return 'Int'
    elif name == 'GLclampf': return 'Float'
    elif name == 'GLclampd': return 'Float'
    return name

def jogo_arg_name(name):
    # Sanitizes arg names by removing Jogo keywords
    if name == 'func': return 'glfunc'
    return name.lower()

def jogo_func_name(name):
    # Converts an OpenGL function name to the equivalent Jogo name
    name = name[2:] # Strip the 'gl'
    out = ''
    for i,char in enumerate(name):
        if name[i].isupper():
            if i > 0 and name[i-1].islower():
                out += '_'
        out += name[i].lower()
    return out

def parse_define(token):
    # Parses a #define (GL_ENUM) (VAL)
    if len(token) != 3: return
    if token[0] != '#define': return
    if token[1][:2] != 'GL': return
    key = token[1][3:].upper()
    if not key[0].isalpha():
        key = 'X%s' % key
        
    value = token[2]
    if 'ARB' in key: return
    try: int(value, 10)
    except ValueError: pass
    try: int(value, 16)
    except ValueError: return
    out.write('%s = %s\n' % (key, value))

def print_jogo_func(name, ret, args):
    # Emits the Jogo native function header
    fn = jogo_func_name(name)
    ret = jogo_type_name(ret)

    out.write('%s(' % fn)

    for i in range(len(args)/2):
        tn = jogo_type_name(args[i*2])
        argn = jogo_arg_name(args[i*2+1])
        out.write('%s %s' % (argn, tn))
        if i+1 != len(args)/2:
            out.write(', ')

    out.write(') native')
    if ret != 'void':
        out.write(' %s' % ret)
    out.write('\n')

def print_c_func(name, ret, args):
    # Emits the C impl of the Jogo binding function
    fn = jogo_func_name(name)
    c.write('%s Gl_%s(' % (ret, fn))
    for i in range(len(args)/2):
        tn = jogo_type_name(args[i*2])
        argn = jogo_arg_name(args[i*2+1])
        c.write('%s %s' % (tn, argn))
        if i+1 != len(args)/2:
            c.write(', ')

    c.write(') {\n')
    c.write('    ')
    if ret != 'void':
        c.write('return ');
    c.write('%s(' % name)
    for i in range(len(args)/2):
        argn = jogo_arg_name(args[i*2+1])
        c.write('%s' % (argn))
        if i+1 != len(args)/2:
            c.write(', ')
    c.write(');\n}\n')
    

def parse_func(token):
    # Parses a function and then emits the native code/Jogo header
    print token

    filt = []
    for i,tok in enumerate(token):
        if tok == 'const': continue
        if tok == 'APIENTRY': continue
        if tok == 'GLAPI': continue
        if tok == 'struct': continue
        if tok == 'extern': continue
        if 'GLsync' in tok: return
        if 'GLintptr' in tok: return
        if 'GLsizeiptr' in tok: return
        if 'GLuint64' in tok: return
        if 'ARB' in tok: return
        if '*' in tok: return
        if '{' in tok: return
        # FIXME: Handle the buffer case 
        tok = tok.replace(',', '')
        tok = tok.replace('(', '')
        tok = tok.replace(')', '')
        tok = tok.replace(';', '')
        filt.append(tok) 

    args = filt[2:]
    if len(args) % 2 != 0 and args[0] != 'void': return
    if len(args) > 0 and args[0] == 'void': args = []
    # Not an even number of tokens (need one arg name per type name)

    ret = filt[0]
    name = filt[1]

    print_jogo_func(name, ret, args)
    print_c_func(name, ret, args)

#fd = open('gl3.h')
fd = open('/System/Library/Frameworks/OpenGL.framework/Headers/gl.h')
#fd2 = open('/usr/include/gl.h')

for line in fd.readlines():
    token = line.split()
    if len(token) < 1: continue
    elif token[0] == '#define': parse_define(token)
    elif token[0] == 'GLAPI': parse_func(token)
    elif token[0] == 'extern': parse_func(token)

