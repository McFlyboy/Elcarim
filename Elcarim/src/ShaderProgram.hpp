#include <string>

namespace Elcarim {
	namespace Graphics {
		namespace Shading {
			class ShaderProgram {
			public:
				ShaderProgram(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);
				void startProgram() const;
				~ShaderProgram();
				static void stopProgram();
			private:
				unsigned int m_program = 0;

				const unsigned int compileShader(const std::string& filename, const unsigned int shaderType) const;
				void checkStatus(const unsigned int object, const unsigned int status, const std::string& errorMessage) const;
			};
		}
	}
}
