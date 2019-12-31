#define _USE_MATH_DEFINES
#include "GameScene.hpp"

#include <cmath>

#include "Math.hpp"
#include "Window.hpp"

namespace Elcarim::Scene::Scenes {
	GameScene::GameScene(Input::Devices::Keyboard* const keyboard, Input::Devices::Gamepad* const gamepad) :
		m_controls(Input::GameControls(keyboard, gamepad)),
		m_camera(new Objects::Camera()),
		m_square(Util::Models::createSquareModel()),
		m_niamTex(new Graphics::Texture("niam.png")),
		m_ballTex(new Graphics::Texture("ball.png")),
		m_shotTex(new Graphics::Texture("shot.png")),
		m_bgTex(new Graphics::Texture("background.png")),
		m_niam(new Objects::Niam(Objects::Camera::getLowerEdge() + glm::vec2(0.0f, 8.0f), m_square, m_niamTex)),
		m_niamMovement(m_niam->getFirstComponentOfType<Objects::Components::MovementComponent>()),
		m_niamJumping(m_niam->getFirstComponentOfType<Objects::Components::JumpingComponent>()),
		m_niamHitting(m_niam->getFirstComponentOfType<Objects::Components::HittingComponent>()),
		m_hitTimer(Timing::Timer(getTimer())),
		m_ball(new Objects::Ball(glm::vec2(Scene::RELATIVE_SCENE_UNIT * 0.8f * Graphics::Renderer::ASPECT_RATIO, Scene::RELATIVE_SCENE_UNIT * -0.2f), m_square, m_ballTex)),
		m_ballMovement(m_ball->getFirstComponentOfType<Objects::Components::MovementComponent>()),
		m_ballCol(m_ball->getFirstComponentOfType<Objects::Components::CollisionComponent>()),
		m_ballHit(m_ball->getFirstComponentOfType<Objects::Components::BeingHitComponent>()),
		m_background(new Objects::Background(m_square, m_bgTex))
	{
		m_ballMovement->setVelocity(Scene::RELATIVE_SCENE_UNIT * -1.4f, Scene::RELATIVE_SCENE_UNIT);
		std::vector<Objects::Components::CollisionComponent*> niamColList;
		m_niam->getAllComponentsOfType<Objects::Components::CollisionComponent>(niamColList);
		m_niamCol = niamColList[0];
		m_niamHitCol = niamColList[1];
	}
	template<typename T>
	void deleteObject(T& t) {
		delete t;
		t = nullptr;
	}
	void GameScene::update(const float deltaTime) {
		//Niam
		m_niamMovement->getVelocity().x = m_controls.getHorizontalMovement() * RELATIVE_SCENE_UNIT;
		if (!m_niamJumping->isJumping()) {
			if (m_controls.isJumping()) {
				m_niamJumping->setJumping(true);
				m_niamMovement->getVelocity().y = 2.3f * RELATIVE_SCENE_UNIT;
			}
		}
		else {
			if (m_niam->getTransformation().getPosition().y < Objects::Camera::getLowerEdge().y + m_niam->getTransformation().getScale().y) {
				m_niamJumping->setJumping(false);
				m_niamMovement->getVelocity().y = 0.0f;
				m_niamMovement->getAcceleration().y = 0.0f;
				m_niam->getTransformation().getPosition().y = Objects::Camera::getLowerEdge().y + m_niam->getTransformation().getScale().y;
			}
			else if (m_controls.isJumping()) {
				m_niamMovement->getAcceleration().y = Scene::RELATIVE_SCENE_UNIT * -8.0f;
			}
			else {
				m_niamMovement->getAcceleration().y = Scene::RELATIVE_SCENE_UNIT * -15.0f;
			}
		}
		m_niamMovement->update(deltaTime);
		if (isObjectOutsideOfScreenX(m_niam)) {
			float xPos = m_niam->getTransformation().getPosition().x;
			m_niam->getTransformation().getPosition().x = (Objects::Camera::getRightEdge().x - m_niam->getTransformation().getScale().x) * Util::Math::getSign(xPos);
		}
		m_niamHitting->updateHitDirection();
		if (m_controls.isHitting()) {
			m_niamHitting->setHitting(true);
			m_hitTimer.start();
		}
		if (m_hitTimer.getTime() >= 1.0) {
			m_hitTimer.stop();
			m_niamHitting->setHitting(false);
		}

		//Shots
		if (m_controls.isShooting()) {
			Objects::Shot* shot = new Objects::Shot(m_niam->getTransformation().getPosition() + glm::vec2(0.0f, m_niam->getTransformation().getScale().y * 2.0f), m_square, m_shotTex);
			auto shotMovement = shot->getFirstComponentOfType<Objects::Components::MovementComponent>();
			shotMovement->setVelocity(0.0f, 3.0f * RELATIVE_SCENE_UNIT);
			m_shots.push_back(shot);
		}
		for (unsigned int i = 0u; i < m_shots.size(); ++i) {
			auto& shot = m_shots[i];
			auto shotMovement = shot->getFirstComponentOfType<Objects::Components::MovementComponent>();
			shotMovement->update(deltaTime);
			if (isObjectFullyOutsideOfScreenY(shot)) {
				deleteObject(shot);
				m_shots.erase(m_shots.begin() + i);
				--i;
			}
		}

		//Ball
		m_ballMovement->getAcceleration() = -m_ballMovement->getVelocity() * 0.025f;
		m_ballMovement->getAcceleration().y += Scene::RELATIVE_SCENE_UNIT * -11.25f * 0.2f;
		m_ballMovement->update(deltaTime);
		if (isObjectOutsideOfScreenX(m_ball)) {
			float xPos = m_ball->getTransformation().getPosition().x;
			m_ball->getTransformation().getPosition().x = (Objects::Camera::getRightEdge().x - m_ball->getTransformation().getScale().x) * Util::Math::getSign(xPos);
			m_ballMovement->getVelocity().x *= -0.9f;
		}
		if (isObjectOutsideOfScreenY(m_ball)) {
			float yPos = m_ball->getTransformation().getPosition().y;
			m_ball->getTransformation().getPosition().y = (Objects::Camera::getUpperEdge().y - m_ball->getTransformation().getScale().y) * Util::Math::getSign(yPos);
			m_ballMovement->getVelocity().y *= -0.9f;
		}
		m_ball->getTransformation().getAngle() -= 360.0f * (m_ballMovement->getVelocity() * deltaTime).x / (2.0f * static_cast<float>(M_PI) * m_ball->getTransformation().getScale().x) * 0.4f;
		
		//Niam-Ball collision
		if (!m_niamHitting->isHitting()) {
			if (m_niamCol->isColliding(*m_ballCol)) {
				Window::getInstance()->close();
			}
		}
		else {
			if (m_niamHitCol->isColliding(*m_ballCol)) {
				if (!m_ballHit->isBeingHit()) {
					m_ballHit->setBeingHit(true);
					m_ballMovement->getVelocity() = m_niamHitting->getHitDirection();
				}
			}
			else {
				m_ballHit->setBeingHit(false);
			}
		}
	}
	void GameScene::render(Graphics::Renderer* const renderer) {
		renderer->setCameraView(m_camera);

		renderer->render(m_background);
		renderer->render(m_niam);
		for (Objects::Shot* shot : m_shots) {
			renderer->render(shot);
		}
		renderer->render(m_ball);
	}
	GameScene::~GameScene() {
		deleteObject(m_background);
		deleteObject(m_niam);
		deleteObject(m_ball);
		m_ballMovement = nullptr;
		for (Objects::Shot*& shot : m_shots) {
			deleteObject(shot);
		}
		deleteObject(m_niamTex);
		deleteObject(m_ballTex);
		deleteObject(m_shotTex);
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
	bool GameScene::isObjectFullyOutsideOfScreenX(Objects::GameObject* object) {
		glm::vec2& pos = object->getTransformation().getPosition();
		glm::vec2& scale = object->getTransformation().getScale();
		if (std::abs(pos.x) - scale.x > Objects::Camera::getRightEdge().x) {
			return true;
		}
		return false;
	}
	bool GameScene::isObjectFullyOutsideOfScreenY(Objects::GameObject* object) {
		glm::vec2& pos = object->getTransformation().getPosition();
		glm::vec2& scale = object->getTransformation().getScale();
		if (std::abs(pos.y) - scale.y > Objects::Camera::getUpperEdge().y) {
			return true;
		}
		return false;
	}
}
