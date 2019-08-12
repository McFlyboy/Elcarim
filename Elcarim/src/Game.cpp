#include "Game.hpp"

#include <glm/glm.hpp>

#include "TexturedModelComponent.hpp"

namespace Elcarim {
	const char* const Game::TITLE = "Elcarim (Project 1996)";

	bool Game::start() {
		m_errorHandler = ErrorHandler::getInstance();
		Window::setNewInstanceSettings(1280, 720, TITLE);
		if (!(m_window = Window::getInstance())) {
			return false;
		}
		m_window->setIconImages("ball_16x16.png", "ball_32x32.png", "ball_48x48.png");
		m_renderer = m_window->getRenderer();
		m_renderer->setVSync(false);
		m_renderer->setWireframe(false);
		m_renderer->setAlphaBlend(true);
		m_window->show();
		m_keyboard = m_window->getKeyboard();
		m_mouse = m_window->getMouse();
		m_mouse->setCursorInvisible(true);
		m_gamepad = m_window->getGamepad();
		m_square = Util::Models::createSquareModel();
		m_niamTex = new Graphics::Texture("niam.png");
		m_bgTex = new Graphics::Texture("background.png");
		m_niam = new Objects::Niam(glm::vec2(8.0f, 8.0f), m_square, m_niamTex);
		m_background = new Objects::Background(m_square, m_bgTex);
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
		m_renderer->render(m_background);
		m_renderer->render(m_niam);
		m_window->updateFrame();
	}
	Game::~Game() {
		delete m_background;
		m_background = nullptr;

		delete m_niam;
		m_niam = nullptr;

		delete m_niamTex;
		m_niamTex = nullptr;

		delete m_bgTex;
		m_bgTex = nullptr;

		delete m_square;
		m_square = nullptr;

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
