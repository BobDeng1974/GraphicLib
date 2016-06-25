/*
 main
 
 Copyright 2012 Thomas Dalling - http://tomdalling.com/
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include "platform.hpp"

// third-party libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// standard C++ libraries
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>

// tdogl classes
#include "Program.hpp"

// constants
const glm::vec2 SCREEN_SIZE(800, 600);

// globals
GLFWwindow* gWindow = nullptr;

GLuint gVAO = 0;
GLuint gVBO = 0;

GLuint Z_VAO = 0;
GLuint Z_EBO = 0;
GLuint Z_VBO = 0;





void OnError(int errorCode, const char* msg) {
    throw std::runtime_error(msg);
}

void initWindows(){
    //initialise GLFW
    glfwSetErrorCallback(OnError);
    
    if (!glfwInit()) {
        throw std::runtime_error("init failed");
    }
    
    // open a windows with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    gWindow = glfwCreateWindow((int)SCREEN_SIZE.x , (int)SCREEN_SIZE.y , "ZHULING" , NULL , NULL);
    
    if (!gWindow) {
        throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    }
    
    glfwMakeContextCurrent(gWindow);
    
}

void initGlew(){
    // todo
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("glewInit failed");
    }
    
    // print out some info about the graphics drivers
    std::cout << "OpenGL version is " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version is " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Graphics card vendor is " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer is " << glGetString(GL_RENDERER) << std::endl;
    
    // make sure OpenGL version 3.2 API is available
    if (!GLEW_VERSION_3_2) {
        throw std::runtime_error("OpenGL 3.2 API is not available");
    }
    
}


// the program starts here
void AppMain() {
    
    // initialise GLFW
    initWindows();
    
    initGlew();

    
    // run while the window is open
    while(!glfwWindowShouldClose(gWindow)){
        // process pending events
        glfwPollEvents();
        
    }
    
    // clean up and exit
    glfwTerminate();
}


int main(int argc, char *argv[]) {
    try {
        AppMain();
    } catch (const std::exception& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
