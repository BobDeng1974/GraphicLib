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
#include "Program.h"

// constants
const glm::vec2 SCREEN_SIZE(800, 600);

// globals
GLFWwindow* gWindow = nullptr;
tdogl::Program* gProgram = nullptr;
GLuint gVAO = 0;
GLuint gVBO = 0;

GLuint Z_VAO = 0;
GLuint Z_EBO = 0;
GLuint Z_VBO = 0;

static void loadPolygon(){
    // generate a VAO and bind
    glGenVertexArrays(1 , &Z_VAO);
    glBindVertexArray(Z_VAO);
    
    
    glGenBuffers(1 , &Z_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , Z_EBO);
    GLuint indices[] = {
        0 , 1 , 3 ,
        1 , 2 , 3
    };
    glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(indices), indices , GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0);
    
    // generate a VBO and bind
    glGenBuffers(1 , &Z_VBO);
    glBindBuffer(GL_ARRAY_BUFFER , Z_VBO);
    
    GLfloat vertice[] = {
        // x , y ,z
        0.5 , 0.5 , 0 ,
        0.5 , -0.5 , 0 ,
        -0.5 , -0.5 , 0 ,
        -0.5 , 0.5 , 0
    };
    glBufferData(GL_ARRAY_BUFFER , sizeof(vertice) , vertice , GL_STATIC_DRAW);
    
    
    glEnableVertexAttribArray(gProgram->attrib("vert1"));
    glVertexAttribPointer(gProgram->attrib("vert1"), 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, NULL);
    // unbind VBO
    glBindBuffer(GL_ARRAY_BUFFER , 0);
    // unbind VAO
    glBindVertexArray(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    
    // generate a EBO and bind (element buffer object)
    //    glGenBuffers(1 , &Z_EBO);
    //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , Z_EBO);
    //    GLuint indices[] = {
    //        0 , 1 , 3 ,
    //        1 , 2 , 3
    //    };
    //    glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(indices), indices , GL_STATIC_DRAW);
    //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0);
}


// loads the vertex shader and fragment shader, and links them to make the global gProgram
static void LoadShaders() {
    std::vector<tdogl::Shader> shaders;
    shaders.push_back(tdogl::Shader::shaderFromFile(ResourcePath("vertex-shader.txt"), GL_VERTEX_SHADER));
    shaders.push_back(tdogl::Shader::shaderFromFile(ResourcePath("fragment-shader.txt"), GL_FRAGMENT_SHADER));
    gProgram = new tdogl::Program(shaders);
}

static void renderPolygon(){
    // clear everything
    glClearColor(0 , 0, 0, 1);
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(gProgram->object());
    
    glBindVertexArray(Z_VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Z_EBO);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    //    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    // unbind the VAO
    glBindVertexArray(0);
    
    // unbind the program
    glUseProgram(0);
    
    // swap the display buffers (displays what was just drawn)
    glfwSwapBuffers(gWindow);
}

// loads a triangle into the VAO global
static void LoadTriangle() {
    // make and bind the VAO
    glGenVertexArrays(1, &gVAO);
    glBindVertexArray(gVAO);
    
    // make and bind the VBO
    glGenBuffers(1, &gVBO);
    glBindBuffer(GL_ARRAY_BUFFER, gVBO);
    
    // Put the three triangle verticies into the VBO
    GLfloat vertexData[] = {
        //  X     Y     Z
        0.0f, 0.8f, 0.0f,
        -0.8f,-0.8f, 0.0f,
        0.8f,-0.8f, 0.0f,
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(gProgram->attrib("vert1"));
    glVertexAttribPointer(gProgram->attrib("vert1"), 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, NULL);
    
    // unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


// draws a single frame
static void Render() {
    // clear everything
    glClearColor(0, 0, 0, 1); // black
    glClear(GL_COLOR_BUFFER_BIT);
    
    // bind the program (the shaders)
    glUseProgram(gProgram->object());
    
    // bind the VAO (the triangle)
    glBindVertexArray(gVAO);
    
    // draw the VAO
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    // unbind the VAO
    glBindVertexArray(0);
    
    // unbind the program
    glUseProgram(0);
    
    // swap the display buffers (displays what was just drawn)
    glfwSwapBuffers(gWindow);
}

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
    
    // load vertex and fragment shaders into opengl
    LoadShaders();
    
    // create buffer and fill it with the points of the triangle
    //    LoadTriangle();
    
    loadPolygon();
    
    // run while the window is open
    while(!glfwWindowShouldClose(gWindow)){
        // process pending events
        glfwPollEvents();
        
        // draw one frame
        //        Render();
        renderPolygon();
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
