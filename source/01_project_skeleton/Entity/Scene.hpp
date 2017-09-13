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
#include "VertexArray.hpp"

namespace ze {
    
    class Scene : public Entity{
        
    public:
        Scene();
        ~Scene();
        
        static Scene * create();
        
        virtual bool init();
        
        virtual bool initVao();
        
        virtual bool initProgram();
        
        virtual void draw(float dt);
        
        GLuint loadCubeMap(const std::vector<GLchar *> names);
        
        
    protected:
        zdogl::TextureCube _textureCube;
        
        GLfloat * _vertexData;
        
        GLfloat * _colorData;
        
        zdogl::VertexArray _vao;
        
    };
    
}

#endif /* Scene_hpp */
