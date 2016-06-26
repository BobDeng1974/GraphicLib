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
    
    Sprite * Sprite = new class Sprite();
    
    addChild(Sprite);
    
    return true;
}

void Scene::draw(){
    
    for (int i = 0 ; i < _children.size() ; i ++) {
        _children.at(i)->draw();
    }
    
}