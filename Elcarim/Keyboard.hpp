#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

namespace Elcarim {
	namespace Input {
		namespace Device {
			class Keyboard {
			public:
				Keyboard(GLFWwindow* const window);
			};
		}
	}
}
