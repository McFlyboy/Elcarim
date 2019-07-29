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
		void Model::set2DVertices(const int dataLength, float* const data) {
			setVertices(2, dataLength, data);
		}
		void Model::set3DVertices(const int dataLength, float* const data) {
			setVertices(3, dataLength, data);
		}
		void Model::setVertices(const int size, const int dataLength, float* const data) {
			addAttrib(0, size, dataLength, data);
			vertexCount = dataLength / size;
		}
		void Model::addAttrib(const int index, const int size, const int dataLength, float* const data) {
			unsigned int vbo = 0;
			glGenBuffers(1, &vbo);
			vbos.push_back(vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * dataLength, data, GL_STATIC_DRAW);
			glVertexAttribPointer(index, size, GL_FLOAT, false, 0, nullptr);
			glEnableVertexAttribArray(index);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
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
