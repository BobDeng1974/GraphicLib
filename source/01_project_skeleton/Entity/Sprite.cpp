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
#include <glm/gtc/matrix_transform.hpp>

#include "Application.hpp"


using namespace ze;

Sprite::Sprite():
_rotate(0){
    
}

Sprite::~Sprite(){
    
}

Sprite * Sprite::create(){
    Sprite * ret = new Sprite();
    ret->init();
    return ret;
}

bool Sprite::initTexture(){
    

    _texture.init("wooden-crate.jpg");
    
    _texture.genMipmap();
    return true;
}

bool Sprite::initProgram(){
    std::vector<zdogl::Shader> shaders;
    shaders.push_back(zdogl::Shader::create("VertexShader.glsl", GL_VERTEX_SHADER));
    shaders.push_back(zdogl::Shader::create("FragmentShader.glsl", GL_FRAGMENT_SHADER));
    _program.init(shaders);
    return true;
}


void Sprite::draw(float dt){
    
    auto camera = Director::getInstance()->getCamera();
    
    auto window = ze::Application::getInstance()->getWindow();
    
    
    if (window->isPress('F')) {
//        factor = factor > 0.5 ? 0 : 1;
    }
    
    //启用shader程序
    _program.use();
    
    _vao.bind();
    
    _texture.bind();
    
    _texture.active(0);
    
    
    if (_position.x < 0.1f) {
        _rotate += dt * 45;
        while (_rotate > 360) {
            _rotate -= 360;
        }
    }
    
    glm::mat4 model = glm::rotate(glm::mat4() , glm::radians(-_rotate), glm::vec3(0,1,0));
    model = glm::translate(model , _position);
    
    _program.setUniform("light.position", camera->getPosition());
    _program.setUniform("light.position",  glm::vec3(0,0,5));
    _program.setUniform("light.intensities", glm::vec3(1,1,1));
    
    _program.setUniform("camera.position", camera->getPosition());
    
    _program.setUniform("model", model);
    
    _program.setUniform("VxP", camera->getViewProjectionMat());
    
    _program.setUniform("tex", 0);
    
    _vao.drawArray(0 , 36);
    
    _vao.unbind();
    
    _texture.unbind();
    
    _program.stopUsing();
    
}


bool Sprite::initVao(){
    // Make a cube out of triangles (two triangles per side)
    GLfloat vertexData[] = {
        //  X     Y     Z       U     V          Normal
        // bottom
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   0.0f, -1.0f, 0.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,
        
        // top
        -1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
        1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 1.0f, 0.0f,
        
        // front
        -1.0f,-1.0f, 1.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,
        1.0f,-1.0f, 1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,
        1.0f,-1.0f, 1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,
        
        // back
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
        1.0f, 1.0f,-1.0f,   1.0f, 1.0f,   0.0f, 0.0f, -1.0f,
        
        // left
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        
        // right
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
        1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   1.0f, 0.0f, 0.0f,
        1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
        1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
        1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   1.0f, 0.0f, 0.0f
    };
    GLint size = sizeof(vertexData);
    
    zdogl::Buffer vbo(GL_ARRAY_BUFFER);
    _vao.bind();
    vbo.bind();
    vbo.inflateBuffer(size , vertexData , GL_STATIC_DRAW);
    
    
    _vao.setEnabled(true , _program.getAttribIndex("vertex"));
    _vao.parseData(_program.getAttribIndex("vertex"),
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          8 * sizeof(GLfloat),
                          0);
    
    _vao.setEnabled(true , _program.getAttribIndex("normal"));
    _vao.parseData(_program.getAttribIndex("normal"),
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          8 * sizeof(GLfloat),
                          (GLvoid *)(5 * sizeof(GLfloat)));
    
    _vao.setEnabled(true , _program.getAttribIndex("vertTexCoor"));
    _vao.parseData(_program.getAttribIndex("vertTexCoor"),
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          8 * sizeof(GLfloat),
                          (GLvoid *)(3 * sizeof(GLfloat)));
    vbo.unbind();
    _vao.unbind();
    
    return true;
    
}

bool Sprite::init(){
    initProgram();
    
    initTexture();
    
    initVao();
    
    return true;
}






















