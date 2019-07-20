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
		m_keyboard = m_window->getKeyboard();
		m_mouse = m_window->getMouse();
		m_mouse->setInvisible(true);
		return true;
	}
	bool Game::run() {
		if (!start()) {
			return false;
		}
		bool exitNormally = true;
		while (!m_window->shouldClose()) {
			if (m_keyboard->isKeyPressed(Input::Device::Keyboard::KEY_ESCAPE)) {
				m_window->close();
			}
			if (m_keyboard->isKeyPressed(Input::Device::Keyboard::KEY_F11)) {
				m_window->setFullscreen(!m_window->isFullscreen());
			}
			m_window->update();
		}
		return exitNormally;
	}
	Game::~Game() {
		delete m_window;
		m_window = nullptr;
		m_keyboard = nullptr;
		m_mouse = nullptr;

		delete m_errorHandler;
		m_errorHandler = nullptr;
	}
}
