#include "GameScene.hpp"

namespace Elcarim::Scene::Scenes {
	GameScene::GameScene(Input::Device::Keyboard* const keyboard, Input::Device::Gamepad* const gamepad) {
		m_controls = new Input::GameControls(keyboard, gamepad);
		m_square = Util::Models::createSquareModel();
		m_niamTex = new Graphics::Texture("niam.png");
		m_bgTex = new Graphics::Texture("background.png");
		m_niam = new Objects::Niam(glm::vec2(8.0f, 8.0f), m_square, m_niamTex);
		m_background = new Objects::Background(m_square, m_bgTex);
	}
	void GameScene::update(const float deltaTime) {
		m_niam->getTransformation().getPosition().x += m_controls->getHorizontalMovement() * deltaTime * 100.0f;
	}
	void GameScene::render(Graphics::Renderer* const renderer) {
		renderer->render(m_background);
		renderer->render(m_niam);
	}
	GameScene::~GameScene() {
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

		delete m_controls;
		m_controls = nullptr;
	}
}
