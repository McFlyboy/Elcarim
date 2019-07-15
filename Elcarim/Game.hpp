#pragma once

#include "ErrorHandler.hpp"

namespace Elcarim {
	class Game {
	public:
		bool run();
		~Game();
	private:
		ErrorHandler* m_errorHandler = nullptr;

		bool start();
	};
}
