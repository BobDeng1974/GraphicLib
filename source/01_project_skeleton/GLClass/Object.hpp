//
//  Object.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Object_hpp
#define Object_hpp

#include <string>
#include "glew.h"

namespace zdogl {
    
    class Object {
        
    public:
        
        Object();
        
        ~Object();
        
        virtual bool init() = 0;
        
        virtual std::string toString();
        
        inline GLuint getHandle(){
            return _handle;
        }
        
    protected:
        
        std::string _className;
        
        GLuint _handle;
        
    };
    
}

#endif /* Object_hpp */
