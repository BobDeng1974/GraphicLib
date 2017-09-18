//
//  Scene.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Scene.hpp"
#include "Sprite.hpp"
#include "Director.hpp"
#include "SkyBox.hpp"

using namespace ze;

Scene::Scene():
_skyBox(nullptr){
    
}

Scene::~Scene(){
    
}

Scene * Scene::create(){
    Scene * ret = new Scene();
    
    std::vector<const GLchar*> faces = {"right.jpg",
                                        "left.jpg",
                                        "top.jpg",
                                        "bottom.jpg",
                                        "back.jpg",
                                        "front.jpg"};
    ret->init(faces);
    ret->initLogic();
    return ret;
}

Scene * Scene::create(const std::vector<const GLchar *> &faces){
    Scene * ret = new Scene();
    ret->init(faces);
    return ret;
}

bool Scene::init(const std::vector<const GLchar *> &faces){
    _skyBox = SkyBox::create(faces);
    
    return true;
}

bool Scene::init(){
    
    initLogic();
    
    return true;
}

void Scene::initLogic(){
    Sprite * sprite = Sprite::create();
    
    sprite->setPosition(glm::vec3(5 , 0 , 0));
    addChild(sprite);
    
    sprite = Sprite::create();
    addChild(sprite);
    
}

void Scene::draw(float dt){
    
    for (int i = 0 ; i < _children.size() ; i ++) {
        _children.at(i)->draw(dt);
    }
    if (_skyBox != nullptr) {
        _skyBox->draw(dt);
    }
}


