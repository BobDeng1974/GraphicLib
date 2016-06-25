//
//  Texture2D.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#ifndef Texture2D_hpp
#define Texture2D_hpp

#include "Object.hpp"
#include "Bitmap.hpp"

namespace zdogl {
    
    class Texture2D : public Object{
        
    public:
        
        /**
         Creates a texture from a bitmap.
         
         The texture will be loaded upside down because tdogl::Bitmap pixel data
         is ordered from the top row down, but OpenGL expects the data to
         be from the bottom row up.
         
         @param bitmap  The bitmap to load the texture from
         @param minMagFiler  GL_NEAREST or GL_LINEAR
         @param wrapMode GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, or GL_CLAMP_TO_BORDER
         */
        Texture2D(const ze::Bitmap& bitmap,
                GLint minMagFiler = GL_LINEAR,
                GLint wrapMode = GL_CLAMP_TO_EDGE);

        
        Texture2D();
        
        /**
         Deletes the texture object with glDeleteTextures
         */
        ~Texture2D();
        
        GLfloat originalWidth() const;
        
        GLfloat originalHeight() const;
        
    };
    
}


#endif /* Texture2D_hpp */
