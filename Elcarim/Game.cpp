#include "Game.hpp"

namespace Elcarim {
	const char* const Game::TITLE = "Elcarim";

	bool Game::start() {
		m_errorHandler = ErrorHandler::getInstance();
		Window::setNewInstanceSettings(1280, 720, TITLE);
		if (!(m_window = Window::getInstance())) {
			return false;
		}
		return true;
	}
	bool Game::run() {
		if (!start()) {
			return false;
		}
		bool exitNormally = true;
		while (!m_window->shouldClose()) {
			m_window->update();
		}
		return exitNormally;
	}
	Game::~Game() {
		delete m_window;
		m_window = nullptr;
		delete m_errorHandler;
		m_errorHandler = nullptr;
	}
}
