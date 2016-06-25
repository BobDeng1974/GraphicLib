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

namespace zdogl {
    
    void OnError(int errorCode, const char* msg) {
        throw std::runtime_error(msg);
    }
    
    class Window : public Object {
        
        Window();
        ~Window();
        
        SYNTHESIZE(GLfloat , _width , Width)
        
        SYNTHESIZE(GLfloat , _height , Height)
        
        SYNTHESIZE(std::string , _title , Title)
        
        SYNTHESIZE(float , _mouseSensitivity , MouseSensitivity)
        
        
        
        virtual bool init();
        
        //todo 键盘事件  鼠标事件
        
        /**
         getter and setter for frame per second
         */
        SYNTHESIZE(double , _fps , FramePerSecond)
        
        void update(float dt);
        
        inline void setCurSorPos(double x , double y){
            glfwSetCursorPos(_GLFWwindow , x , y);
        }
        
        inline glm::vec2 getCurSorPos(){
            double x , y;
            glfwGetCursorPos(_GLFWwindow , &x , &y);
            return glm::vec2(x , y);
        }
        
    private:
        
        bool initGlfw();
        
        bool initGlew();
        
        GLFWwindow * _GLFWwindow;
        
    };
    
}


#endif /* Window_hpp */
