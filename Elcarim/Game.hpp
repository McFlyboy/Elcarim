#pragma once

#include "ErrorHandler.hpp"
#include "Window.hpp"

namespace Elcarim {
	class Game {
	public:
		static const char* const TITLE;
		bool run();
		~Game();
	private:
		ErrorHandler* m_errorHandler = nullptr;
		Window* m_window = nullptr;

		bool start();
	};
}
