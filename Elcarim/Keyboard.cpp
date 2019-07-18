#include <cstdint>

#include "Keyboard.hpp"

namespace Elcarim {
	namespace Input {
		namespace Device {
			const int8_t KEY_CHANGED = 2;
			const int8_t KEY_UNCHANGED = 1;

			int8_t keyStates[GLFW_KEY_LAST + 1] = {0};

			Keyboard::Keyboard(GLFWwindow* const window) {
				glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
					if (action != GLFW_REPEAT && key > -1) {
						keyStates[key] = action | KEY_CHANGED;
					}
				});
			}
		}
	}
}
