#pragma once

#include <vector>

namespace Elcarim::Graphics {
	class Model {
	public:
		Model();
		void bind() const;
		const int getIndexCount() const;
		void setIndices(const int dataLength, const unsigned int* const data);
		void set2DVertices(const int dataLength, const float* const data);
		void set3DVertices(const int dataLength, const float* const data);
		void setTextureCoords(const int dataLength, const float* const data);
		~Model();
		static void unbind();
	private:
		unsigned int m_vao = 0;
		unsigned int m_ibo = 0;
		std::vector<unsigned int> m_vbos = std::vector<unsigned int>();
		int m_indexCount = 0;

		void setVertices(const int size, const int dataLength, const float* const data);
		void addAttrib(const int index, const int size, const int dataLength, const float* const data);
	};
}
