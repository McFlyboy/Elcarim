#include <fstream>
#include <stdexcept>

#include <glad/glad.h>

#include "ErrorHandler.hpp"
#include "ShaderProgram.hpp"

namespace Elcarim {
	namespace Graphics {
		namespace Shading {
			ShaderProgram::ShaderProgram(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename) {
				m_vertexShader = compileShader(vertexShaderFilename, GL_VERTEX_SHADER);
				m_fragmentShader = compileShader(fragmentShaderFilename, GL_FRAGMENT_SHADER);
				m_program = glCreateProgram();
				glAttachShader(m_program, m_vertexShader);
				glAttachShader(m_program, m_fragmentShader);
				glLinkProgram(m_program);
				checkStatus(m_program, GL_LINK_STATUS, "Failed to link shader-program");
			}
			void ShaderProgram::startProgram() const {
				glUseProgram(m_program);
			}
			void ShaderProgram::stopProgram() {
				glUseProgram(0);
			}
			const unsigned int ShaderProgram::compileShader(const std::string& filename, const unsigned int shaderType) const {
				std::string filepath = "assets/shaders/" + filename;
				std::ifstream file(filepath);
				if (!file) {
					throw std::runtime_error("Could not open the file: " + filepath);
				}
				std::string sourceCode;
				std::string line;
				while (std::getline(file, line)) {
					sourceCode += line + "\n";
				}
				unsigned int shader = glCreateShader(shaderType);
				const char* const constSourceCode = sourceCode.c_str();
				glShaderSource(shader, 1, &constSourceCode, nullptr);
				glCompileShader(shader);
				checkStatus(shader, GL_COMPILE_STATUS, "Failed to compile the shader: " + filepath);
				return shader;
			}
			void ShaderProgram::checkStatus(const unsigned int object, const unsigned int status, const std::string& errorMessage) const {
				int success;
				char infoLog[512];
				glGetShaderiv(object, status, &success);
				if (!success) {
					glGetShaderInfoLog(object, sizeof(infoLog), nullptr, infoLog);
					throw std::runtime_error(errorMessage + "\n" + infoLog);
				}
			}
			ShaderProgram::~ShaderProgram() {
				stopProgram();
				glDetachShader(m_program, m_vertexShader);
				glDetachShader(m_program, m_fragmentShader);
				glDeleteShader(m_vertexShader);
				glDeleteShader(m_fragmentShader);
				glDeleteProgram(m_program);
			}
		}
	}
}
