#include "GameControls.hpp"

namespace Elcarim::Input {
	GameControls::GameControls(Devices::Keyboard* const keyboard, Devices::Gamepad* const gamepad) :
		Controls(keyboard, gamepad),
		m_horizontalIndex(insertkeyPairAxisMapping(Devices::Keyboard::KEY_LEFT, Devices::Keyboard::KEY_RIGHT, Devices::Gamepad::AXIS_LEFT_X))
	{}
	const float GameControls::getHorizontalMovement() {
		return getAxisValue(m_horizontalIndex);
	}
}
