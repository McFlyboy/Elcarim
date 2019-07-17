#pragma once

#include <GLFW/glfw3.h>

namespace Elcarim {
	class Window {
	public:
		~Window();
		static void setNewInstanceSettings();
		static Window* getInstance();
	private:
		GLFWmonitor* m_activeMonitor = nullptr;
		GLFWwindow* m_window = nullptr;
		static Window* s_instance;

		Window();
	};
}
