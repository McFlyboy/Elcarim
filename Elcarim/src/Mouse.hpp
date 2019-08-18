#pragma once

#include <GLFW/glfw3.h>

namespace Elcarim::Input::Devices {
	class Mouse {
	public:
		Mouse(GLFWwindow* const window);
		void setCursorInvisible(const bool invisible);
		~Mouse();
	private:
		GLFWwindow* m_window = nullptr;
	};
}
