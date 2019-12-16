#pragma once

#include "Controls.hpp"

namespace Elcarim::Input {
	class GameControls : public Controls {
	public:
		GameControls(Devices::Keyboard* const keyboard, Devices::Gamepad* const gamepad);
		const float getHorizontalMovement();
		const bool isJumping();
	private:
		unsigned int m_horizontalIndex = 0;
		unsigned int m_jumpIndex = 0;
	};
}
