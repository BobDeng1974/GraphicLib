//
//  Camera.hpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#ifndef Camera_hpp
#define Camera_hpp

#include "Entity.hpp"


namespace ze{
    
    class Camera : public Entity{
        
    public:
        
        Camera();
        ~Camera();
        
        static Camera * create();
        
        virtual bool init();
        
        glm::mat4 getViewMat();
        
        glm::mat4 getProjectionMat();
        
        glm::mat4 getViewProjectionMat();
        
        inline void setAspectRatio(float r){
            _viewportAspectRatio = r;
        }
        
        inline void setNearAndFarPlane(float n , float f){
            setNearPlane(n);
            setFarPlane(f);
        }
        
        bool initLookAt(glm::vec3 lookAt);
        
        glm::mat4 getCurDirectionMat();
        
        inline void offsetDirection(float verticalAngle , float horizontalAngle){
            _verticalAngle += verticalAngle;
            _horizontalAngle += horizontalAngle;
            normalizeAngle();
        }
        
        SYNTHESIZE(float , _nearPlane , NearPlane)
        
        SYNTHESIZE(float , _farPlane , FarPlane)
        
        SYNTHESIZE(float , _moveVelo , MoveVelo)

        glm::vec3 forward();
        
        glm::vec3 up();
        
        glm::vec3 right();
        
        inline void offsetPosition(glm::vec3 moveVec){
            _position += moveVec;
        }
        
        inline void setFieldOfView(float fov){
            if (fov > _maxFov) {
                _fieldOfView = _maxFov;
            }else if(fov < _minFov){
                _fieldOfView = _minFov;
            }
        }
        
    protected:
    
        inline void normalizeAngle(){
            _horizontalAngle = fmodf(_horizontalAngle, 360.0f);
            //fmodf can return negative values, but this will make them all positive
            if(_horizontalAngle < 0.0f){
                _horizontalAngle += 360.0f;
            }
            
            if(_verticalAngle > _maxPitch){
                _verticalAngle = _maxPitch;
            }
            else if(_verticalAngle < -_maxPitch){
                _verticalAngle = -_maxPitch;
            }
        }
        
        glm::vec3 _lookAt;
        
        float _verticalAngle;
        
        float _horizontalAngle;
        
        float _maxPitch;
        
        
        // base of angle (horizontal)
        float _fieldOfView;
        
        float _maxFov;
        
        float _minFov;
        
        // width / height
        float _viewportAspectRatio;
    };
    
}

#endif /* Camera_hpp */
