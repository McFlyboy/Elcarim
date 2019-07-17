#include "Game.hpp"

namespace Elcarim {
	bool Game::start() {
		if (!(m_errorHandler = ErrorHandler::getInstance())) {
			return false;
		}
		if (!(m_window = Window::getInstance())) {
			return false;
		}
		return true;
	}
	bool Game::run() {
		if (!start()) {
			return false;
		}
		return true;
	}
	Game::~Game() {
		delete m_window;
		m_window = nullptr;
		delete m_errorHandler;
		m_errorHandler = nullptr;
	}
}
