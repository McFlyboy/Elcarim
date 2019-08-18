#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Gamepad.hpp"

namespace Elcarim {
	class Window {
	public:
		const int getActiveMonitorWidth() const;
		const int getActiveMonitorHeight() const;
		const int getActiveMonitorRefreshRate() const;
		const bool shouldClose() const;
		void close();
		void center();
		void show();
		void setIconImages(const char* const smallx16, const char* const mediumx32, const char* const largex48);
		const bool isFocused() const;
		const bool isFullscreen() const;
		void setFullscreen(const bool fullscreen);
		void update();
		void updateFrame();
		Graphics::Renderer* const getRenderer() const;
		Input::Devices::Keyboard* const getKeyboard() const;
		Input::Devices::Mouse* const getMouse() const;
		Input::Devices::Gamepad* const getGamepad() const;
		const double getTime() const;
		const double getDeltaTime();
		~Window();
		static Window* const createInstance(const int width, const int height, const char* const title, const bool fullscreen);
	private:
		GLFWmonitor* m_activeMonitor = nullptr;
		const GLFWvidmode* m_monitorVideoMode = nullptr;
		GLFWwindow* m_window = nullptr;
		int m_width = 0;
		int m_height = 0;
		bool m_focused = false;
		Graphics::Renderer* m_renderer = nullptr;
		Input::Devices::Keyboard* m_keyboard = nullptr;
		Input::Devices::Mouse* m_mouse = nullptr;
		Input::Devices::Gamepad* m_gamepad = nullptr;
		static Window* s_instance;

		Window(const int width, const int height, const char* const title, const bool fullscreen);

		struct InternalTimer {
			int frameCount = 0;
			int updateCount = 0;
			int fps = 0;
			int ups = 0;
			double lastSecondTime = 0.0;
			double previousTime = 0.0;

			const double getTime() const;
			const double getDeltaTime();
			void updatePerSecCounters();
		};
		InternalTimer m_timer = InternalTimer();
	};
}
