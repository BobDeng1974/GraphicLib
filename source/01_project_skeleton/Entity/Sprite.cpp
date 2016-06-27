//
//  Sprite.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/26.
//
//

#include "Sprite.hpp"
#include <stdlib.h>
#include <vector>
#include "Director.hpp"
#include "glm/glm.hpp"

using namespace ze;

Sprite::Sprite():
_vao(nullptr),
_vertexData(nullptr),
_colorData(nullptr),
_texture(nullptr){
    
}

Sprite::~Sprite(){
    
}

bool Sprite::initTexture(){
    Bitmap bitmap = Bitmap::loadFromFile("wooden-crate.jpg");
    
    _texture = new zdogl::Texture2D();
    
    _texture->init(bitmap);
}

bool Sprite::initProgram(){
    std::vector<zdogl::Shader> shaders;
    shaders.push_back(zdogl::Shader::create("VertexShader.glsl", GL_VERTEX_SHADER));
    shaders.push_back(zdogl::Shader::create("FragmentShader.glsl", GL_FRAGMENT_SHADER));
    _program = new zdogl::Program(shaders);
}

void Sprite::draw(){
    
    auto camera = Director::getInstance()->getCamera();
    
    //启用shader程序
    _program->use();
    
    _vao->bind();
    
    _texture->active(0);
    
    _texture->bind();
    
//    auto t = camera->getViewMat();
    
    _program->setUniform("VxP", camera->getViewProjectionMat());
    
//    _program->setUniform("projection", camera->getProjectionMat());
    
    _program->setUniform("tex", 0);
    
    glDrawArrays(GL_TRIANGLES , 0 , 36);
    
    _vao->unbind();
    
    _texture->unbind();
    
    _program->stopUsing();
    
}


bool Sprite::initVao(){
    // Make a cube out of triangles (two triangles per side)
    GLfloat vertexData[] = {
        //  X     Y     Z       U     V
        // bottom
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
        
        // top
        -1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
        1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
        1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
        
        // front
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
        
        // back
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
        1.0f, 1.0f,-1.0f,   1.0f, 1.0f,
        
        // left
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
        
        // right
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
        1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 1.0f
    };
    GLint size = sizeof(vertexData);
    _vertexData = (GLfloat *)malloc(size);
    memcpy(_vertexData , vertexData , size);
    
    
    zdogl::Buffer vbo;
    vbo.setBufferType(GL_ARRAY_BUFFER);
    vbo.inflateBuffer(size , vertexData , GL_STATIC_DRAW);
    
    _vao = new zdogl::VertexArray();
    _vao->addBuffer(vbo);
    
    _vao->bind();
    
    glEnableVertexAttribArray(_program->getAttribIndex("vertex"));
    glVertexAttribPointer(_program->getAttribIndex("vertex"),
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          5 * sizeof(GLfloat),
                          0);
    
    glEnableVertexAttribArray(_program->getAttribIndex("texCoor"));
    glVertexAttribPointer(_program->getAttribIndex("texCoor"),
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          5 * sizeof(GLfloat),
                          (GLvoid *)(3 * sizeof(GLfloat)));
    
    _vao->unbind();
    
}

bool Sprite::init(){
    initProgram();
    
    initTexture();
    
    initVao();
    
    return true;
}






















