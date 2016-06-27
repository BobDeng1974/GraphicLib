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
#include <string>

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

        static Texture2D * loadFromFile(std::string & filePath ,
                                        GLint minMagFiler = GL_LINEAR,
                                        GLint wrapMode = GL_CLAMP_TO_EDGE);
        
        /**
         init a texture from a bitmap.
         
         The texture will be loaded upside down because tdogl::Bitmap pixel data
         is ordered from the top row down, but OpenGL expects the data to
         be from the bottom row up.
         
         @param bitmap  The bitmap to load the texture from
         @param minMagFiler  GL_NEAREST or GL_LINEAR
         @param wrapMode GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, or GL_CLAMP_TO_BORDER
         */
        bool init(const ze::Bitmap& bitmap,
                  GLint minMagFiler = GL_LINEAR,
                  GLint wrapMode = GL_CLAMP_TO_EDGE);
        
        inline void bind(){
            glBindTexture(GL_TEXTURE_2D , _handle);
        }
        
        inline void unbind(){
            glBindTexture(GL_TEXTURE_2D , 0);
        }
        
        /**
         生成多级纹理
         */
        inline void genMipmap(){
            bind();
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        
        /**
         激活纹理
         */
        inline void active(unsigned index){
            
            switch (index) {
                case 0:
                    glActiveTexture(GL_TEXTURE0);
                    break;
                    
                default:
                    break;
            }
            
        }
        
        Texture2D();
        
        /**
         Deletes the texture object with glDeleteTextures
         */
        ~Texture2D();
        
        inline GLfloat originalWidth() const{
            return _originalWidth;
        }
        
        GLfloat originalHeight() const{
            return _originalHeight;
        }
        
    private:
        
        GLfloat _originalWidth;
        
        GLfloat _originalHeight;
        
        
    };
    
}


#endif /* Texture2D_hpp */





