//
//  Ref.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Ref_hpp
#define Ref_hpp

#include <stdio.h>

namespace ze {
    
    class Ref {
        
    public:
        Ref();
        ~Ref();
        
        virtual void retain();
        
        virtual void release();
        
        unsigned int getRefCount();
        
    protected:
        
        unsigned int _refCount;
        
    };
    
}

#endif /* Ref_hpp */
