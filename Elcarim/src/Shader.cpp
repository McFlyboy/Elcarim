#include "Shader.hpp"

#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Elcarim {
	namespace Graphics {
		namespace Shading {
			Shader::Shader(const std::string& shaderName) :
				ShaderProgram(shaderName),
				m_transformationLocation(registerUniformLocation("transformation")),
				m_projectionLocation(registerUniformLocation("projection"))
			{}
			void Shader::set2DTransformation(glm::vec2 position, glm::vec2 scale, float angle) {
				glm::mat3 transformation = glm::mat3(1.0f);
				transformation = glm::translate(transformation, position);
				transformation = glm::scale(transformation, scale);
				transformation = glm::rotate(transformation, glm::radians(angle));
				loadMat3(m_transformationLocation, transformation);
			}
			void Shader::setOrthographicProjection(const float width, const float height, const float nearPlane, const float farPlane) {
				loadMat4(m_projectionLocation, glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
			}
		}
	}
}
