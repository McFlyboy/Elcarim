#include "Controls.hpp"

namespace Elcarim::Input {
	Controls::Controls(Device::Keyboard* const keyboard, Device::Gamepad* const gamepad) : m_keyboard(keyboard), m_gamepad(gamepad) {}
	const bool Controls::isPressed(const unsigned int index) {
		auto mapping = keyButtonMapping[index];
		return m_keyboard->isKeyPressed(mapping.first) || m_gamepad->isButtonPressed(mapping.second);
	}
	const bool Controls::isDown(const unsigned int index) {
		auto mapping = keyButtonMapping[index];
		return m_keyboard->isKeyDown(mapping.first) || m_gamepad->isButtonDown(mapping.second);
	}
	const float Controls::getAxisValue(const unsigned int index) {
		auto mapping = keyPairAxisMapping[index];
		const float keyOutput = (m_keyboard->isKeyDown(mapping.first.first) ? -1.0f : 0.0f) + (m_keyboard->isKeyDown(mapping.first.second) ? 1.0f : 0.0f);
		if (keyOutput != 0.0f) {
			return keyOutput;
		}
		return m_gamepad->getAxisValue(mapping.second);
	}
	const float Controls::getKeyTriggerValue(const unsigned int index) {
		auto mapping = keyTriggerMapping[index];
		const float keyOutput = m_keyboard->isKeyDown(mapping.first);
		if (keyOutput != 0.0f) {
			return keyOutput;
		}
		return m_gamepad->getTriggerValue(mapping.second);
	}
	const unsigned int Controls::insertkeyButtonMapping(const uint16_t key, const uint8_t button) {
		keyButtonMapping.push_back(std::pair<uint16_t, uint8_t>(key, button));
		return keyButtonMapping.size() - 1;
	}
	const unsigned int Controls::insertkeyPairAxisMapping(const uint16_t negativeKey, const uint16_t positiveKey, const uint8_t axis) {
		keyPairAxisMapping.push_back(std::pair<std::pair<uint16_t, uint16_t>, uint8_t>(std::pair<uint16_t, uint16_t>(negativeKey, positiveKey), axis));
		return keyPairAxisMapping.size() - 1;
	}
	const unsigned int Controls::insertkeyTriggerMapping(const uint16_t key, const uint8_t trigger) {
		keyTriggerMapping.push_back(std::pair<uint16_t, uint8_t>(key, trigger));
		return keyTriggerMapping.size() - 1;
	}
}
