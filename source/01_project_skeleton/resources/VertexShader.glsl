#version 150
/*
  VertexShader.glsl
  opengl-series

  Created by SATAN_Z on 16/6/27.

*/

// vertex coordinate
in vec3 vertex;

//texture coordinate
in vec2 texCoor;

out vec2 texFragment;

//// view transform (with camera)
//uniform mat4 view;

// projection transform
uniform mat4 VxP;

// model transform
//uniform mat4 model;

void main(){
    
    texFragment = texCoor;
    
    gl_Position = VxP * vec4(vertex , 1);
    
}