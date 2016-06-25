//
//  Application.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Application.hpp"

extern int * pWindow;

using namespace ze;

Application * Application::s_pApplication = nullptr;

Application * Application::getInstance(){
    if (! s_pApplication) {
        s_pApplication = new Application();
        s_pApplication->init();
    }
    return s_pApplication;
}

int Application::run(){
    
    double lastTime = _window.getCurTime();
    
    while (!_window.shouldClose()) {
        
        double curTime = _window.getCurTime();
        
        _window.update(curTime - lastTime);
        
        lastTime = curTime;
        
        //render todo
        
    }

    _window.terminate();
    
    return 0;
}

void Application::destroyInstance(){
    delete s_pApplication;
    s_pApplication = nullptr;
}

bool Application::init(){
    
    return true;
}

Application::Application(){
    
}

Application::~Application(){
    
}



