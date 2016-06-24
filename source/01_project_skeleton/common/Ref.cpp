//
//  Ref.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Ref.hpp"


using namespace ze;

Ref::Ref():
_refCount(1){
    
}

Ref::~Ref(){
    
}

void Ref::retain(){
    _refCount ++;
}

void Ref::release(){
    _refCount --;
    if (_refCount == 0) {
        delete this;
    }
}