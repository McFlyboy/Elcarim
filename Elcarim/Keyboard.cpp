#include <iostream>

#include "Keyboard.hpp"

namespace Elcarim {
	namespace Input {
		namespace Device {
			Keyboard::Keyboard(GLFWwindow* const window) {
				glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
					std::cout << key << "\n";
				});
			}
		}
	}
}
