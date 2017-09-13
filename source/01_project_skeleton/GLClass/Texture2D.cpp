//
//  Texture2D.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#include "Texture2D.hpp"


using namespace zdogl;

static GLenum TextureFormatForBitmapFormat(ze::Bitmap::Format format)
{
    switch (format) {
        case ze::Bitmap::Format_Grayscale: return GL_LUMINANCE;
        case ze::Bitmap::Format_GrayscaleAlpha: return GL_LUMINANCE_ALPHA;
        case ze::Bitmap::Format_RGB: return GL_RGB;
        case ze::Bitmap::Format_RGBA: return GL_RGBA;
        default: throw std::runtime_error("Unrecognised Bitmap::Format");
    }
}

Texture2D::Texture2D(){
    glGenTextures(1 , &_handle);
}

Texture2D::~Texture2D(){
    glDeleteTextures(1 , &_handle);
}

bool Texture2D::init(const ze::Bitmap &bitmap ,
                     GLint minMagFiler /* = GL_LINEAR */ ,
                     GLint wrapMode /* = GL_CLAMP_TO_EDGE */){
    
    bind();
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minMagFiler);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minMagFiler);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 TextureFormatForBitmapFormat(bitmap.getFormat()),
                 (GLsizei)bitmap.getWidth(),
                 (GLsizei)bitmap.getHeight(),
                 0,
                 TextureFormatForBitmapFormat(bitmap.getFormat()),
                 GL_UNSIGNED_BYTE,
                 bitmap.getPixelBuffer());
    unbind();
    
    return true;
}

bool Texture2D::init(const std::string &filePath , GLint minMagFiler , GLint wrapMode){
    ze::Bitmap bitmap = ze::Bitmap::loadFromFile(filePath);
    init(bitmap , minMagFiler , wrapMode);
    return true;
}

Texture2D::Texture2D(const ze::Bitmap &bitmap ,
                     GLint minMagFiler /* = GL_LINEAR */ ,
                     GLint wrapMode /* = GL_CLAMP_TO_EDGE */){
    glGenTextures(1 , &_handle);
    init(bitmap , minMagFiler , wrapMode);
}

Texture2D * Texture2D::loadFromFile(const std::string & filePath ,
                                    GLint minMagFiler /* = GL_LINEAR */ ,
                                    GLint wrapMode /* = GL_CLAMP_TO_EDGE */){
    Texture2D * ret = new Texture2D();
    ze::Bitmap bitmap = ze::Bitmap::loadFromFile(filePath);
    ret->init(bitmap , minMagFiler , wrapMode);
    return ret;
}
