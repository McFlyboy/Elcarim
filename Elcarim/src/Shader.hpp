#pragma once

#include <string>

#include <glm/glm.hpp>

#include "ShaderProgram.hpp"

namespace Elcarim {
	namespace Graphics {
		namespace Shading {
			class Shader : public ShaderProgram {
			public:
				Shader(const std::string& shaderName);
				void set2DTransformation(glm::vec2 position, glm::vec2 scale, float angle);
				void setOrthographicProjection(const float width, const float height, const float nearPlane, const float farPlane);
			private:
				int m_projectionLocation;
				int m_transformationLocation;
			};
		}
	}
}
