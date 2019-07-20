#pragma once

#include "ErrorHandler.hpp"
#include "Window.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

namespace Elcarim {
	class Game {
	public:
		static const char* const TITLE;

		bool run();
		~Game();
	private:
		ErrorHandler* m_errorHandler = nullptr;
		Window* m_window = nullptr;
		Input::Device::Keyboard* m_keyboard = nullptr;
		Input::Device::Mouse* m_mouse = nullptr;

		bool start();
	};
}
