//
//  Scene.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Scene.hpp"
#include "Sprite.hpp"
#include "Director.hpp"
#include "SkyBox.hpp"

using namespace ze;

Scene::Scene(){
    
}

Scene::~Scene(){
    
}

Scene * Scene::create(){
    Scene * ret = new Scene();
    ret->init();
    return ret;
}

GLuint Scene::loadCubeMap(const std::vector<const GLchar *> &names){
    _textureCube = zdogl::TextureCube(names);
    
    return _textureCube.getHandle();
}

void Scene::initVao(zdogl::VertexArray &vao , GLfloat *vertice , GLuint size){
    zdogl::Buffer buffer;
    buffer.inflateBuffer(size , vertice);
    vao.addBuffer(buffer);
}



void Scene::initSkyBox(){
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
    
    initVao(_skyBoxVao , skyboxVertices , sizeof(skyboxVertices));
    initProgram(_skyBoxProgram , "skyBoxVs.glsl", "skyBoxFs.glsl");
    _skyBoxVao.bind();
    _skyBoxVao.setEnabled(true , _skyBoxProgram.getAttribIndex("aPos"));
    _skyBoxVao.parseData(_skyBoxProgram.getAttribIndex("aPos"),
                         3,
                         GL_FLOAT,
                         GL_FALSE,
                         3 * sizeof(GLfloat),
                         (GLvoid *)0);
    _skyBoxVao.unbind();
}

bool Scene::initProgram(zdogl::Program &program , const std::string &vs, const std::string &fs){
    std::vector<zdogl::Shader> shaders;
    shaders.push_back(zdogl::Shader::create(vs, GL_VERTEX_SHADER));
    shaders.push_back(zdogl::Shader::create(fs, GL_FRAGMENT_SHADER));
    program.init(shaders);
    return true;
}

void Scene::drawSelf(float dt){
    Camera * camera = ze::Director::getInstance()->getCamera();
    
    glm::mat4 view = glm::mat4(glm::mat3(camera->getViewMat()));
    
    glDepthFunc(GL_LEQUAL);
    
    _skyBoxProgram.use();
    _skyBoxProgram.setUniform("view", view);
    
    _skyBoxProgram.setUniform("projection" , camera->getProjectionMat());
    _skyBoxVao.bind();
    _textureCube.bind();
    
    _skyBoxVao.drawArray(0 , 36);
    
    _skyBoxVao.unbind();
    
    glDepthFunc(GL_LESS);
    
    
//    _skyBoxProgram.use();
//    
//    _skyBoxProgram.setUniform("view", view);
//    
//    _skyBoxProgram.setUniform("projection", projection);
//    
//    _skyBoxVao.bind();
//    
//    _textureCube.bind();
//    
//    _skyBoxVao.drawArray(0 , 36);
//    
//    _skyBoxVao.unbind();
//    
//    _textureCube.unbind();
//    
//    glDepthMask(GL_TRUE);
//    
//    _skyBoxProgram.stopUsing();
    
    
}

bool Scene::init(){
    
    initLogic();
    
    std::vector<const GLchar*> faces = {"right.jpg",
                                        "left.jpg",
                                        "top.jpg",
                                        "bottom.jpg",
                                        "back.jpg",
                                        "front.jpg"};
    
    loadCubeMap(faces);
    
    initSkyBox();
    
    return true;
}

void Scene::initLogic(){
    Sprite * sprite = Sprite::create();
    
    sprite->setPosition(glm::vec3(5 , 0 , 0));
    addChild(sprite);
    
    sprite = Sprite::create();
    addChild(sprite);
    
    std::vector<const GLchar*> faces = {"right.jpg",
                                        "left.jpg",
                                        "top.jpg",
                                        "bottom.jpg",
                                        "back.jpg",
                                        "front.jpg"};
    
    SkyBox * skyBox = SkyBox::create(faces);
    
    addChild(skyBox);
}

void Scene::draw(float dt){
    
//    drawSelf(dt);
    
    for (int i = 0 ; i < _children.size() ; i ++) {
        _children.at(i)->draw(dt);
    }
    
}


