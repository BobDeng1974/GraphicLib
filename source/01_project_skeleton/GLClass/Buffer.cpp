//
//  Buffer.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#include "Buffer.hpp"

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