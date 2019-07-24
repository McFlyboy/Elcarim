#pragma once

#include <GLFW/glfw3.h>

#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Gamepad.hpp"

namespace Elcarim {
	class Window {
	public:
		const int getActiveMonitorWidth();
		const int getActiveMonitorHeight();
		const int getActiveMonitorRefreshRate();
		const bool shouldClose() const;
		void close();
		void center();
		void show();
		void setIconImages(const char* const smallx16, const char* const mediumx32, const char* const largex48);
		const bool isFocused() const;
		const bool isFullscreen() const;
		void setFullscreen(const bool fullscreen);
		void setVSync(const bool vsync);
		void updateEvents();
		void swapBuffers();
		Input::Device::Keyboard* const getKeyboard();
		Input::Device::Mouse* const getMouse();
		Input::Device::Gamepad* const getGamepad();
		~Window();
		static void setNewInstanceSettings(const int width, const int height, const char* const title = "", const bool fullscreen = false);
		static Window* const getInstance();
	private:
		GLFWmonitor* m_activeMonitor = nullptr;
		const GLFWvidmode* m_monitorVideoMode = nullptr;
		GLFWwindow* m_window = nullptr;
		int m_width = 0;
		int m_height = 0;
		bool m_focused = false;
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