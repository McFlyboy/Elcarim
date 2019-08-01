#version 330 core

layout (location = 0) in vec2 vertex;
layout (location = 1) in vec2 textureCoord;

out vec2 passTextureCoord;

uniform mat3 transformation;

void main(){
	gl_Position = vec4((transformation * vec3(vertex, 1.0)).xy, 0.0, 1.0);
	passTextureCoord = textureCoord;
}
