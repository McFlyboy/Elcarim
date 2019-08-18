#pragma once

#include <string>

#include <glm/glm.hpp>

#include "ShaderProgram.hpp"

namespace Elcarim::Graphics::Shading::Shaders {
	class Shader : public ShaderProgram {
	public:
		Shader(const std::string& shaderName);
		void set2DTransformation(glm::vec2& position, glm::vec2& scale, float& angle);
		void set2DView(glm::vec2& position, glm::vec2& scale, float& angle);
		void setOrthographicProjection(const float width, const float height, const float nearPlane, const float farPlane);
	private:
		int m_projectionLocation;
		int m_viewLocation;
		int m_transformationLocation;
	};
}
