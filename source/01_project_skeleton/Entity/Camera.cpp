//
//  Camera.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Camera.hpp"

using namespace ze;

Camera::Camera():
_horizontalAngle(0),
_verticalAngle(0),
_maxFov(130),
_minFov(20),
_farPlane(100),
_nearPlane(1),
_fieldOfView(50),
_maxPitch(80),
_viewportAspectRatio(0.75f),
_moveVelo(0.1){
    
}

Camera::~Camera(){
    
}

glm::mat4 Camera::getCurDirectionMat(){
    
}

glm::mat4 Camera::getViewMat(){
    
}

glm::mat4 Camera::getProjectionMat(){
    
}

bool Camera::init(){
    return true;
}

glm::vec3 Camera::forward(){
    
}

glm::vec3 Camera::up(){
    
}

glm::vec3 Camera::right(){
    
}

bool Camera::initLookAt(glm::vec3 lookAt){
    assert(lookAt != _position);
    
}