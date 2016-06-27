//
//  Director.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/26.
//
//  be used to game engine , not related to OpenGL

#ifndef Director_hpp
#define Director_hpp

#include "Scene.hpp"
#include "Camera.hpp"

namespace ze {
    
    class Director : public Ref{
        
    public:
        
        ~Director();
        
        static Director * getInstance();
        
        void mainLoop(float d);
        
        bool init();
        
        inline void setScene(Scene * scene){
            _curScene = scene;
        }
        
    protected:
        
        Scene * _curScene;
        
        Camera * _camera;
        
        Director();
        
        static Director * s_pDirector;
        
    };
    
}


#endif /* Director_hpp */
