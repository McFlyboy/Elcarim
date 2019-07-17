#pragma once

#include "ErrorHandler.hpp"
#include "Window.hpp"

namespace Elcarim {
	class Game {
	public:
		bool run();
		~Game();
	private:
		ErrorHandler* m_errorHandler = nullptr;
		Window* m_window = nullptr;

		bool start();
	};
}
