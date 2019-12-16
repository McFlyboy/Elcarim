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

namespace Elcarim::Scene::Scenes {
	class GameScene : public Scene {
	public:
		GameScene(Input::Devices::Keyboard* const keyboard, Input::Devices::Gamepad* const gamepad);
		virtual void render(Graphics::Renderer* const renderer) override;
		virtual ~GameScene() override;
	protected:
		virtual void update(const float deltaTime) override;
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
		Objects::Ball* m_ball = nullptr;
		Objects::Components::MovementComponent* m_ballMovement = nullptr;
		Objects::Background* m_background = nullptr;

		bool isObjectOutsideOfScreenX(Objects::GameObject* object);
		bool isObjectOutsideOfScreenY(Objects::GameObject* object);
	};
}
