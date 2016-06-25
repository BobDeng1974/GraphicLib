//
//  Application.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Application_hpp
#define Application_hpp

#include <stdio.h>
#include "Window.hpp"

namespace ze {
    
    class Application {
        
    public:
        
        int run();
        
        bool init();
        
        static Application * getInstance();
        
        static void destroyInstance();
        
    protected:
        ~Application();
        Application();
        
        zdogl::Window _window;
        
        static Application * s_pApplication;
    };
    
}

#endif /* Application_hpp */
