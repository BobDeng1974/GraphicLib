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

namespace ze {
    
    class Director : public Ref{
        
    public:
        
        ~Director();
        
        static Director * getInstance();
        
        void mainLoop(float d);
        
        void setScene(Scene * scene);
        
    protected:
        
        Scene * _CurSecne;
        
        Director();
        
        static Director * s_pDirector;
        
    };
    
}


#endif /* Director_hpp */
