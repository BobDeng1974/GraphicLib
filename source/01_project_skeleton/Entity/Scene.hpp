//
//  Scene.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Scene_hpp
#define Scene_hpp

#include "Entity.hpp"

namespace ze {
    
    class Scene : public Entity{
        
    public:
        Scene();
        ~Scene();
        
        virtual bool init();
        
        virtual void draw();
        
    };
    
}

#endif /* Scene_hpp */
