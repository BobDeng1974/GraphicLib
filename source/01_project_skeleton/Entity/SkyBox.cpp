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
    GLfloat skyboxVertices[] = {
        // Positions
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        
        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,
        
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        
        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,
        
        -1.0f,  1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,
        
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f
    };
    zdogl::Buffer buffer;
    buffer.setBufferType(GL_ARRAY_BUFFER);
    buffer.inflateBuffer(sizeof(skyboxVertices) , skyboxVertices);
    _vao.addBuffer(buffer);
    _vao.bind();
    _vao.setEnabled(true , _program.getAttribIndex("aPos"));
    _vao.parseData(_program.getAttribIndex("aPos"),
                   3,
                   GL_FLOAT,
                   GL_FALSE,
                   3 * sizeof(GLfloat),
                   (GLvoid *)0);
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

void SkyBox::draw(float dt){
    glDepthFunc(GL_LEQUAL);
    
    Camera * camera = ze::Director::getInstance()->getCamera();
    _program.use();
    glm::mat4 view = glm::mat4(glm::mat3(camera->getViewMat()));
    _program.setUniform("view", view);
    
    _program.setUniform("projection" , camera->getProjectionMat());
    _vao.bind();
    _textureCube.bind();
    
    _vao.drawArray(0 , 36);
    
    _vao.unbind();
    
    glDepthFunc(GL_LESS);
}















