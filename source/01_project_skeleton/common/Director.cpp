//
//  Director.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/26.
//
//

#include "Director.hpp"
#include "glm/glm.hpp"

using namespace ze;

Director * Director::s_pDirector = nullptr;

Director::Director():
_curScene(nullptr),
_camera(nullptr){
    
}

Director * Director::getInstance(){
    if (! s_pDirector) {
        s_pDirector = new Director();
        s_pDirector->init();
    }
    return s_pDirector;
}

bool Director::init(){
    
    _curScene = new Scene();
    
    _curScene->init();
    
    _camera = new Camera();
    
    glm::vec3 position(0,0,5);
    
    _camera->setPosition(position);
    
    _camera->initLookAt(glm::vec3(0,0,0));
    
    return true;
}

void Director::mainLoop(float d){
    
    _curScene->draw(d);
    
}























