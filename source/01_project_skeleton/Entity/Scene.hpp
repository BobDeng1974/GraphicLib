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
#include "SkyBox.hpp"
#include <string>

namespace ze {
    
    class Scene : public Entity{
        
    public:
        Scene();
        ~Scene();
        
        static Scene * create();
        
        static Scene * create(const std::vector<const GLchar *> &faces);
        
        virtual bool init();
        
        virtual bool init(const std::vector<const GLchar *> &faces);
        
        void initLogic();
        
        virtual void draw(float dt);
        
    protected:
        
        SkyBox * _skyBox;
        
    };
    
}

#endif /* Scene_hpp */
