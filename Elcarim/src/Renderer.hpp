#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "GameObject.hpp"

namespace Elcarim {
	namespace Graphics {
		class Renderer {
		public:
			static const float ASPECT_RATION;
			static const float PROJECTION_RESOLUTION_WIDTH;
			static const float PROJECTION_RESOLUTION_HEIGHT;

			Renderer(GLFWwindow* const window, const int width, const int height);
			void swapBuffers();
			void setVSync(const bool vsync);
			void setViewPort(const int width, const int height);
			void setWireframe(const bool wireframe);
			void setAlphaBlend(const bool alphablend);
			void clear();
			void setClearColor(const float red, const float green, const float blue);
			void setClearColor(const unsigned int color);
			void render(Objects::GameObject* object);
			~Renderer();
		private:
			GLFWwindow* const m_window = nullptr;
			Shading::Shader* m_shader = nullptr;
		};
	}
}
