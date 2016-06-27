/*
 FragmentShader.glsl
 opengl-series
 
 Created by SATAN_Z on 16/6/27.
 
 */

uniform sampler2D tex;

in vec2 texFragment;

out vec4 finalColor;

void main(){
    
    finalColor = texture(tex , texFragment);
    
}