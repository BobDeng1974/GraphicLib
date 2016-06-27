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