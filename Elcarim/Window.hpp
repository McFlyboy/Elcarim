#pragma once

#include <GLFW/glfw3.h>

#include "Keyboard.hpp"

namespace Elcarim {
	class Window {
	public:
		const bool shouldClose() const;
		void center();
		void setVSync(const bool vsync);
		void update();
		const Input::Device::Keyboard* const createKeyboard();
		~Window();
		static void setNewInstanceSettings(const int width, const int height, const char* const title = "", const bool fullscreen = false);
		static Window* getInstance();
	private:
		GLFWmonitor* m_activeMonitor = nullptr;
		const GLFWvidmode* m_monitorVideoMode = nullptr;
		GLFWwindow* m_window = nullptr;
		int m_width = 0;
		int m_height = 0;
		static int s_newInstanceWidth;
		static int s_newInstanceHeight;
		static const char* s_newInstanceTitle;
		static bool s_newInstanceFullscreen;
		static Window* s_instance;

		Window();
	};
}
