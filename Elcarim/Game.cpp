#include "Game.hpp"

namespace Elcarim {
	bool Game::start() {
		if (!(m_errorHandler = ErrorHandler::createInstance())) {
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
		delete m_errorHandler;
		m_errorHandler = nullptr;
	}
}
