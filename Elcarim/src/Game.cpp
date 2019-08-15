#include "Game.hpp"

namespace Elcarim {
	const char* const Game::TITLE = "Elcarim (Project 1996)";

	bool Game::start() {
		m_errorHandler = ErrorHandler::getInstance();
		if (!(m_window = Window::createInstance(1280, 720, TITLE, false))) {
			return false;
		}
		m_window->setIconImages("icon_16x16.png", "icon_32x32.png", "icon_48x48.png");
		m_renderer = m_window->getRenderer();
		m_renderer->setVSync(false);
		m_renderer->setWireframe(false);
		m_renderer->setAlphaBlend(true);
		m_window->show();
		m_keyboard = m_window->getKeyboard();
		m_window->getMouse()->setCursorInvisible(true);
		m_gamepad = m_window->getGamepad();
		m_sceneManager = new Scene::SceneManager(m_renderer, m_keyboard, m_gamepad);
		return true;
	}
	bool Game::run() {
		if (!start()) {
			return false;
		}
		double targetFrameTime = 1.0 / m_window->getActiveMonitorRefreshRate();
		double renderTimeRemaining = 0.0;
		m_window->getDeltaTime();
		while (!m_window->shouldClose()) {
			bool renderReady = false;
			if (!update()) {
				return false;
			}
			if (renderTimeRemaining <= 0.0) {
				renderReady = true;
				renderTimeRemaining += targetFrameTime;
			}
			renderTimeRemaining -= m_window->getDeltaTime();
			if (renderReady) {
				render();
			}
		}
		return true;
	}
	bool Game::update() {
		m_window->update();
		if (m_keyboard->isKeyPressed(Input::Device::Keyboard::KEY_ESCAPE)) {
			m_window->close();
			return true;
		}
		if (
			m_keyboard->isKeyPressed(Input::Device::Keyboard::KEY_F11)
#if defined(_WIN32) || defined(__APPLE__)
			|| m_keyboard->isFullscreenShortcutPressed()
#endif
		) {
			m_window->setFullscreen(!m_window->isFullscreen());
		}
		m_gamepad->update();
		m_sceneManager->updateActiveScene();
		return true;
	}
	void Game::render() {
		m_renderer->clear();
		m_sceneManager->renderActiveScene();
		m_window->updateFrame();
	}
	Game::~Game() {
		delete m_sceneManager;
		m_sceneManager = nullptr;

		delete m_window;
		m_window = nullptr;
		m_renderer = nullptr;
		m_keyboard = nullptr;
		m_gamepad = nullptr;

		delete m_errorHandler;
		m_errorHandler = nullptr;
	}
}
