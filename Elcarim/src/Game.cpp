#include "Game.hpp"

namespace Elcarim {
	const char* const Game::TITLE = "Elcarim (Project 1996)";

	bool Game::start() {
		m_errorHandler = Util::ErrorHandler::getInstance();
		Window::setNewInstanceSettings(1280, 720, TITLE);
		if (!(m_window = Window::getInstance())) {
			return false;
		}
		m_window->setIconImages("ball_16x16.png", "ball_32x32.png", "ball_48x48.png");
		m_renderer = m_window->getRenderer();
		m_renderer->setVSync(false);
		m_renderer->setWireframe(false);
		//Testing-color
		m_renderer->setClearColor(0.2f, 0.15f, 0.4f);
		m_window->show();
		m_keyboard = m_window->getKeyboard();
		m_mouse = m_window->getMouse();
		m_mouse->setCursorInvisible(true);
		m_gamepad = m_window->getGamepad();
		float data[8] = {
			-0.5f, -0.5f,
			0.5f, -0.5f,
			0.5f, 0.5f,
			-0.5f, 0.5f
		};
		m_model = new Graphics::Model();
		m_model->addAttrib(0, 2, 8, data);
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
		if (m_keyboard->isKeyPressed(Input::Device::Keyboard::KEY_F11) || m_keyboard->isFullscreenShortcutPressed()) {
			m_window->setFullscreen(!m_window->isFullscreen());
		}
		m_gamepad->update();
		return true;
	}
	void Game::render() {
		m_renderer->clear();
		m_renderer->render(m_model);
		m_window->updateFrame();
	}
	Game::~Game() {
		delete m_model;
		m_model = nullptr;

		delete m_window;
		m_window = nullptr;
		m_renderer = nullptr;
		m_keyboard = nullptr;
		m_mouse = nullptr;
		m_gamepad = nullptr;

		delete m_errorHandler;
		m_errorHandler = nullptr;
	}
}
