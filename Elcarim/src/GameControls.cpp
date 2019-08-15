#include "GameControls.hpp"

namespace Elcarim::Input {
	GameControls::GameControls(Device::Keyboard* const keyboard, Device::Gamepad* const gamepad) :
		Controls(keyboard, gamepad),
		m_horizontalIndex(insertkeyPairAxisMapping(Device::Keyboard::KEY_LEFT, Device::Keyboard::KEY_RIGHT, Device::Gamepad::AXIS_LEFT_X))
	{}
	const float GameControls::getHorizontalMovement() {
		return getAxisValue(m_horizontalIndex);
	}
}
