//
//  Window.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>

#include "Object.hpp"
#include <GLFW/glfw3.h>
#include "Macro.h"
#include "glm/glm.hpp"
#include "InputManager.hpp"

namespace zdogl {
    
    class Window : public Object {
        
    public:
        
        Window();
        
        ~Window();
        
        SYNTHESIZE(GLfloat , _width , Width)
        
        SYNTHESIZE(GLfloat , _height , Height)
        
        SYNTHESIZE(std::string , _title , Title)
        
//        SYNTHESIZE(float , _mouseSensitivity , MouseSensitivity)
        
        void swapBuffer();
        
        void pollEvent();
        
        inline void terminate(){
            glfwTerminate();
        }
        
        inline void close(){
            glfwSetWindowShouldClose(_GLFWwindow , GL_TRUE);
        }
        
        inline int shouldClose(){
            return glfwWindowShouldClose(_GLFWwindow);
        }
        
        virtual bool init();
        
        inline double getCurTime(){
            return glfwGetTime();
        }
        
        //todo 键盘事件  鼠标事件
        
        /**
         getter and setter for frame per second
         */
        SYNTHESIZE(double , _fps , FramePerSecond)
        
        void update(float dt);
        
        inline int isPress(int key){
            return glfwGetKey(_GLFWwindow , key);
        }
        
        inline void setCursorPos(double x , double y){
            glfwSetCursorPos(_GLFWwindow , x , y);
        }
        
        inline glm::vec2 getCursorPos(){
            double x , y;
            glfwGetCursorPos(_GLFWwindow , &x , &y);
            return glm::vec2(x , y);
        }
        
    private:
        
        bool initGlfw();
        
        bool initGlew();
        
        ze::InputManager * _inputManager;
        
        GLFWwindow * _GLFWwindow;
        
    };
    
}


#endif /* Window_hpp */
