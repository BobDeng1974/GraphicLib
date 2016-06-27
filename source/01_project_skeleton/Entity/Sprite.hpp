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
        
        bool initTexture();
        
        bool initVao();
        
        virtual void draw();
        
    protected:
        
        GLfloat * _vertexData;
        
        GLfloat * _colorData;
        
        zdogl::VertexArray * _vao;
        
        zdogl::Texture2D _texture;
        
    };
    
}


#endif /* Sprite_hpp */
