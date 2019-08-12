#pragma once

#include <vector>

namespace Elcarim::Graphics {
	class Model {
	public:
		Model();
		void bind();
		const int getVertexCount() const;
		void set2DVertices(const int dataLength, float* const data);
		void set3DVertices(const int dataLength, float* const data);
		void setTextureCoords(const int dataLength, float* const data);
		~Model();
		static void unbind();
	private:
		unsigned int vao = 0;
		std::vector<unsigned int> vbos = std::vector<unsigned int>();
		int vertexCount = 0;

		void setVertices(const int size, const int dataLength, float* const data);
		void addAttrib(const int index, const int size, const int dataLength, float* const data);
	};
}
