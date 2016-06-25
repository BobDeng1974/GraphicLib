//
//  Shader.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include "Object.hpp"


namespace zdogl {
    
    /**
     Represents a compiled OpenGL shader.
     */
    class Shader : public Object {
        
    public:
        
        Shader();
        
        ~Shader();
        
        virtual bool init();
        
        /**
         Creates a shader from a text file.
         
         @param filePath    The path to the text file containing the shader source.
         @param shaderType  Same as the argument to glCreateShader. For example GL_VERTEX_SHADER
         or GL_FRAGMENT_SHADER.
         
         @throws std::exception if an error occurs.
         */
        static Shader create(std::string &filePath , GLenum shaderType);
        
        /**
         Creates a shader from a string of shader source code.
         
         @param shaderCode  The source code for the shader.
         @param shaderType  Same as the argument to glCreateShader. For example GL_VERTEX_SHADER
         or GL_FRAGMENT_SHADER.
         
         @throws std::exception if an error occurs.
         */
        Shader(const std::string& shaderCode, GLenum shaderType);
        
        Shader(const Shader& other);
        Shader& operator =(const Shader& other);

        
    };
    
}



#endif /* Shader_hpp */
