//
//  TextureCube.hpp
//  opengl-series
//
//  Created by SATAN_Z on 2017/9/10.
//
//

#ifndef TextureCube_hpp
#define TextureCube_hpp

#include <stdio.h>
#include "Bitmap.hpp"
#include "Object.hpp"
#include "Macro.h"
#include <string>
#include <vector>

namespace zdogl {
    
    class TextureCube : public Object{
        
    public:
        TextureCube(std::vector<const GLchar *> names);
        
        ~TextureCube();
        
        TextureCube();
        
        static TextureCube * create(std::vector<const GLchar *> names);
        
        virtual bool init(std::vector<const GLchar *> names);
        
        inline GLvoid active(GLuint index){
            glActiveTexture(GL_TEXTURE0 + index);
        }
        
        GLvoid bind();
        
        GLvoid unbind();
    };
}

#endif /* TextureCube_hpp */
