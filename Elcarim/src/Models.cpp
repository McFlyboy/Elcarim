#include "Models.hpp"

namespace Elcarim::Util {
	Graphics::Model* const Models::createSquareModel() {
		float vertices[] = {
		-1.0f, -1.0f,
		 1.0f, -1.0f,
		 1.0f,  1.0f,
		-1.0f, -1.0f,
		 1.0f,  1.0f,
		-1.0f,  1.0f
		};
		float textureCoords[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
		};
		Graphics::Model* square = new Graphics::Model();
		square->set2DVertices(sizeof(vertices) / sizeof(float), vertices);
		square->setTextureCoords(sizeof(textureCoords) / sizeof(float), textureCoords);
		Graphics::Model::unbind();
		return square;
	}
}
