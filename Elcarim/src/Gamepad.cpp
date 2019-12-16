#include "Gamepad.hpp"

#include <memory>
#include <cstdlib>

namespace Elcarim::Input::Devices {
	Gamepad* Gamepad::s_instance = nullptr;

	//Change-values
	const uint8_t BUTTON_STATE_CHANGED = 2u;
	const uint8_t BUTTON_STATE_UNCHANGED = 1u;

	//Threshold values
	const float INNER_THRESHOLD = 0.1f;
	const float OUTER_THRESHOLD = 0.9f;

	Gamepad::Gamepad() {
		glfwSetJoystickUserPointer(GLFW_JOYSTICK_1, this);
		glfwSetJoystickCallback([](int jid, int event) {
			Gamepad* instance = (Gamepad*)glfwGetJoystickUserPointer(GLFW_JOYSTICK_1);
			if (jid == GLFW_JOYSTICK_1 && event == GLFW_DISCONNECTED) {
				instance->resetAllButtonStates();
				instance->resetAllAxisStates();
			}
			});
	}
	const bool Gamepad::isGamepadConnected() {
		return glfwJoystickIsGamepad(GLFW_JOYSTICK_1);
	}
	const char* const Gamepad::getGamepadName() {
		if (!isGamepadConnected()) {
			return "";
		}
		return glfwGetGamepadName(GLFW_JOYSTICK_1);
	}
	void Gamepad::setFocued(bool focused) {
		this->focused = focused;
	}
	void Gamepad::update() {
		if (!focused) {
			return;
		}
		GLFWgamepadstate state;
		if (glfwGetGamepadState(GLFW_JOYSTICK_1, &state)) {
			for (int i = 0; i < 15; ++i) {
				if ((m_state.buttons[i] & BUTTON_STATE_UNCHANGED) != state.buttons[i]) {
					m_state.buttons[i] = state.buttons[i] | BUTTON_STATE_CHANGED;
				}
			}
			memcpy(&m_state.axes, &state.axes, sizeof(float) * 4);
			m_state.axes[AXIS_LEFT_Y] *= -1;
			m_state.axes[AXIS_RIGHT_Y] *= -1;
			memcpy(&m_state.triggers, &state.axes[4], sizeof(float) * 2);
			m_state.triggers[TRIGGER_LEFT] = (m_state.triggers[TRIGGER_LEFT] + 1.0f) / 2.0f;
			m_state.triggers[TRIGGER_RIGHT] = (m_state.triggers[TRIGGER_RIGHT] + 1.0f) / 2.0f;
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
		m_state.buttons[button] &= BUTTON_STATE_UNCHANGED;
		return buttonState;
	}
	const float Gamepad::getAxisValue(uint8_t axis) {
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
		return m_state.axes[axis];
	}
	const float Gamepad::getTriggerValue(uint8_t trigger) {
		return m_state.triggers[trigger];
	}
	void Gamepad::resetAllButtonStates() {
		for (int i = 0; i < 15; ++i) {
			m_state.buttons[i] = GLFW_RELEASE;
		}
	}
	void Gamepad::resetAllAxisStates() {
		for (int i = 0; i < 4; ++i) {
			m_state.axes[i] = 0.0f;
		}
	}
	void Gamepad::resetAllTriggerStates() {
		for (int i = 0; i < 2; ++i) {
			m_state.triggers[i] = 0.0f;
		}
	}
	Gamepad::~Gamepad() {
		glfwSetJoystickCallback(nullptr);
		s_instance = nullptr;
	}
	Gamepad* const Gamepad::createInstance() {
		if (!s_instance) {
			s_instance = new Gamepad();
			return s_instance;
		}
		return nullptr;
	}
}
