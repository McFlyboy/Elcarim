#pragma once

#include <cstdint>
#include <vector>
#include <utility>

#include "Keyboard.hpp"
#include "Gamepad.hpp"

namespace Elcarim::Input {
	class Controls {
	protected:
		Controls(Devices::Keyboard* const keyboard, Devices::Gamepad* const gamepad);
		const bool isPressed(const unsigned int index);
		const bool isDown(const unsigned int index);
		const float getAxisValue(const unsigned int index);
		const float getKeyTriggerValue(const unsigned int index);
		const unsigned int insertkeyButtonMapping(const uint16_t key, const uint8_t button);
		const unsigned int insertkeyPairAxisMapping(const uint16_t negativeKey, const uint16_t positiveKey, const uint8_t axis);
		const unsigned int insertkeyTriggerMapping(const uint16_t key, const uint8_t trigger);
	private:
		Devices::Keyboard* m_keyboard = nullptr;
		Devices::Gamepad* m_gamepad = nullptr;
		std::vector<std::pair<uint16_t, uint8_t>> keyButtonMapping;
		std::vector<std::pair<std::pair<uint16_t, uint16_t>, uint8_t>> keyPairAxisMapping;
		std::vector<std::pair<uint16_t, uint8_t>> keyTriggerMapping;
	};
}
