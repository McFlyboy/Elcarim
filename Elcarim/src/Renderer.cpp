#include <stdexcept>

#include "Renderer.hpp"

namespace Elcarim {
	namespace Graphics {
		Renderer::Renderer(GLFWwindow* const window, const int width, const int height) : m_window(window) {
			glfwMakeContextCurrent(window);
			if (!glfwGetCurrentContext()) {
				throw std::runtime_error("Failed to make context current for the window\n");
			}
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				throw std::runtime_error("Failed to load GLAD\n");
			}
			setViewPort(width, height);
		}
		void Renderer::swapBuffers() {
			glfwSwapBuffers(m_window);
		}
		void Renderer::setVSync(const bool vsync) {
			glfwSwapInterval(vsync);
		}
		void Renderer::setViewPort(const int width, const int height) {
			glViewport(0, 0, width, height);
		}
		void Renderer::setWireframe(const bool wireframe) {
			glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
		}
		void Renderer::clear() {
			glClear(GL_COLOR_BUFFER_BIT);
		}
		void Renderer::setClearColor(const float red, const float green, const float blue) {
			glClearColor(red, green, blue, 1.0f);
		}
		void Renderer::setClearColor(const unsigned int color) {
			setClearColor(
				static_cast<float>((color & 0xFF0000) >> 16) / 255.0f,
				static_cast<float>((color & 0xFF00) >> 8) / 255.0f,
				static_cast<float>(color & 0xFF) / 255.0f
			);
		}
		void Renderer::render(Model* model){
			model->bind();
			glEnableVertexAttribArray(0);
			glDrawArrays(GL_QUADS, 0, model->getVertexCount());
			glDisableVertexAttribArray(0);
			Model::unbind();
		}
	}
}
