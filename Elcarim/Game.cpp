#include "Game.hpp"
#include "ErrorHandler.hpp"

namespace Elcarim {
	bool Game::start() {
		if (!ErrorHandler::createInstance()) {
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
		delete ErrorHandler::getInstance();
	}
}