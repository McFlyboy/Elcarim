#include "Renderer.hpp"

#include <stdexcept>

#include <glm/glm.hpp>

#include "TexturedModelComponent.hpp"

namespace Elcarim {
	namespace Graphics {
		const float Renderer::ASPECT_RATION = 16.0f / 9.0f;
		const float Renderer::PROJECTION_RESOLUTION_WIDTH = 512.0f;
		const float Renderer::PROJECTION_RESOLUTION_HEIGHT = 288.0f;

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
			m_shader->setOrthographicProjection(PROJECTION_RESOLUTION_WIDTH, PROJECTION_RESOLUTION_HEIGHT, -1.0f, 1.0f);
		}
		void Renderer::swapBuffers() {
			glfwSwapBuffers(m_window);
		}
		void Renderer::setVSync(const bool vsync) {
			glfwSwapInterval(vsync);
		}
		void Renderer::setViewPort(const int width, const int height) {
			float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
			int aspectFixX = 0;
			int aspectFixY = 0;
			int aspectFixWidth = 0;
			int aspectFixHeight = 0;
			if (aspectRatio == ASPECT_RATION) {
				aspectFixX = 0;
				aspectFixY = 0;
				aspectFixWidth = width;
				aspectFixHeight = height;
			}
			else if (aspectRatio < ASPECT_RATION) {
				int heightOffset = height / 2 - 9 * width / 32;
				aspectFixX = 0;
				aspectFixY = heightOffset;
				aspectFixWidth = width;
				aspectFixHeight = height - heightOffset * 2;
			}
			else {
				int widthOffset = width / 2 - 8 * height / 9;
				aspectFixX = widthOffset;
				aspectFixY = 0;
				aspectFixWidth = width - widthOffset * 2;
				aspectFixHeight = height;
			}
			glViewport(aspectFixX, aspectFixY, aspectFixWidth, aspectFixHeight);
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
		void Renderer::render(Objects::GameObject* object){
			auto texturedModel = object->getFirstComponentOfType<Objects::Components::TexturedModelComponent>();
			if (!texturedModel) {
				return;
			}
			Model* model = texturedModel->getModel();
			Texture* texture = texturedModel->getTexture();
			model->bind();
			glActiveTexture(GL_TEXTURE0);
			texture->bind();
			m_shader->set2DTransformation(object->getTransformation().getPosition(), object->getTransformation().getScale(), object->getTransformation().getAngle());
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
