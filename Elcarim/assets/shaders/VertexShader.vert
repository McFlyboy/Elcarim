#version 330 core

layout (location = 0) in vec2 vertex;
layout (location = 1) in vec2 textureCoord;

out vec2 passTextureCoord;

void main(){
	gl_Position = vec4(vertex.x * 9.0/16.0, vertex.y, 0.0, 1.0);
	passTextureCoord = textureCoord;
}
