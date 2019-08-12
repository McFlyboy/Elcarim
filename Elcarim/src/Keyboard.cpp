#include "Keyboard.hpp"

#include <array>
#include <algorithm>

namespace Elcarim::Input::Device {
	//Fix for too fast key-pressing.
	//Overrides all other state-flags
	const uint8_t KEY_DOUBLESTATE_PRESS_AND_RELEASE = 4u;

	//Change-values
	const uint8_t KEY_STATE_CHANGED = 2u;
	const uint8_t KEY_STATE_UNCHANGED = 1u;

	std::array<uint8_t, GLFW_KEY_LAST + 1> keyStates;
	uint16_t lastKeyChanged = 0u;
	bool fullscreenShortcut = false;

	Keyboard::Keyboard(GLFWwindow* const window) : m_window(window) {
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == GLFW_REPEAT || key == GLFW_KEY_UNKNOWN) {
				return;
			}
			if (keyStates[key] == (GLFW_PRESS | KEY_STATE_CHANGED)) {
				keyStates[key] = KEY_DOUBLESTATE_PRESS_AND_RELEASE;
			}
			else {
				keyStates[key] = action | KEY_STATE_CHANGED;
			}
			if (action == GLFW_PRESS) {
				lastKeyChanged = key;
#ifdef _WIN32
				if (key == KEY_ENTER && mods == GLFW_MOD_ALT) {
					fullscreenShortcut = true;
				}
#elif defined(__APPLE__)
				if (key == KEY_ENTER && mods == GLFW_MOD_SUPER) {
					fullscreenShortcut = true;
				}
#endif
			}
			});
	}
	const bool Keyboard::isKeyPressed(uint16_t key) {
		return getKeyState(key) == (GLFW_PRESS | KEY_STATE_CHANGED);
	}
	const bool Keyboard::isKeyDown(uint16_t key) {
		return (getKeyState(key) & KEY_STATE_UNCHANGED) == GLFW_PRESS;
	}
	const uint8_t Keyboard::getKeyState(uint16_t key) {
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
	const uint16_t Keyboard::getLastKeyPressed() const {
		int lastKey = lastKeyChanged;
		lastKeyChanged = 0u;
		return lastKey;
	}
	const bool Keyboard::isFullscreenShortcutPressed() {
		bool fullscreenShortcutPressed = fullscreenShortcut;
		fullscreenShortcut = false;
		return fullscreenShortcutPressed;
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
