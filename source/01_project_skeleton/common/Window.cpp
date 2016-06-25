//
//  Window.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Window.hpp"
#include <iostream>
#include <stdexcept>

using namespace zdogl;

Window::Window():
_GLFWwindow(nullptr),
_mouseSensitivity(0.1f){
    _className = "Windows";
}

Window::~Window(){
    
}

void Window::update(float dt){
    
}

bool Window::initGlew(){
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if(glewInit() != GLEW_OK){
        throw std::runtime_error("glewInit failed");
    }
    
    // GLEW throws some errors, so discard all the errors so far
    while(glGetError() != GL_NO_ERROR) {}
    
    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2){
        throw std::runtime_error("OpenGL 3.2 API is not available.");
    }
    
    // OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    return true;
}

//void OnError(int errorCode, const char* msg) {
//    throw std::runtime_error(msg);
//}

bool Window::initGlfw(){
    // initialise GLFW
    glfwSetErrorCallback(OnError);
    if(!glfwInit()){
        throw std::runtime_error("glfwInit failed");
    }
    
    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    _GLFWwindow = glfwCreateWindow((int)800, (int)600, "", NULL, NULL);
    if(!_GLFWwindow){
        throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    }
    
    // GLFW settings
    glfwSetInputMode(_GLFWwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(_GLFWwindow, 0, 0);
    glfwMakeContextCurrent(_GLFWwindow);

    return true;
}

bool Window::init(){
    initGlfw();
    initGlew();
    return true;
}