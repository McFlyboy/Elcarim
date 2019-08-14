#pragma once

#include "Scene.hpp"

#include "Model.hpp"
#include "Models.hpp"
#include "Texture.hpp"
#include "Niam.hpp"
#include "Background.hpp"

namespace Elcarim::Scene::Scenes {
	class GameScene : public Scene {
	public:
		GameScene();
		virtual void render(Graphics::Renderer* const renderer) override;
		virtual ~GameScene() override;
	protected:
		virtual void update(const float deltaTime) override;
	private:
		Graphics::Model* m_square = nullptr;
		Graphics::Texture* m_niamTex = nullptr;
		Graphics::Texture* m_bgTex = nullptr;
		Objects::Niam* m_niam = nullptr;
		Objects::Background* m_background = nullptr;
	};
}