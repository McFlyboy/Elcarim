#include "Shader.hpp"

#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer.hpp"

namespace Elcarim::Graphics::Shading {
	Shader::Shader(const std::string& shaderName) :
		ShaderProgram(shaderName),
		m_transformationLocation(registerUniformLocation("transformation")),
		m_viewLocation(registerUniformLocation("view")),
		m_projectionLocation(registerUniformLocation("projection"))
	{}
	void Shader::set2DTransformation(glm::vec2 position, glm::vec2 scale, float angle) {
		glm::mat3 transformation = glm::mat3(1.0f);
		transformation = glm::translate(transformation, position);
		transformation = glm::scale(transformation, scale);
		transformation = glm::rotate(transformation, glm::radians(angle));
		loadMat3(m_transformationLocation, transformation);
	}
	void Shader::set2DView(glm::vec2 position, glm::vec2 scale, float angle) {
		float radians = glm::radians(-angle);
		glm::mat3 positioningMatrix = glm::mat3(1.0f);
		positioningMatrix = glm::scale(positioningMatrix, scale);
		positioningMatrix = glm::rotate(positioningMatrix, radians);
		glm::mat3 view = glm::mat3(1.0f);
		view = glm::translate(view, (glm::vec2(positioningMatrix * glm::vec3(-position, 1.0f))));
		view = glm::scale(view, scale);
		view = glm::rotate(view, radians);
		loadMat3(m_viewLocation, view);
	}
	void Shader::setOrthographicProjection(const float width, const float height, const float nearPlane, const float farPlane) {
		loadMat4(m_projectionLocation, glm::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, nearPlane, farPlane));
	}
}
