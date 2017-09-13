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

Scene * Scene::create(){
    Scene * ret = new Scene();
    ret->init();
    return ret;
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
GLuint Scene::loadCubeMap(const std::vector<GLchar *> names){
    _textureCube = zdogl::TextureCube(names);
    
    
    
    return _textureCube.getHandle();
}

bool Scene::initVao(){
    return true;
}

bool Scene::initProgram(){
    return true;
}

bool Scene::init(){
    
    Sprite * sprite = Sprite::create();

    sprite->setPosition(glm::vec3(5 , 0 , 0));
    addChild(sprite);
    
    sprite = Sprite::create();
    
    addChild(sprite);
    
    return true;
}

void Scene::draw(float dt){
    
    for (int i = 0 ; i < _children.size() ; i ++) {
        _children.at(i)->draw(dt);
    }
    
}
