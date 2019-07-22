#include <memory>
#include <cstdlib>

#include "Gamepad.hpp"

namespace Elcarim {
	namespace Input {
		namespace Device {
			//Fix for too fast key-pressing.
			//Overrides all other state-flags
			const uint8_t BUTTON_DOUBLESTATE_PRESS_AND_RELEASE = 4u;

			//Change-values
			const uint8_t BUTTON_STATE_CHANGED = 2u;
			const uint8_t BUTTON_STATE_UNCHANGED = 1u;

			//Threshold values
			const float INNER_THRESHOLD = 0.1f;
			const float OUTER_THRESHOLD = 0.9f;

			Gamepad::Gamepad(const int gamepadID) : m_gamepadID(gamepadID) {}
			const bool Gamepad::isGamepadConnected() {
				return glfwJoystickIsGamepad(m_gamepadID);
			}
			const char* const Gamepad::getGamepadName() {
				if (!isGamepadConnected()) {
					return "";
				}
				return glfwGetGamepadName(m_gamepadID);
			}
			void Gamepad::update() {
				GLFWgamepadstate state;
				if (glfwGetGamepadState(m_gamepadID, &state)) {
					for (int i = 0; i < 15; i++) {
						if ((m_state.buttons[i] & BUTTON_STATE_UNCHANGED) != state.buttons[i]) {
							m_state.buttons[i] = state.buttons[i] | BUTTON_STATE_CHANGED;
						}
					}
					memcpy(&m_state.axes, &state.axes, sizeof(float) * 6);
					m_state.axes[AXIS_LEFT_Y] *= -1;
					m_state.axes[AXIS_RIGHT_Y] *= -1;
					m_state.axes[AXIS_LEFT_TRIGGER] = (m_state.axes[AXIS_LEFT_TRIGGER] + 1.0f) / 2.0f;
					m_state.axes[AXIS_RIGHT_TRIGGER] = (m_state.axes[AXIS_RIGHT_TRIGGER] + 1.0f) / 2.0f;
				}
			}
			const bool Gamepad::isButtonPressed(uint8_t button) {
				return getButtonState(button) == (GLFW_PRESS | BUTTON_STATE_CHANGED);
			}
			const bool Gamepad::isButtonDown(uint8_t button) {
				return (getButtonState(button) & BUTTON_STATE_UNCHANGED) == GLFW_PRESS;
			}
			const uint8_t Gamepad::getButtonState(uint8_t button) {
				uint8_t buttonState = m_state.buttons[button];
				if (buttonState == BUTTON_DOUBLESTATE_PRESS_AND_RELEASE) {
					m_state.buttons[button] = GLFW_RELEASE | BUTTON_STATE_CHANGED;
					buttonState = GLFW_PRESS | BUTTON_STATE_CHANGED;
				}
				else {
					m_state.buttons[button] &= BUTTON_STATE_UNCHANGED;
				}
				return buttonState;
			}
			const float Gamepad::getAxisValue(uint8_t axis) {
				if (axis < 4) {
					if (std::abs(m_state.axes[axis]) < INNER_THRESHOLD) {
						m_state.axes[axis] = 0.0f;
					}
					else if (std::abs(m_state.axes[axis]) > OUTER_THRESHOLD) {
						if (m_state.axes[axis] > 0.0f) {
							m_state.axes[axis] = 1.0f;
						}
						else {
							m_state.axes[axis] = -1.0f;
						}
					}
				}
				return m_state.axes[axis];
			}
		}
	}
}
