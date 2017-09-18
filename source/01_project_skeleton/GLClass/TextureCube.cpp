//
//  TextureCube.cpp
//  opengl-series
//
//  Created by SATAN_Z on 2017/9/10.
//
//

#include "TextureCube.hpp"

using namespace zdogl;

TextureCube * TextureCube::create(std::vector<const GLchar *> names){
    TextureCube * ret = new TextureCube(names);
    ret->init(names);
    return ret;
}

TextureCube::TextureCube(){
    
}

bool TextureCube::init(std::vector<const GLchar *> names){
    glGenTextures(1 , &_handle);
    active(0);
    bind();
    for (int i = 0 ; i < names.size() ; ++ i) {
        ze::Bitmap bmp = ze::Bitmap::loadFromFile(names[i]);
        auto data = bmp.getPixelBuffer();
        if (data == nullptr) {
            throw std::runtime_error(std::string("image resource no found ") + names[i]);
        }
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i ,
                     0 ,
                     GL_RGB,
                     bmp.getWidth() ,
                     bmp.getHeight() ,
                     0 ,
                     GL_RGB ,
                     GL_UNSIGNED_BYTE ,
                     bmp.getPixelBuffer());
    }
    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    unbind();
    
    return true;
}

TextureCube::TextureCube(std::vector<const GLchar *>names){
    init(names);
}

TextureCube::~TextureCube(){
    unbind();
}

GLvoid TextureCube::bind(){
    glBindTexture(GL_TEXTURE_CUBE_MAP, _handle);
}

GLvoid TextureCube::unbind(){
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
