#include <iostream>

#include "Game.hpp"

namespace Elcarim {
	const char* const Game::TITLE = "Elcarim (Project 1996)";

	bool Game::start() {
		m_errorHandler = ErrorHandler::getInstance();
		Window::setNewInstanceSettings(1280, 720, TITLE);
		if (!(m_window = Window::getInstance())) {
			return false;
		}
		m_window->setVSync(true);
		m_keyboard = m_window->createKeyboard();
		return true;
	}
	bool Game::run() {
		if (!start()) {
			return false;
		}
		bool exitNormally = true;
		while (!m_window->shouldClose()) {
			if (m_keyboard->isKeyPressed(69)) {
				std::cout << "E-key was pressed\n";
			}
			m_window->update();
		}
		return exitNormally;
	}
	Game::~Game() {
		delete m_window;
		m_window = nullptr;
		m_keyboard = nullptr;
		delete m_errorHandler;
		m_errorHandler = nullptr;
	}
}
