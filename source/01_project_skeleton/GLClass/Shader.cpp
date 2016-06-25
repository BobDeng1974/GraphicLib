//
//  Shader.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Shader.hpp"
#include <fstream>
#include <sstream>

using namespace zdogl;

Shader::Shader(const std::string& shaderCode, GLenum shaderType) {
    
    //create the shader object
    _handle = glCreateShader(shaderType);
    if(_handle == 0)
        throw std::runtime_error("glCreateShader failed");
    
    //set the source code
    const char* code = shaderCode.c_str();
    glShaderSource(_handle, 1, (const GLchar**)&code, NULL);
    
    //compile
    glCompileShader(_handle);
    
    //throw exception if compile error occurred
    GLint status;
    glGetShaderiv(_handle, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        std::string msg("Compile failure in shader:\n");
        
        GLint infoLogLength;
        glGetShaderiv(_handle, GL_INFO_LOG_LENGTH, &infoLogLength);
        char* strInfoLog = new char[infoLogLength + 1];
        glGetShaderInfoLog(_handle, infoLogLength, NULL, strInfoLog);
        msg += strInfoLog;
        delete[] strInfoLog;
        
        glDeleteShader(_handle); _handle = 0;
        throw std::runtime_error(msg);
    }
    
}

bool Shader::init(){
    return  true;
}

Shader::Shader(const Shader& other){
    
}

Shader::~Shader() {

}

Shader& Shader::operator = (const Shader& other) {
    _handle = other._handle;
    return * this;
}

Shader Shader::create(std::string &filePath, GLenum shaderType){
    //open file
    std::ifstream f;
    f.open(filePath.c_str(), std::ios::in | std::ios::binary);
    if(!f.is_open()){
        throw std::runtime_error(std::string("Failed to open file: ") + filePath);
    }
    
    //read whole file into stringstream buffer
    std::stringstream buffer;
    buffer << f.rdbuf();
    
    //return new shader
    Shader shader(buffer.str(), shaderType);
    return shader;
}