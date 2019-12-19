#pragma once

#include "Scene.hpp"

#include "GameControls.hpp"
#include "Camera.hpp"
#include "Model.hpp"
#include "Models.hpp"
#include "Texture.hpp"
#include "Niam.hpp"
#include "Ball.hpp"
#include "Background.hpp"
#include "GameObject.hpp"
#include "MovementComponent.hpp"
#include "JumpingComponent.hpp"
#include "CollisionComponent.hpp"
#include "HittingComponent.hpp"
#include "BeingHitComponent.hpp"
#include "Timer.hpp"

namespace Elcarim::Scene::Scenes {
	class GameScene : public Scene {
	public:
		GameScene(Input::Devices::Keyboard* const keyboard, Input::Devices::Gamepad* const gamepad);
		void render(Graphics::Renderer* const renderer) override;
		~GameScene() override;
	protected:
		void update(const float deltaTime) override;
	private:
		Input::GameControls m_controls;
		Objects::Camera* m_camera = nullptr;
		Graphics::Model* m_square = nullptr;
		Graphics::Texture* m_niamTex = nullptr;
		Graphics::Texture* m_ballTex = nullptr;
		Graphics::Texture* m_bgTex = nullptr;
		Objects::Niam* m_niam = nullptr;
		Objects::Components::MovementComponent* m_niamMovement = nullptr;
		Objects::Components::JumpingComponent* m_niamJumping = nullptr;
		Objects::Components::CollisionComponent* m_niamCol = nullptr;
		Objects::Components::CollisionComponent* m_niamHitCol = nullptr;
		Objects::Components::HittingComponent* m_niamHitting = nullptr;
		Timing::Timer m_hitTimer;
		Objects::Ball* m_ball = nullptr;
		Objects::Components::MovementComponent* m_ballMovement = nullptr;
		Objects::Components::CollisionComponent* m_ballCol = nullptr;
		Objects::Components::BeingHitComponent* m_ballHit = nullptr;
		Objects::Background* m_background = nullptr;

		bool isObjectOutsideOfScreenX(Objects::GameObject* object);
		bool isObjectOutsideOfScreenY(Objects::GameObject* object);
	};
}
