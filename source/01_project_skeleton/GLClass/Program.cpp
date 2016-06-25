//
//  Program.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Program.hpp"

#include <stdexcept>
#include <glm/gtc/type_ptr.hpp>

using namespace zdogl;

Program::Program(const std::vector<Shader>& shaders){
    
    if(shaders.size() <= 0)
        throw std::runtime_error("No shaders were provided to create the program");
    
    //create the program object
    _handle = glCreateProgram();
    if(_handle == 0)
        throw std::runtime_error("glCreateProgram failed");
    
    //attach all the shaders
    for(unsigned i = 0; i < shaders.size(); ++i)
        glAttachShader(_handle, shaders[i].getHandle());
    
    //link the shaders together
    glLinkProgram(_handle);
    
    //detach all the shaders
    for(unsigned i = 0; i < shaders.size(); ++i)
        glDetachShader(_handle, shaders[i].getHandle());
    
    //throw exception if linking failed
    GLint status;
    glGetProgramiv(_handle, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        std::string msg("Program linking failure: ");
        
        GLint infoLogLength;
        glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &infoLogLength);
        char* strInfoLog = new char[infoLogLength + 1];
        glGetProgramInfoLog(_handle, infoLogLength, NULL, strInfoLog);
        msg += strInfoLog;
        delete[] strInfoLog;
        
        glDeleteProgram(_handle); _handle = 0;
        throw std::runtime_error(msg);
    }
}

Program::~Program() {
    //might be 0 if ctor fails by throwing exception
    if(_handle != 0) glDeleteProgram(_handle);
}

void Program::use() const {
    glUseProgram(_handle);
}

bool Program::isInUse() const {
    GLint currentProgram = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);
    return (currentProgram == (GLint)_handle);
}

void Program::stopUsing() const {
    assert(isInUse());
    glUseProgram(0);
}

GLint Program::getAttribIndex(const GLchar* attribName) const {
    if(!attribName)
        throw std::runtime_error("attribName was NULL");
    
    GLint attrib = glGetAttribLocation(_handle, attribName);
    if(attrib == -1)
        throw std::runtime_error(std::string("Program attribute not found: ") + attribName);
    
    return attrib;
}

GLint Program::getUniformIndex(const GLchar* uniformName) const {
    if(!uniformName)
        throw std::runtime_error("uniformName was NULL");
    
    GLint uniform = glGetUniformLocation(_handle, uniformName);
    if(uniform == -1)
        throw std::runtime_error(std::string("Program uniform not found: ") + uniformName);
    
    return uniform;
}



ATTRIB_N_UNIFORM_SETTERS(GLfloat, , f);
ATTRIB_N_UNIFORM_SETTERS(GLdouble, , d);
ATTRIB_N_UNIFORM_SETTERS(GLint, I, i);
ATTRIB_N_UNIFORM_SETTERS(GLuint, I, ui);

void Program::setUniformMatrix2(const GLchar* name, const GLfloat* v, GLsizei count, GLboolean transpose) {
    assert(isInUse());
    glUniformMatrix2fv(getUniformIndex(name), count, transpose, v);
}

void Program::setUniformMatrix3(const GLchar* name, const GLfloat* v, GLsizei count, GLboolean transpose) {
    assert(isInUse());
    glUniformMatrix3fv(getUniformIndex(name), count, transpose, v);
}

void Program::setUniformMatrix4(const GLchar* name, const GLfloat* v, GLsizei count, GLboolean transpose) {
    assert(isInUse());
    glUniformMatrix4fv(getUniformIndex(name), count, transpose, v);
}

void Program::setUniform(const GLchar* name, const glm::mat2& m, GLboolean transpose) {
    assert(isInUse());
    glUniformMatrix2fv(getUniformIndex(name), 1, transpose, glm::value_ptr(m));
}

void Program::setUniform(const GLchar* name, const glm::mat3& m, GLboolean transpose) {
    assert(isInUse());
    glUniformMatrix3fv(getUniformIndex(name), 1, transpose, glm::value_ptr(m));
}

void Program::setUniform(const GLchar* name, const glm::mat4& m, GLboolean transpose) {
    assert(isInUse());
    glUniformMatrix4fv(getUniformIndex(name), 1, transpose, glm::value_ptr(m));
}

void Program::setUniform(const GLchar* uniformName, const glm::vec3& v) {
    setUniform3v(uniformName, glm::value_ptr(v));
}

void Program::setUniform(const GLchar* uniformName, const glm::vec4& v) {
    setUniform4v(uniformName, glm::value_ptr(v));
}
