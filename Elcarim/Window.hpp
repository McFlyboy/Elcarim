#pragma once

#include <GLFW/glfw3.h>

#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Gamepad.hpp"

namespace Elcarim {
	class Window {
	public:
		const bool shouldClose() const;
		void close();
		void center();
		const int getActiveMonitorWidth();
		const int getActiveMonitorHeight();
		const int getActiveMonitorRefreshRate();
		const bool isFullscreen() const;
		void setFullscreen(const bool fullscreen);
		void setVSync(const bool vsync);
		void update();
		Input::Device::Keyboard* const getKeyboard();
		Input::Device::Mouse* const getMouse();
		Input::Device::Gamepad* const getGamepad();
		~Window();
		static void setNewInstanceSettings(const int width, const int height, const char* const title = "", const bool fullscreen = false);
		static Window* getInstance();
	private:
		GLFWmonitor* m_activeMonitor = nullptr;
		const GLFWvidmode* m_monitorVideoMode = nullptr;
		GLFWwindow* m_window = nullptr;
		int m_width = 0;
		int m_height = 0;
		Input::Device::Keyboard* m_keyboard = nullptr;
		Input::Device::Mouse* m_mouse = nullptr;
		Input::Device::Gamepad* m_gamepad = nullptr;
		static int s_newInstanceWidth;
		static int s_newInstanceHeight;
		static const char* s_newInstanceTitle;
		static bool s_newInstanceFullscreen;
		static Window* s_instance;

		Window();
	};
}
