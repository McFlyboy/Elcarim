#include <array>

#include "Keyboard.hpp"

namespace Elcarim {
	namespace Input {
		namespace Device {
			//Change-values
			const uint8_t KEY_STATE_CHANGED   = 2;
			const uint8_t KEY_STATE_UNCHANGED = 1;

			std::array<uint8_t, GLFW_KEY_LAST + 1> keyStates;
			uint32_t lastKeyChanged = 0u;

			Keyboard::Keyboard(GLFWwindow* const window) {
				glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
					if (action == GLFW_REPEAT || key == GLFW_KEY_UNKNOWN) {
						return;
					}
					keyStates[key] = static_cast<uint8_t>(action) | KEY_STATE_CHANGED;
					if (action == GLFW_PRESS) {
						lastKeyChanged = key;
					}
				});
			}
			const bool Keyboard::isKeyPressed(int key) {
				return getKeyState(key) == (GLFW_PRESS | KEY_STATE_CHANGED);
			}
			const bool Keyboard::isKeyDown(int key) {
				return (getKeyState(key) & KEY_STATE_UNCHANGED) == GLFW_PRESS;
			}
			const uint8_t Keyboard::getKeyState(int key) {
				uint8_t keyState = keyStates[key];
				keyStates[key] &= KEY_STATE_UNCHANGED;
				return keyState;
			}
		}
	}
}
