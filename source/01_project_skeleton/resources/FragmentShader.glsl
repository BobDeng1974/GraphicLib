#version 150
/*
 FragmentShader.glsl
 opengl-series
 
 Created by SATAN_Z on 16/6/27.
 
 */

uniform sampler2D tex;

in vec2 texFragment;

out vec4 finalColor;

void main(){
    
    vec4 black = vec4(0,0,0,1);
    
    finalColor = mix(texture(tex , texFragment) , black , 0.1);
    
}