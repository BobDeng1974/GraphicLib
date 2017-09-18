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
#include <string>

namespace ze {
    
    class Scene : public Entity{
        
    public:
        Scene();
        ~Scene();
        
        static Scene * create();
        
        virtual bool init();
        
        void initLogic();
        
        void initSkyBox();
        
        virtual void initVao(zdogl::VertexArray &vao , GLfloat * vertice , GLuint size);
        
        virtual bool initProgram(zdogl::Program &program , const std::string &vs , const std::string &fs);
        
        virtual void draw(float dt);
        
        virtual void drawSelf(float dt);
        
        GLuint loadCubeMap(const std::vector<const GLchar *> &names);
        
        
    protected:
        zdogl::TextureCube _textureCube;
        
        zdogl::VertexArray _skyBoxVao;
        
        zdogl::Program _skyBoxProgram;
        
    };
    
}

#endif /* Scene_hpp */
