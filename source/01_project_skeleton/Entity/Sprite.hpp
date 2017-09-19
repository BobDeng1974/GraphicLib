//
//  Sprite.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/26.
//
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "Entity.hpp"
#include "glew.h"
#include "VertexArray.hpp"
#include "Texture2D.hpp"

namespace ze {
    
    class Sprite : public Entity{
        
    public:
        
        Sprite();
        
        ~Sprite();
        
        virtual bool init();
        
        static Sprite * create();
        
        bool initTexture();
        
        bool initVao();
        
        bool initProgram();
        
        virtual void _begin();
        
        virtual void _end();
        
        virtual void draw(float dt);
        
    protected:
        //角度
        GLfloat _rotate;
        
        zdogl::VertexArray  _vao;
        
        zdogl::Texture2D  _texture;
        
        zdogl::Program _program;
        
    };
    
}


#endif /* Sprite_hpp */
