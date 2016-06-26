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


void Entity::draw(){
    
}

void Entity::addChild(ze::Entity *child){
    
}

void Entity::removeChild(ze::Entity *child){
    
}

void Entity::removeChildByName(std::string & name){
    
}


