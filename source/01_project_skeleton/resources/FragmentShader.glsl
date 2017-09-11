#version 150
/*
 FragmentShader.glsl
 opengl-series
 
 Created by SATAN_Z on 16/6/27.
 
 */

uniform sampler2D tex;

uniform struct Light {
    //光源位置
    vec3 position;
    //光源颜色
    vec3 intensities;
} light;



uniform struct Camera{
    vec3 position;
    vec3 dir;
} camera;


in vec3 fragPos;
in vec2 fragTexCoor;
in vec3 Normal;

out vec4 finalColor;

void main(){
    
    float ambient = 0.2f;
    
    vec4 objectColor = texture(tex , fragTexCoor);
    
//    vec4 objectColor = vec4(vec3(1.0 - texture(tex , fragTexCoor)) , 1.0);

//    float v = 0.299 * objectColor.r + 0.587 * objectColor.g + 0.114 * objectColor.b;
    
    
    vec3 lightDir = normalize(light.position - fragPos);
    
    float cosTheta = max(dot(Normal , lightDir) , 0);
    
    vec3 diffuse = cosTheta * light.intensities;
    
    
    vec3 fragToCamera = normalize(camera.position - fragPos);
    // 光的反射向量
    vec3 reflectVec = reflect(-lightDir , Normal);
    
    // 物体的反光程度 详情请绘制曲线
    float spec = pow(max(dot(reflectVec , fragToCamera) , 0.0) , 64);
    // 高光强度系数
    float specularFactor = 1.95;
    
    vec3 specular = spec * light.intensities * specularFactor;
    
    finalColor = vec4(objectColor.rgb * (ambient + specular ) , objectColor.a);
    
}


























