#include <array>
#include <algorithm>

#include "Keyboard.hpp"

namespace Elcarim {
	namespace Input {
		namespace Device {
			//Fix for too fast key-pressing.
			//Overrides all other state-flags
			const uint8_t KEY_DOUBLESTATE_PRESS_AND_RELEASE = 4u;

			//Change-values
			const uint8_t KEY_STATE_CHANGED   = 2u;
			const uint8_t KEY_STATE_UNCHANGED = 1u;

			std::array<uint8_t, GLFW_KEY_LAST + 1> keyStates;
			uint32_t lastKeyChanged = 0u;

			Keyboard::Keyboard(GLFWwindow* const window) : m_window(window) {
				glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
					if (action == GLFW_REPEAT || key == GLFW_KEY_UNKNOWN) {
						return;
					}
					if (keyStates[key] == (GLFW_PRESS | KEY_STATE_CHANGED)) {
						keyStates[key] = KEY_DOUBLESTATE_PRESS_AND_RELEASE;
					}
					else {
						keyStates[key] = static_cast<uint8_t>(action) | KEY_STATE_CHANGED;
					}
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
				if (keyState == KEY_DOUBLESTATE_PRESS_AND_RELEASE) {
					keyStates[key] = GLFW_RELEASE | KEY_STATE_CHANGED;
					keyState = GLFW_PRESS | KEY_STATE_CHANGED;
				}
				else {
					keyStates[key] &= KEY_STATE_UNCHANGED;
				}
				return keyState;
			}
			const int Keyboard::getLastKeyPressed() const {
				int lastKey = static_cast<int>(lastKeyChanged);
				lastKeyChanged = 0u;
				return lastKey;
			}
			void Keyboard::resetAllKeyStates() const {
				std::for_each(keyStates.begin(), keyStates.end(), [](uint8_t& keyState) {
					keyState = GLFW_RELEASE;
				});
			}
			Keyboard::~Keyboard() {
				glfwSetKeyCallback(m_window, nullptr);
				m_window = nullptr;
			}
		}
	}
}
