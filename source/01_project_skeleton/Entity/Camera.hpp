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

    /**
     A first-person shooter type of camera.
     
     Set the properties of the camera, then use the `matrix` method to get the camera matrix for
     use in the vertex shader.
     
     Includes the perspective projection matrix.
     */
    class Camera : public Entity{
        
    public:
        
        Camera();
        ~Camera();
        
        static Camera * create();
        
        virtual bool init();
        
        glm::mat4 getViewMat() const;
        
        glm::mat4 getProjectionMat() const;
        
        /**
         The combined camera transformation matrix, including perspective projection.
         
         This is the complete matrix to use in the vertex shader.
         */
        glm::mat4 getViewProjectionMat() const;
        
        inline void setAspectRatio(float r){
            _viewportAspectRatio = r;
        }
        
        inline void setNearAndFarPlane(float n , float f){
            setNearPlane(n);
            setFarPlane(f);
        }
        
        bool initLookAt(glm::vec3 lookAt);
        
        
        glm::mat4 getCurDirectionMat() const;
        
        inline void offsetDirection(float verticalAngle , float horizontalAngle){
            _verticalAngle += verticalAngle;
            _horizontalAngle += horizontalAngle;
            _normalizeAngle();
        }
        
        inline float getNearPlane(){
            return _nearPlane;
        }
        
        inline void setNearPlane(float val){
            _nearPlane = val;
        }
        
        inline float getFarPlane(){
            return _farPlane;
        }
        
        inline void setFarPlane(float val){
            _farPlane = val;
        }
        
        inline void setMoveVelo(float val){
            _moveVelo = val;
        }
        
        inline float getMoveVelo(){
            return _moveVelo;
        }

        /** 
         A unit vector representing the direction the camera is facing in world coordinate system
         */
        glm::vec3 forward();
        
        /**
         A unit vector representing the direction out of the top of the camera in world coordinate system
         */
        glm::vec3 up();
        
        /** 
         A unit vector representing the direction to the right of the camera in world coordinate system
         */
        glm::vec3 right();
        
        inline void offsetPosition(glm::vec3 moveVec){
            _position += moveVec;
        }
        
        /**
         The vertical viewing angle of the camera, in degrees.
         
         Determines how "wide" the view of the camera is. Large angles appear to be zoomed out,
         as the camera has a wide view. Small values appear to be zoomed in, as the camera has a
         very narrow view.
         
         The value must be between 0 and 180.
         */
        inline float getFieldOfView(){
            return _fieldOfView;
        }
        
        inline void setFieldOfView(float fov){
            if (fov > _maxFov) {
                _fieldOfView = _maxFov;
            }else if(fov < _minFov){
                _fieldOfView = _minFov;
            }
        }
        
    protected:
    
        inline void _normalizeAngle(){
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
        
        /**
         mean head vector
         */
        glm::vec3 _headVec;
        
        float _verticalAngle;
        
        float _horizontalAngle;
        
        float _maxPitch;
        
        float _nearPlane;
        
        float _farPlane;
        
        float _moveVelo;
        
        
        // base of angle (horizontal)
        float _fieldOfView;
        
        float _maxFov;
        
        float _minFov;
        
        // width / height
        float _viewportAspectRatio;
    };
    
}

#endif /* Camera_hpp */
