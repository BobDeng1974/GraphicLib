//
//  Director.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/26.
//
//

#include "Director.hpp"


using namespace ze;

Director * Director::s_pDirector = nullptr;

Director::Director():
_curScene(nullptr){
    
}

Director * Director::getInstance(){
    if (! s_pDirector) {
        s_pDirector = new Director();
        s_pDirector->init();
    }
    return s_pDirector;
}

bool Director::init(){
    
    return true;
}

void Director::mainLoop(float d){
    
}























