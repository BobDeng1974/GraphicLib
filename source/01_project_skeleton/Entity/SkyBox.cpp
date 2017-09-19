//
//  SkyBox.cpp
//  opengl-series
//
//  Created by SATAN_Z on 2017/9/17.
//
//

#include "SkyBox.hpp"
#include "Director.hpp"

using namespace ze;

SkyBox::SkyBox(){
    
}

SkyBox::~SkyBox(){
    
}

bool SkyBox::init(zdogl::TextureCube &textureCube){
    _textureCube = textureCube;
    return true;
}

SkyBox * SkyBox::create(zdogl::TextureCube &textureCube){
    SkyBox * ret = new SkyBox();
    ret->init(textureCube);
    return ret;
}

SkyBox * SkyBox::create(const std::vector<const GLchar *> &faces){
    SkyBox * ret = new SkyBox();
    ret->init(faces);
    return ret;
}

void SkyBox::initVao(){
    GLfloat vexBuf[] = {
        1, -1, 1,
        1, 1, 1,
        -1, 1, 1,
        -1, -1, 1,
        1, -1, -1,
        1, 1, -1,
        -1, 1, -1,
        -1, -1, -1
    };
    
    GLubyte idxBuf[] = {
        2, 1, 0, 3, 2, 0, // front
        1, 5, 4, 1, 4, 0, // right
        4, 5, 6, 4, 6, 7, // back
        7, 6, 2, 7, 2, 3, // left
        2, 6, 5, 2, 5, 1, // up
        3, 0, 4, 3, 4, 7  // down
    };
    
    
    _vao.bind();
    zdogl::Buffer vbo(GL_ARRAY_BUFFER);
    vbo.bind();
    vbo.inflateBuffer(sizeof(vexBuf) , vexBuf);
    
    zdogl::Buffer ebo(GL_ELEMENT_ARRAY_BUFFER);
    ebo.bind();
    ebo.inflateBuffer(sizeof(idxBuf), idxBuf);
    
    _vao.setEnabled(true , _program.getAttribIndex("aPos"));
    _vao.parseData(_program.getAttribIndex("aPos"),
                   3,
                   GL_FLOAT,
                   GL_FALSE,
                   3 * sizeof(GLfloat),
                   (GLvoid *)0);
    
    vbo.unbind();
    _vao.unbind();
}

bool SkyBox::initProgram(const std::string &vs, const std::string &fs){
    std::vector<zdogl::Shader> shaders;
    shaders.push_back(zdogl::Shader::create(vs, GL_VERTEX_SHADER));
    shaders.push_back(zdogl::Shader::create(fs, GL_FRAGMENT_SHADER));
    _program.init(shaders);
    return true;
}

bool SkyBox::init(const std::vector<const GLchar *> &faces){
    
    _textureCube.init(faces);
    
    initProgram("skyBoxVs.glsl", "skyBoxFs.glsl");
    
    initVao();
    
    return true;
}

void SkyBox::_begin(){
    _program.use();
    _textureCube.bind();
    _vao.bind();
}

void SkyBox::_end(){
    _textureCube.unbind();
    
    _vao.unbind();
    
    _program.stopUsing();
}

void SkyBox::draw(float dt){
    
    Camera * camera = ze::Director::getInstance()->getCamera();
    
    glDepthFunc(GL_LEQUAL);
    
    _begin();
    _program.setUniform("view", camera->getCurDirectionMat());
    _program.setUniform("projection" , camera->getProjectionMat());
    _program.setUniform("skybox" , 0);
    
    _textureCube.active(0);
    
    _vao.drawElements(36, GL_UNSIGNED_BYTE, nullptr);
    
    _end();
    
    glDepthFunc(GL_LESS);
}















