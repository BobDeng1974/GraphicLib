//
//  Buffer.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/25.
//
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include "Object.hpp"
#include "VertexAttribute.hpp"

namespace zdogl {
    
    class Buffer : public Object {
        
    public:
        
        /**
         constructor
         */
        Buffer(GLenum bufferType , GLenum usage /* = GL_STATIC_DRAW */);
        
        Buffer(GLenum usage = GL_STATIC_DRAW);
        
        ~Buffer();
        
        
        inline GLenum getBufferType() {
            return _bufferType;
        }
        
        inline void setBufferType(GLenum type) {
            _bufferType = type;
        }
        
        /**
         fill buffer with array element
         */
        void inflateBuffer(GLuint size , GLvoid * p , GLenum usage = GL_STATIC_DRAW);
        
        /**
         call the glBindBuffer
         */
        void bind();
        
        void unbind();
        
    protected:
        
        /**
         type of buffer
         */
        GLenum _bufferType;
        
        /**
         type of array element
         */
        GLenum _elementType;

        /**
         store the array data
         */
        union{
            GLuint * _indice;
            GLfloat * _vertice;
        }array;
        
        /**
         Specifies the expected usage pattern of the data store
         */
        GLenum _usage;
        
        /**
         tips: size is in byte
         */
        GLuint _dataSize;
        
    };
    
}

#endif /* Buffer_hpp */
