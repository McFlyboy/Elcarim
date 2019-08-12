#include <string>

#include <glm/glm.hpp>

namespace Elcarim::Graphics::Shading {
	class ShaderProgram {
	public:
		void startProgram() const;
		virtual ~ShaderProgram();
		static void stopProgram();
	protected:
		ShaderProgram(const std::string& shaderName);
		int registerUniformLocation(const char* const name);
		void loadInt(int location, int i);
		void loadFloat(int location, float f);
		void loadVec2(int location, const glm::vec2& vec);
		void loadVec3(int location, const glm::vec3& vec);
		void loadMat3(int location, const glm::mat3& mat);
		void loadMat4(int location, const glm::mat4& mat);
	private:
		unsigned int m_program = 0;

		const unsigned int compileShader(const std::string& filename, const unsigned int shaderType) const;
		void checkStatus(const unsigned int object, const unsigned int status, const std::string& errorMessage) const;
	};
}
