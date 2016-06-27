//
//  VertexArray.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#include "VertexArray.hpp"

using namespace zdogl;


VertexArray::VertexArray(){
    glGenVertexArrays(1 , &_handle);
}

VertexArray::~VertexArray(){
    unbind();
}

GLvoid VertexArray::unbind(){
    glBindVertexArray(0);
    for (int i = 0 ; i < _buffers.size() ; i ++) {
        _buffers.at(i).bind();
    }
}

GLvoid VertexArray::bind(){
    glBindVertexArray(_handle);
    for (int i = 0 ; i < _buffers.size() ; i ++) {
        _buffers.at(i).bind();
    }
}

GLvoid VertexArray::addBuffer(zdogl::Buffer buffer){
    _buffers.push_back(buffer);
}