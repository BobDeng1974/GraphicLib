//
//  Entity.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Entity.hpp"


using namespace ze;

Entity::Entity():
_position(0 , 0 , 0),
_anchorPoint(0 , 0 , 0),
_scale(1),
_parent(nullptr){
    
}

Entity::~Entity(){
    
}

bool Entity::init(){
    
    return true;
}

void Entity::_begin(){
    
}

void Entity::_end(){
    
}

void Entity::draw(float dt){
    
}

void Entity::addChild(ze::Entity *child){
    _children.push_back(child);
}

void Entity::removeChild(ze::Entity *child){
    for (auto iter = _children.begin() ; iter != _children.end(); iter ++) {
        if (*(iter) == child) {
            _children.erase(iter);
            return;
        }
    }
}

void Entity::removeChildByName(const std::string & name){
    for (auto iter = _children.begin() ; iter != _children.end() ; ++iter) {
        if ((*iter)->getName() == name) {
            _children.erase(iter);
            return;
        }
    }
}


