//
//  InputManager.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/27.
//
//

#include "InputManager.hpp"
#include "Window.hpp"
#include "Application.hpp"
#include "Director.hpp"
#include <iostream>

using namespace ze;

InputManager::InputManager():
_mouseSensitivity(0.1f){
    
}

InputManager::~InputManager(){
    
}

void InputManager::onMouseEvent(float dt){
    glm::vec2 pos = getCursorPos();
    auto camera = ze::Director::getInstance()->getCamera();
    float offsetX = pos.x;
    float offsetY = pos.y;
    setCursorPos(0 , 0);
    camera->offsetDirection(offsetY * _mouseSensitivity , offsetX * _mouseSensitivity);
}

void InputManager::onKeyEvent(float dt){
    auto camera = ze::Director::getInstance()->getCamera();
    
    if (isPress('W')) {
        camera->offsetPosition(camera->forward() * camera->getMoveVelo());
    }else if (isPress('S')){
        camera->offsetPosition(-camera->forward() * camera->getMoveVelo());
    }
    
    if (isPress('A')) {
        camera->offsetPosition(-camera->right() * camera->getMoveVelo());
    }else if (isPress('D')){
        camera->offsetPosition(camera->right() * camera->getMoveVelo());
    }
    
    if (isPress('Z')) {
        camera->offsetPosition(glm::vec3(0,1,0) * camera->getMoveVelo());
    }else if (isPress('X')){
        camera->offsetPosition(glm::vec3(0,-1,0) * camera->getMoveVelo());
    }
}



void InputManager::update(float dt){
    onKeyEvent(dt);
    onMouseEvent(dt);
}

int InputManager::isPress(int key){
    zdogl::Window * pWindow = Application::getInstance()->getWindow();
    return pWindow->isPress(key);
}

void InputManager::setCursorPos(float x, float y){
    zdogl::Window * pWindow = Application::getInstance()->getWindow();
    pWindow->setCursorPos(x, y);
}

glm::vec2 InputManager::getCursorPos(){
    zdogl::Window * pWindow = Application::getInstance()->getWindow();
    return pWindow->getCursorPos();
}
