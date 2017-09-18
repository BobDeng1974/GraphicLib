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
#include "Director.hpp"

using namespace zdogl;

Window::Window():
_GLFWwindow(nullptr),
_fps(1 / 60),
_width(800),
_height(600),
_inputManager(nullptr){
    _className = "Windows";
    init();
}

Window::~Window(){
    
}

void Window::update(float dt){
    
    pollEvent();
    
    // clear everything
    glClearColor(0, 0, 0, 1); // black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    ze::Director::getInstance()->mainLoop(dt);
    
    _inputManager->update(dt);
    
    swapBuffer();
}

static void OnError(int errorCode, const char* msg) {
    throw std::runtime_error(msg);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_PRESS)
        return;
    switch (key)
    {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        default:
            break;
    }
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

void Window::pollEvent(){
    glfwPollEvents();
}

void Window::swapBuffer(){
    glfwSwapBuffers(_GLFWwindow);
}

bool Window::initGlfw(){
    // initialise GLFW
    glfwSetErrorCallback(OnError);
    if(!glfwInit()){
        throw std::runtime_error("glfwInit failed");
    }
    
    _inputManager = new ze::InputManager();
    
    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    _GLFWwindow = glfwCreateWindow((int)_width , (int)_height , "" , NULL , NULL);
    if(!_GLFWwindow){
        throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    }
    glfwSetKeyCallback(_GLFWwindow , key_callback);

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
