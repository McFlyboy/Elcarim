#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Shader.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "Color3.hpp"
#include "Color4.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"

namespace Elcarim::Graphics {
	class Renderer {
	public:
		static constexpr float ASPECT_RATIO = 16.0f / 9.0f;

		Renderer(GLFWwindow* const window, const int width, const int height);
		void swapBuffers();
		void setVSync(const bool vsync);
		void setViewPort(const int width, const int height);
		void setWireframe(const bool wireframe);
		void setAlphaBlend(const bool alphablend);
		void clear();
		void setClearColor(const Color3& color);
		void setClearColor(const Color4& color);
		void setCameraView(Objects::Camera* camera);
		void render(Objects::GameObject* object);
		~Renderer();
	private:
		GLFWwindow* const m_window = nullptr;
		Shading::Shaders::Shader* m_shader = nullptr;
	};
}
