#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Elcarim {
	namespace Graphics {
		class Renderer {
		public:
			Renderer(GLFWwindow* const window, const int width, const int height);
			void setViewPort(const int width, const int height);
			void setVSync(const bool vsync);
			void clear();
			void setClearColor(const float red, const float green, const float blue);
		};
	}
}
