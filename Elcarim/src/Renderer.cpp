#include <stdexcept>

#include "Renderer.hpp"

namespace Elcarim {
	namespace Graphics {
		Renderer::Renderer(GLFWwindow* const window, const int width, const int height) {
			glfwMakeContextCurrent(window);
			if (!glfwGetCurrentContext()) {
				throw std::runtime_error("Failed to make context current for the window\n");
			}
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				throw std::runtime_error("Failed to load GLAD\n");
			}
			setViewPort(width, height);
		}
		void Renderer::setViewPort(const int width, const int height) {
			glViewport(0, 0, width, height);
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
