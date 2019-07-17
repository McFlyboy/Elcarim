#pragma once

#include <GLFW/glfw3.h>

namespace Elcarim {
	class Window {
	public:
		const bool shouldClose() const;
		void center();
		void update();
		~Window();
		static void setNewInstanceSettings(int width, int height, const char* const& title = "", bool fullscreen = false);
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
