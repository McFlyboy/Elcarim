#include "Model.hpp"

#include <glad/glad.h>

namespace Elcarim::Graphics {
	Model::Model() {
		glGenVertexArrays(1, &m_vao);
		bind();
	}
	void Model::bind() const {
		glBindVertexArray(m_vao);
	}
	const int Model::getIndexCount() const {
		return m_indexCount;
	}
	void Model::setIndices(const int dataLength, const unsigned int* const data) {
		glGenBuffers(1, &m_ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * dataLength, data, GL_STATIC_DRAW);
		m_indexCount = dataLength;
	}
	void Model::set2DVertices(const int dataLength, const float* const data) {
		setVertices(2, dataLength, data);
	}
	void Model::set3DVertices(const int dataLength, const float* const data) {
		setVertices(3, dataLength, data);
	}
	void Model::setTextureCoords(const int dataLength, const float* const data) {
		addAttrib(1, 2, dataLength, data);
	}
	void Model::setVertices(const int size, const int dataLength, const float* const data) {
		addAttrib(0, size, dataLength, data);
	}
	void Model::addAttrib(const int index, const int size, const int dataLength, const float* const data) {
		unsigned int vbo = 0;
		glGenBuffers(1, &vbo);
		m_vbos.push_back(vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * dataLength, data, GL_STATIC_DRAW);
		glVertexAttribPointer(index, size, GL_FLOAT, false, 0, nullptr);
		glEnableVertexAttribArray(index);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	Model::~Model() {
		glDeleteBuffers(m_vbos.size(), m_vbos.data());
		glDeleteVertexArrays(1, &m_vao);
		unbind();
	}
	void Model::unbind() {
		glBindVertexArray(0);
	}
}
