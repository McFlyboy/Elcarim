#define _USE_MATH_DEFINES
#include "GameScene.hpp"

#include <cmath>

#include "Window.hpp"
#include "CollisionComponent.hpp"

namespace Elcarim::Scene::Scenes {
	GameScene::GameScene(Input::Devices::Keyboard* const keyboard, Input::Devices::Gamepad* const gamepad) :
		m_controls(Input::GameControls(keyboard, gamepad)),
		m_camera(new Objects::Camera()),
		m_square(Util::Models::createSquareModel()),
		m_niamTex(new Graphics::Texture("niam.png")),
		m_ballTex(new Graphics::Texture("ball.png")),
		m_bgTex(new Graphics::Texture("background.png")),
		m_niam(new Objects::Niam(Objects::Camera::getLowerEdge() + glm::vec2(0.0f, 8.0f), m_square, m_niamTex)),
		m_ball(new Objects::Ball(glm::vec2(Scene::RELATIVE_SCENE_UNIT * 0.8f * Graphics::Renderer::ASPECT_RATIO, Scene::RELATIVE_SCENE_UNIT * -0.2f), m_square, m_ballTex)),
		m_ballMovement(m_ball->getFirstComponentOfType<Elcarim::Objects::Components::MovementComponent>()),
		m_background(new Objects::Background(m_square, m_bgTex))
	{
		m_ballMovement->setVelocity(Scene::RELATIVE_SCENE_UNIT * -1.4f, Scene::RELATIVE_SCENE_UNIT * 1.0f);
	}
	const float getSign(const float value) {
		return static_cast<float>(((!(static_cast<int>(value) >> (sizeof(int) * 8 - 1))) << 1) - 1);
	}
	void GameScene::update(const float deltaTime) {
		m_niam->getTransformation().getPosition().x += m_controls.getHorizontalMovement() * RELATIVE_SCENE_UNIT * deltaTime;
		m_ballMovement->getAcceleration() = -m_ballMovement->getVelocity() * 0.025f;
		m_ballMovement->getAcceleration().y += Scene::RELATIVE_SCENE_UNIT * -11.25f * 0.2f;
		m_ballMovement->update(deltaTime);
		if (isObjectOutsideOfScreenX(m_niam)) {
			float xPos = m_niam->getTransformation().getPosition().x;
			m_niam->getTransformation().getPosition().x = (Objects::Camera::getRightEdge().x - m_niam->getTransformation().getScale().x) * getSign(xPos);
		}
		if (isObjectOutsideOfScreenX(m_ball)) {
			float xPos = m_ball->getTransformation().getPosition().x;
			m_ball->getTransformation().getPosition().x = (Objects::Camera::getRightEdge().x - m_ball->getTransformation().getScale().x) * getSign(xPos);
			m_ballMovement->getVelocity().x *= -0.9f;
		}
		if (isObjectOutsideOfScreenY(m_ball)) {
			float yPos = m_ball->getTransformation().getPosition().y;
			m_ball->getTransformation().getPosition().y = (Objects::Camera::getUpperEdge().y - m_ball->getTransformation().getScale().y) * getSign(yPos);
			m_ballMovement->getVelocity().y *= -0.9f;
		}
		m_ball->getTransformation().getAngle() -= 360.0f * (m_ballMovement->getVelocity() * deltaTime).x / (2.0f * static_cast<float>(M_PI) * m_ball->getTransformation().getScale().x) * 0.4f;
		if (m_niam->getFirstComponentOfType<Elcarim::Objects::Components::CollisionComponent>()->isColliding(*m_ball->getFirstComponentOfType<Elcarim::Objects::Components::CollisionComponent>())) {
			Window::getInstance()->close();
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
	}
	bool GameScene::isObjectOutsideOfScreenX(Objects::GameObject* object) {
		glm::vec2& pos = object->getTransformation().getPosition();
		glm::vec2& scale = object->getTransformation().getScale();
		if (std::abs(pos.x) + scale.x > Objects::Camera::getRightEdge().x) {
			return true;
		}
		return false;
	}
	bool GameScene::isObjectOutsideOfScreenY(Objects::GameObject* object) {
		glm::vec2& pos = object->getTransformation().getPosition();
		glm::vec2& scale = object->getTransformation().getScale();
		if (std::abs(pos.y) + scale.y > Objects::Camera::getUpperEdge().y) {
			return true;
		}
		return false;
	}
}
