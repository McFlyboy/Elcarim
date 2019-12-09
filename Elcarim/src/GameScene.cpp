#include "GameScene.hpp"

#include <algorithm>

namespace Elcarim::Scene::Scenes {
	GameScene::GameScene(Input::Devices::Keyboard* const keyboard, Input::Devices::Gamepad* const gamepad) {
		m_controls = new Input::GameControls(keyboard, gamepad);
		m_camera = new Objects::Camera();
		m_square = Util::Models::createSquareModel();
		m_niamTex = new Graphics::Texture("niam.png");
		m_ballTex = new Graphics::Texture("ball.png");
		m_bgTex = new Graphics::Texture("background.png");
		m_niam = new Objects::Niam(Objects::Camera::getLowerEdge() + glm::vec2(0.0f, 8.0f), m_square, m_niamTex);
		m_ball = new Objects::Ball(Objects::Camera::getCenter(), m_square, m_ballTex);
		m_ballMovement = m_ball->getFirstComponentOfType<Elcarim::Objects::Components::MovementComponent>();
		m_ballMovement->setVelocity(100.0f, 100.0f);
		m_background = new Objects::Background(m_square, m_bgTex);
	}
	void GameScene::update(const float deltaTime) {
		m_niam->getTransformation().getPosition().x += m_controls->getHorizontalMovement() * 144.0f * deltaTime;
		m_ball->getTransformation().getPosition() += m_ballMovement->getVelocity() * deltaTime;
		if (isObjectOutsideOfScreenX(m_niam)) {
			float xPos = m_niam->getTransformation().getPosition().x;
			m_niam->getTransformation().getPosition().x = (Objects::Camera::getRightEdge().x - m_niam->getTransformation().getScale().x / 2.0f) * xPos / std::abs(xPos);
		}
		if (isObjectOutsideOfScreenX(m_ball)) {
			float xPos = m_ball->getTransformation().getPosition().x;
			m_ball->getTransformation().getPosition().x = (Objects::Camera::getRightEdge().x - m_ball->getTransformation().getScale().x / 2.0f) * xPos / std::abs(xPos);
			m_ballMovement->getVelocity().x *= -1.0f;
		}
		if (isObjectOutsideOfScreenY(m_ball)) {
			float yPos = m_ball->getTransformation().getPosition().y;
			m_ball->getTransformation().getPosition().y = (Objects::Camera::getUpperEdge().y - m_ball->getTransformation().getScale().y / 2.0f) * yPos / std::abs(yPos);
			m_ballMovement->getVelocity().y *= -1.0f;
		}
	}
	void GameScene::render(Graphics::Renderer* const renderer) {
		renderer->setCameraView(m_camera);

		renderer->render(m_background);
		renderer->render(m_niam);
		renderer->render(m_ball);
	}
	template<typename T>
	void deleteObject(T& t) {
		delete t;
		t = nullptr;
	}
	GameScene::~GameScene() {
		deleteObject(m_background);
		deleteObject(m_niam);
		deleteObject(m_ball);
		m_ballMovement = nullptr;
		deleteObject(m_niamTex);
		deleteObject(m_bgTex);
		deleteObject(m_square);
		deleteObject(m_camera);
		deleteObject(m_controls);
	}
	bool GameScene::isObjectOutsideOfScreenX(Objects::GameObject* object) {
		glm::vec2& pos = object->getTransformation().getPosition();
		glm::vec2& scale = object->getTransformation().getScale();
		if (std::abs(pos.x) + scale.x / 2.0f > Objects::Camera::getRightEdge().x) {
			return true;
		}
		return false;
	}
	bool GameScene::isObjectOutsideOfScreenY(Objects::GameObject* object) {
		glm::vec2& pos = object->getTransformation().getPosition();
		glm::vec2& scale = object->getTransformation().getScale();
		if (std::abs(pos.y) + scale.y / 2.0f > Objects::Camera::getUpperEdge().y) {
			return true;
		}
		return false;
	}
}
