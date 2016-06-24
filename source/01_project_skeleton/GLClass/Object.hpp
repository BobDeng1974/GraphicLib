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

namespace zdogl {
    
    class Object {
        
    public:
        
        Object();
        
        ~Object();
        
        virtual bool init() = 0;
        
        virtual std::string toString();
        
    protected:
        
        std::string _className;
        
    };
    
}

#endif /* Object_hpp */
