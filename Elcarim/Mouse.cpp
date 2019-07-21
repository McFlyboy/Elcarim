#include "Mouse.hpp"

namespace Elcarim {
	namespace Input {
		namespace Device {
			Mouse::Mouse(GLFWwindow* const window) : m_window(window) {}
			void Mouse::setCursorInvisible(const bool invisible) {
				glfwSetInputMode(m_window, GLFW_CURSOR, invisible ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL);
			}
			Mouse::~Mouse() {
				m_window = nullptr;
			}
		}
	}
}
