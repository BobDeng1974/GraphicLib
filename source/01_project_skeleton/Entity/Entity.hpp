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
#include "Program.hpp"

namespace ze {
    
    class Entity : public Ref{
        
    public:
        
        Entity();
        
        ~Entity();
        
        virtual void draw(float dt);
        
        virtual bool init();
        
        virtual void setScale(double scale){
            this->_scale = scale;
        }
        
        virtual double getScale(){
            return _scale;
        }

        virtual glm::vec3 getPosition(){
            return _position;
        }
        
        void setPosition(glm::vec3 position){
            _position = position;
        }
        
        virtual glm::vec3 getAnchorPoint(){
            return _anchorPoint;
        }
        
        virtual void setAnchorPoint(glm::vec3 anchorPoint){
            _anchorPoint = anchorPoint;
        }
        
        virtual void addChild(Entity * child);
        
        virtual void removeChildByName(const std::string & name);
        
        virtual void removeChild(Entity * child);
        
        virtual void setName(const std::string name){
            _name = name;
        }
        
        virtual std::string getName(){
            return _name;
        }
        
    protected:
        
        std::string _name;
        
        Entity * _parent;
        
        double _scale;
        
        glm::vec3 _position;
        
        glm::vec3 _anchorPoint;
        
        std::vector<Entity *> _children;
        
//        zdogl::Program _program;
    };
    
}

#endif /* Entity_hpp */
