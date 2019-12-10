#include "ShaderProgram.hpp"

#include <fstream>
#include <stdexcept>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include "ErrorHandler.hpp"

namespace Elcarim::Graphics::Shading {
	ShaderProgram::ShaderProgram(const std::string& shaderName) {
		const unsigned int vertexShader = compileShader(shaderName + ".vert", GL_VERTEX_SHADER);
		const unsigned int fragmentShader = compileShader(shaderName + ".frag", GL_FRAGMENT_SHADER);
		m_program = glCreateProgram();
		glAttachShader(m_program, vertexShader);
		glAttachShader(m_program, fragmentShader);
		glLinkProgram(m_program);
		glValidateProgram(m_program);
		glDetachShader(m_program, vertexShader);
		glDetachShader(m_program, fragmentShader);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		checkStatus(m_program, GL_LINK_STATUS, "Failed to link shader-program: " + shaderName);
	}
	void ShaderProgram::startProgram() const {
		glUseProgram(m_program);
	}
	void ShaderProgram::stopProgram() {
		glUseProgram(0);
	}
	int ShaderProgram::registerUniformLocation(const char* const name) {
		return glGetUniformLocation(m_program, name);
	}
	void ShaderProgram::loadInt(int location, int i) {
		glUniform1i(location, i);
	}
	void ShaderProgram::loadFloat(int location, float f) {
		glUniform1f(location, f);
	}
	void ShaderProgram::loadVec2(int location, const glm::vec2& vec) {
		glUniform2f(location, vec.x, vec.y);
	}
	void ShaderProgram::loadVec3(int location, const glm::vec3& vec) {
		glUniform3f(location, vec.x, vec.y, vec.z);
	}
	void ShaderProgram::loadMat3(int location, const glm::mat3& mat) {
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}
	void ShaderProgram::loadMat4(int location, const glm::mat4& mat) {
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
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
		glGetShaderiv(object, status, &success);
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(object, sizeof(infoLog), nullptr, infoLog);
			throw std::runtime_error(errorMessage + "\n" + infoLog);
		}
	}
	ShaderProgram::~ShaderProgram() {
		stopProgram();
		glDeleteProgram(m_program);
	}
}
