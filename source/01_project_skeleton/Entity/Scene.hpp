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
#include "TextureCube.hpp"

namespace ze {
    
    class Scene : public Entity{
        
    public:
        Scene();
        ~Scene();
        
        virtual bool init();
        
        virtual void draw(float dt);
        
        GLuint loadCubeMap(const std::vector<GLchar *> names);
        
    protected:
        zdogl::TextureCube _textureCube;
        
    };
    
}

#endif /* Scene_hpp */
