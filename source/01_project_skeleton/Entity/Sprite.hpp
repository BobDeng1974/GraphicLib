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

namespace ze {
    
    class Sprite : public Entity{
        
    public:
        
        Sprite();
        
        ~Sprite();
        
        virtual bool init();
        
        virtual void draw();
        
    protected:
        
        GLfloat * _vertexData;
        
        GLfloat * _colorData;
        
        zdogl::VertexArray * _vao;
        
        
        
    };
    
}


#endif /* Sprite_hpp */
