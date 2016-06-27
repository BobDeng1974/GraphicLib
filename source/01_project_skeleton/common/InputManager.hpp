//
//  InputManager.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/27.
//
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include "Ref.hpp"
#include "Macro.h"
#include "glm/glm.hpp"

namespace ze {
    
    /**
     handle input logic , keyboard and mouse
     */
    class InputManager : public Ref{
        
    public:
        // 鼠标灵敏度
        SYNTHESIZE(float , _mouseSensitivity , MouseSensitivity);

        InputManager();
        ~InputManager();
        
        void update(float dt);
        
        void onMouseEvent(float dt);
        
        void onKeyEvent(float dt);
        
        int isPress(int key);
        
        glm::vec2 getCursorPos();
        
        void setCursorPos(float x , float y);
        
    protected:
        
        
    };
    
}

#endif /* InputManager_hpp */
