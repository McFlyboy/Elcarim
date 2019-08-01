#include <string>

#include <glm/glm.hpp>

namespace Elcarim {
	namespace Graphics {
		namespace Shading {
			class ShaderProgram {
			public:
				ShaderProgram(const std::string& shaderName);
				void startProgram() const;
				virtual ~ShaderProgram();
				static void stopProgram();
			protected:
				int registerUniformLocation(const char* const name);
				void loadInt(int location, int i);
				void loadFloat(int location, float f);
				void loadVec2(int location, glm::vec2 vec);
				void loadVec3(int location, glm::vec3 vec);
				void loadMat3(int location, glm::mat3 mat);
				void loadMat4(int location, glm::mat4 mat);
			private:
				unsigned int m_program = 0;

				const unsigned int compileShader(const std::string& filename, const unsigned int shaderType) const;
				void checkStatus(const unsigned int object, const unsigned int status, const std::string& errorMessage) const;
			};
		}
	}
}
