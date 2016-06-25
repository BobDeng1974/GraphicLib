//
//  Entity.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Ref.hpp"
#include "glm/glm.hpp"
#include "Macro.h"

namespace ze {
    
    class Entity : public Ref{
        
    public:
        
        Entity();
        
        ~Entity();
        
        virtual void draw();
        
        SYNTHESIZE(float , _scale , Scale)
        
        SYNTHESIZE(glm::vec3 , _position , Position)
        
        SYNTHESIZE(glm::vec3 , _anchorPoint , AnchorPoint)
        
    protected:
        
        
        
    };
    
}

#endif /* Entity_hpp */
