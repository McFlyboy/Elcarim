#pragma once

#include "Controls.hpp"

namespace Elcarim::Input {
	class GameControls : public Controls {
	public:
		GameControls(Device::Keyboard* const keyboard, Device::Gamepad* const gamepad);
		const float getHorizontalMovement();
	private:
		unsigned int m_horizontalIndex = 0;
	};
}
