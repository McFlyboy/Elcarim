#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Shader.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"

namespace Elcarim::Graphics {
	class Renderer {
	public:
		static const float ASPECT_RATION;

		Renderer(GLFWwindow* const window, const int width, const int height);
		void swapBuffers();
		void setVSync(const bool vsync);
		void setViewPort(const int width, const int height);
		void setWireframe(const bool wireframe);
		void setAlphaBlend(const bool alphablend);
		void clear();
		void setClearColor(const float red, const float green, const float blue);
		void setClearColor(const unsigned int color);
		void setCameraView(Objects::Camera* camera);
		void render(Objects::GameObject* object);
		~Renderer();
	private:
		GLFWwindow* const m_window = nullptr;
		Shading::Shaders::Shader* m_shader = nullptr;
	};
}
