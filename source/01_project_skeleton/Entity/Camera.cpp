//
//  Camera.cpp
//  opengl-series
//
//  Created by SATAN_Z on 16/6/24.
//
//

#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

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
_viewportAspectRatio(4 / 3.0f),
_moveVelo(0.07),
_lookAt(0 , 0 , -1),
_headVec(0 , 1 , 0){
    
}

Camera::~Camera(){
    
}

glm::mat4 Camera::getCurDirectionMat() const{
    glm::mat4 ret;
    ret = glm::rotate(ret , glm::radians(_verticalAngle) , glm::vec3(1,0,0));
    ret = glm::rotate(ret , glm::radians(_horizontalAngle) , glm::vec3(0,1,0));
    return ret;
}

glm::vec3 Camera::forward(){
    glm::vec4 temp = glm::inverse(getCurDirectionMat()) * glm::vec4(0,0,-1,1);
    return glm::vec3(temp);
}

glm::vec3 Camera::up(){
    glm::vec4 temp = glm::inverse(getCurDirectionMat()) * glm::vec4(0,1,0,1);
    return glm::vec3(temp);
}

glm::vec3 Camera::right(){
    glm::vec4 temp = glm::inverse(getCurDirectionMat()) * glm::vec4(1,0,0,1);
    return glm::vec3(temp);
}

bool Camera::initLookAt(glm::vec3 lookAt){
    assert(lookAt != _position);
    glm::vec3 direction = glm::normalize(lookAt - _position);
    _verticalAngle = TO_ANGLE(atan(direction.y / direction.z));
    _horizontalAngle = TO_ANGLE(atan2f(direction.x , - direction.z));
    _normalizeAngle();
    return true;
}

glm::mat4 Camera::getViewMat() const{
    return getCurDirectionMat() * glm::translate(glm::mat4(), -_position);
}

glm::mat4 Camera::getProjectionMat() const{
    return glm::perspective(glm::radians(_fieldOfView) , _viewportAspectRatio , _nearPlane , _farPlane);
}

glm::mat4 Camera::getViewProjectionMat() const{
    return getProjectionMat() * getViewMat();
}

bool Camera::init(){
    return true;
}

