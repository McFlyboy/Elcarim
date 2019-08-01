#include <glm/gtx/matrix_transform_2d.hpp>

#include "Shader.hpp"

namespace Elcarim {
	namespace Graphics {
		namespace Shading {
			Shader::Shader(const std::string& shaderName) :
				ShaderProgram(shaderName),
				m_transformationLocation(registerUniformLocation("transformation"))
			{}
			void Shader::set2DTransformation(glm::vec2 position, glm::vec2 scale, float angle) {
				glm::mat3 transformation = glm::mat3(1.0f);
				transformation = glm::translate(transformation, position);
				transformation = glm::scale(transformation, scale);
				transformation = glm::rotate(transformation, glm::radians(angle));
				loadMat3(m_transformationLocation, transformation);
			}
		}
	}
}
