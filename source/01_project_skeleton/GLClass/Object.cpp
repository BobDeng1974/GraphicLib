//
//  Object.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Object.hpp"

using namespace zdogl;

Object::Object(){
    _className = "Object";
}

Object::~Object(){
    
}

std::string Object::toString(){
    return _className;
}
