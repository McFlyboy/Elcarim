#pragma once

#include <cstdint>

#include <GLFW/glfw3.h>

namespace Elcarim::Input::Device {
	class Gamepad {
	public:
		static const uint8_t
			BUTTON_A = 0,
			BUTTON_B = 1,
			BUTTON_X = 2,
			BUTTON_Y = 3,
			BUTTON_LEFT_BUMPER = 4,
			BUTTON_RIGHT_BUMPER = 5,
			BUTTON_BACK = 6,
			BUTTON_START = 7,
			BUTTON_GUIDE = 8,
			BUTTON_LEFT_THUMB = 9,
			BUTTON_RIGHT_THUMB = 10,
			BUTTON_DPAD_UP = 11,
			BUTTON_DPAD_RIGHT = 12,
			BUTTON_DPAD_DOWN = 13,
			BUTTON_DPAD_LEFT = 14,

			AXIS_LEFT_X = 0,
			AXIS_LEFT_Y = 1,
			AXIS_RIGHT_X = 2,
			AXIS_RIGHT_Y = 3,
			AXIS_LEFT_TRIGGER = 4,
			AXIS_RIGHT_TRIGGER = 5;

		const bool isGamepadConnected();
		const char* const getGamepadName();
		void setFocued(bool focused);
		void update();
		const bool isButtonPressed(uint8_t button);
		const bool isButtonDown(uint8_t button);
		const float getAxisValue(uint8_t axis);
		void resetAllButtonStates();
		void resetAllAxisStates();
		~Gamepad();
		static Gamepad* const getInstance();
	private:
		GLFWgamepadstate m_state = GLFWgamepadstate();
		bool focused = true;
		static Gamepad* s_instance;

		Gamepad();
		const uint8_t getButtonState(uint8_t button);
	};
}
