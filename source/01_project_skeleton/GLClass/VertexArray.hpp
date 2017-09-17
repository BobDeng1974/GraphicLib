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
    
    class VertexArray : public Object{
        
    public:
        
        VertexArray();
        
        ~VertexArray();
        
        GLvoid bind();
        
        GLvoid unbind();
        
        GLvoid setEnabled(bool bEnabled , GLuint attrIndex);
        
        GLvoid drawArray(GLint first , GLsizei count , GLenum mode = GL_TRIANGLES);
        
        /**
         * 解析数据，告诉GPU数据的意义
         * @param  index      属性索引
         * @param  size       每组数据的个数
         * @param  type       数据类型
         * @param  normalized 是否归一化
         * @param  stride     步长
         * @param  pointer    起始地址偏移量
         * @return            void
         */
        GLvoid parseData(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,const GLvoid * pointer);
        
        GLvoid addBuffer(Buffer buffer);
        
    protected:
        
        std::vector<Buffer> _buffers;
        
    };
    
}

#endif /* VertexArray_hpp */
