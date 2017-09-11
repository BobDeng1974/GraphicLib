//
//  Scene.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Scene.hpp"
#include "Sprite.hpp"

using namespace ze;

Scene::Scene(){
    
}

Scene::~Scene(){
    
}
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
GLuint Scene::loadCubeMap(const std::vector<GLchar *> faces){
    GLuint textureID;
    glGenTextures(1, &textureID);
    glActiveTexture(GL_TEXTURE0);
    
    int width,height;
    unsigned char* image;
    
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    for(GLuint i = 0; i < faces.size(); i++)
    {
        ze::Bitmap bitmap = ze::Bitmap::loadFromFile(faces[i]);
//        image = SOIL_load_image(faces[i], &width, &height, 0, SOIL_LOAD_RGB);
//        glTexImage2D(
//                     GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
//                     GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap.getPixel(<#unsigned int width#>, <#unsigned int height#>)
//                     );
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     TextureFormatForBitmapFormat(bitmap.getFormat()),
                     (GLsizei)bitmap.getWidth(),
                     (GLsizei)bitmap.getHeight(),
                     0,
                     TextureFormatForBitmapFormat(bitmap.getFormat()),
                     GL_UNSIGNED_BYTE,
                     bitmap.getPixelBuffer());
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    
    return textureID;
}

bool Scene::init(){
    
    Sprite * sprite = new Sprite();
    
    sprite->init();
    sprite->setPosition(glm::vec3(5 , 0 , 0));
    addChild(sprite);
    
    sprite = new Sprite();
    
    sprite->init();
    addChild(sprite);
    
    return true;
}

void Scene::draw(float dt){
    
    for (int i = 0 ; i < _children.size() ; i ++) {
        _children.at(i)->draw(dt);
    }
    
}
