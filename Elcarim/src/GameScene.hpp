#pragma once

#include "Scene.hpp"

#include "GameControls.hpp"
#include "Camera.hpp"
#include "Model.hpp"
#include "Models.hpp"
#include "Texture.hpp"
#include "Niam.hpp"
#include "Background.hpp"

namespace Elcarim::Scene::Scenes {
	class GameScene : public Scene {
	public:
		GameScene(Input::Devices::Keyboard* const keyboard, Input::Devices::Gamepad* const gamepad);
		virtual void render(Graphics::Renderer* const renderer) override;
		virtual ~GameScene() override;
	protected:
		virtual void update(const float deltaTime) override;
	private:
		Input::GameControls* m_controls = nullptr;
		Objects::Camera* m_camera = nullptr;
		Graphics::Model* m_square = nullptr;
		Graphics::Texture* m_niamTex = nullptr;
		Graphics::Texture* m_bgTex = nullptr;
		Objects::Niam* m_niam = nullptr;
		Objects::Background* m_background = nullptr;
	};
}
