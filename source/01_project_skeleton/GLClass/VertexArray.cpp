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

GLvoid VertexArray::setEnabled(bool bEnabled, GLuint attrIndex){
    if (bEnabled) {
        glEnableVertexAttribArray(attrIndex);
    }else{
        glDisableVertexAttribArray(attrIndex);
    }
}

GLvoid VertexArray::drawArray(GLint first, GLsizei count , GLenum mode /*= GL_TRIANGLES*/){
    glDrawArrays(mode , first, count);
}

GLvoid VertexArray::drawElements(GLsizei count, GLenum type, const GLvoid *indices , GLenum mode  /*= GL_TRIANGLES*/){
    glDrawElements(mode, count, type, indices);
}

GLvoid VertexArray::parseData(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer){
    glVertexAttribPointer(index , size , type , normalized , stride , pointer);
}

GLvoid VertexArray::unbind(){
    glBindVertexArray(0);
    for (int i = 0 ; i < _buffers.size() ; i ++) {
        _buffers.at(i).unbind();
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
