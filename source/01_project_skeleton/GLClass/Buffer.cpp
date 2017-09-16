//
//  Buffer.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#include "Buffer.hpp"
#include "stdlib.h"
#include <vector>

using namespace zdogl;

Buffer::Buffer(GLenum bufferType , GLenum usage /* = GL_STATIC_DRAW */):
_dataSize(0),
_bufferType(bufferType),
_usage(usage){
    glGenBuffers(1 , &_handle);
}

Buffer::Buffer(GLenum usage /* = GL_STATIC_DRAW */):
_dataSize(0),
_bufferType(GL_ARRAY_BUFFER),
_usage(GL_STATIC_DRAW){
    glGenBuffers(1 , &_handle);
}

Buffer::Buffer(const Buffer & other){
    
}

Buffer::~Buffer(){
    unbind();
}

Buffer::Buffer(GLenum bufferType , GLuint size , void * p , GLenum usage /*= GL_STATIC_DRAW*/):
_dataSize(0),
_bufferType(bufferType),
_usage(usage){
    inflateBuffer(size, p , _usage);
}

void Buffer::inflateBuffer(GLuint size , GLvoid * p ,  GLenum usage /*= GL_STATIC_DRAW*/){
    bind();
    switch (_bufferType) {
        case GL_ARRAY_BUFFER:
            glBufferData(_bufferType , size , p , usage);
            break;
            
        case GL_ELEMENT_ARRAY_BUFFER:
            glBufferData(_bufferType , size , p , usage);
            break;
            
        default:
            break;
    }
    _usage = usage;
    _dataSize = size;
}



