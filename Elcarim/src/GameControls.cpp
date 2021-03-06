#include "GameControls.hpp"

namespace Elcarim::Input {
	GameControls::GameControls(Devices::Keyboard* const keyboard, Devices::Gamepad* const gamepad) :
		Controls(keyboard, gamepad),
		m_horizontalIndex(insertkeyPairAxisMapping(Devices::Keyboard::KEY_LEFT, Devices::Keyboard::KEY_RIGHT, Devices::Gamepad::AXIS_LEFT_X)),
		m_jumpIndex(insertkeyButtonMapping(Devices::Keyboard::KEY_SPACE, Devices::Gamepad::BUTTON_A)),
		m_shootIndex1(insertkeyButtonMapping(Devices::Keyboard::KEY_Z, Devices::Gamepad::BUTTON_LEFT_BUMPER)),
		m_shootIndex2(insertkeyButtonMapping(Devices::Keyboard::KEY_X, Devices::Gamepad::BUTTON_RIGHT_BUMPER)),
		m_hitIndex(insertkeyButtonMapping(Devices::Keyboard::KEY_C, Devices::Gamepad::BUTTON_X))
	{}
	const float GameControls::getHorizontalMovement() {
		return getAxisValue(m_horizontalIndex);
	}
	const bool GameControls::isJumping() {
		return isDown(m_jumpIndex);
	}
	const bool GameControls::isShooting() {
		return isPressed(m_shootIndex1) | isPressed(m_shootIndex2);
	}
	const bool GameControls::isHitting() {
		return isPressed(m_hitIndex);
	}
}
