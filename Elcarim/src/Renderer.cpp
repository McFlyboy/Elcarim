#include <stdexcept>

#include <glm/glm.hpp>

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
			m_shader = new Shading::Shader("Shader");
			m_shader->startProgram();
			m_shader->setOrthographicProjection(16.0f, 9.0f, 0.1f, 100.0f);
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
		void Renderer::setAlphaBlend(const bool alphablend) {
			if (alphablend) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
			else {
				glDisable(GL_BLEND);
			}
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
		void Renderer::render(Model* model, Texture* texture, Objects::GameObject& object){
			model->bind();
			glActiveTexture(GL_TEXTURE0);
			texture->bind();
			m_shader->set2DTransformation(object.getPosition(), object.getScale(), object.getAngle());
			glDrawArrays(GL_TRIANGLES, 0, model->getVertexCount());
			Texture::unbind();
			Model::unbind();
		}
		Renderer::~Renderer() {
			delete m_shader;
			m_shader = nullptr;
		}
	}
}
