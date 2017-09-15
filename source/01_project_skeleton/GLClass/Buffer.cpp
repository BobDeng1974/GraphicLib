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
_elementType(0),
_usage(usage){
    glGenBuffers(1 , &_handle);
}

Buffer::Buffer(GLenum usage /* = GL_STATIC_DRAW */):
_dataSize(0),
_bufferType(0),
_elementType(0),
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
_elementType(0),
_usage(usage){
    inflateBuffer(size, p , _usage);
}

void Buffer::inflateBuffer(GLuint size , GLvoid * p ,  GLenum usage /*= GL_STATIC_DRAW*/){
    bind();
    switch (_bufferType) {
        case GL_ARRAY_BUFFER:
            
            array._vertice = (GLfloat *)malloc(size);
            
            memcpy(array._vertice , p , size);
            glBufferData(_bufferType , size , array._vertice , usage);
            break;
            
        case GL_ELEMENT_ARRAY_BUFFER:
            
            array._indice = (GLuint *)malloc(size);
            
            memcpy(array._indice , p , size);
            glBufferData(_bufferType , size , array._indice , usage);
            break;
            
        default:
            break;
    }
    _usage = usage;
    _dataSize = size;
}



