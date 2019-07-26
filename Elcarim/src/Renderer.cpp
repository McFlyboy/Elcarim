#include <stdexcept>

#include "Renderer.hpp"

namespace Elcarim {
	namespace Graphics {
		Renderer::Renderer(GLFWwindow* const window) {
			glfwMakeContextCurrent(window);
			if (!glfwGetCurrentContext()) {
				throw std::runtime_error("Failed to make context current for the window\n");
			}
		}
		void Renderer::setVSync(const bool vsync) {
			glfwSwapInterval(vsync);
		}
		void Renderer::clear() {
			glClear(GL_COLOR_BUFFER_BIT);
		}
		void Renderer::setClearColor(const float red, const float green, const float blue) {
			glClearColor(red, green, blue, 1.0f);
		}
	}
}
