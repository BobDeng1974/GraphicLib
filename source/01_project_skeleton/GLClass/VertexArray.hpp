//
//  VertexAttribute.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include <vector>

#include "Buffer.hpp"

namespace zdogl {
    
    class VertexArray : public Buffer{
        
    public:
        
        VertexArray();
        
        ~VertexArray();
        
        GLvoid bind();
        
        GLvoid unbind();
        
        GLvoid addBuffer(Buffer buffer);
        
//        GLvoid removeBuffer();
        
    protected:
        
        std::vector<Buffer> _buffers;
        
    };
    
}

#endif /* VertexArray_hpp */
