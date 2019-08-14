#include "GameScene.hpp"

namespace Elcarim::Scene::Scenes {
	GameScene::GameScene() {
		m_square = Util::Models::createSquareModel();
		m_niamTex = new Graphics::Texture("niam.png");
		m_bgTex = new Graphics::Texture("background.png");
		m_niam = new Objects::Niam(glm::vec2(8.0f, 8.0f), m_square, m_niamTex);
		m_background = new Objects::Background(m_square, m_bgTex);
	}
	void GameScene::update(const float deltaTime) {

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
	}
}
