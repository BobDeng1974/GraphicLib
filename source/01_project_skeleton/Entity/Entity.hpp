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
#include <vector>
#include <string>

namespace ze {
    
    class Entity : public Ref{
        
    public:
        
        Entity();
        
        ~Entity();
        
        virtual void draw();
        
        SYNTHESIZE(float , _scale , Scale)
        
        SYNTHESIZE(glm::vec3 , _position , Position)
        
        SYNTHESIZE(glm::vec3 , _anchorPoint , AnchorPoint)
        
        virtual void addChild(Entity * child);
        
        virtual void removeChildByName(std::string & name);
        
        virtual void removeChild(Entity * child);
        
    protected:
        
        std::string _name;
        
        Entity * _parent;
        
        std::vector<Entity *> _children;
    };
    
}

#endif /* Entity_hpp */
