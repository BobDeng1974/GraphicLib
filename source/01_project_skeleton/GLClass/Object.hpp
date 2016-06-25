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
        
        virtual bool init();
        
        virtual std::string toString();
        
        inline GLuint getHandle() const {
            return _handle;
        }
        
    protected:
        
        std::string _className;
        
        GLuint _handle;
        
    };
    
}

#endif /* Object_hpp */
