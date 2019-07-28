#include <glad/glad.h>

#include "Model.hpp"

namespace Elcarim {
	namespace Graphics {
		Model::Model() {
			glGenVertexArrays(1, &vao);
			bind();
		}
		void Model::bind() {
			glBindVertexArray(vao);
		}
		const int Model::getVertexCount() const {
			return vertexCount;
		}
		void Model::addAttrib(const int index, const int size, const int dataLength, float* const data) {
			unsigned int vbo = 0;
			glGenBuffers(1, &vbo);
			vbos.push_back(vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * dataLength, data, GL_STATIC_DRAW);
			glVertexAttribPointer(index, size, GL_FLOAT, false, 0, nullptr);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			vertexCount = dataLength / size;
		}
		Model::~Model() {
			glDeleteBuffers(vbos.size(), vbos.data());
			glDeleteVertexArrays(1, &vao);
			unbind();
		}
		void Model::unbind() {
			glBindVertexArray(0);
		}
	}
}
