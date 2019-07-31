#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderProgram.hpp"
#include "Model.hpp"
#include "Texture.hpp"

namespace Elcarim {
	namespace Graphics {
		class Renderer {
		public:
			Renderer(GLFWwindow* const window, const int width, const int height);
			void swapBuffers();
			void setVSync(const bool vsync);
			void setViewPort(const int width, const int height);
			void setWireframe(const bool wireframe);
			void setAlphaBlend(const bool alphablend);
			void clear();
			void setClearColor(const float red, const float green, const float blue);
			void setClearColor(const unsigned int color);
			void render(Model* model, Texture* texture);
			~Renderer();
		private:
			GLFWwindow* const m_window = nullptr;
			Shading::ShaderProgram* m_shader = nullptr;
		};
	}
}
