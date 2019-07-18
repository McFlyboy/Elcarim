#pragma once

#include <cstdint>

#include <GLFW/glfw3.h>

namespace Elcarim {
	namespace Input {
		namespace Device {
			class Keyboard {
			public:
				Keyboard(GLFWwindow* const window);
				const bool isKeyPressed(int key);
				const bool isKeyDown(int key);
			private:
				const uint8_t getKeyState(int key);
			};
		}
	}
}
