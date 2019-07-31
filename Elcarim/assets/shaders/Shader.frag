#version 330 core

in vec2 passTextureCoord;

out vec4 color;

uniform sampler2D textureImg;

void main() {
	color = texture(textureImg, passTextureCoord);
}
