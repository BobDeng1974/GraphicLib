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

// view transform (with camera)
uniform mat4 view;

// projection transform
uniform mat4 projection;

// model transform
uniform mat4 model;

void main(){
    
    texFragment = texCoor;
    
    gl_Position = projection * view * model * vec4(vertex , 1);
    
}