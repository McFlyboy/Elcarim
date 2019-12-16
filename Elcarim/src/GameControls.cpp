#include "GameControls.hpp"

namespace Elcarim::Input {
	GameControls::GameControls(Devices::Keyboard* const keyboard, Devices::Gamepad* const gamepad) :
		Controls(keyboard, gamepad),
		m_horizontalIndex(insertkeyPairAxisMapping(Devices::Keyboard::KEY_LEFT, Devices::Keyboard::KEY_RIGHT, Devices::Gamepad::AXIS_LEFT_X)),
		m_jumpIndex(insertkeyButtonMapping(Devices::Keyboard::KEY_SPACE, Devices::Gamepad::BUTTON_A))
	{}
	const float GameControls::getHorizontalMovement() {
		return getAxisValue(m_horizontalIndex);
	}
	const bool GameControls::isJumping() {
		return isPressed(m_jumpIndex);
	}
}
