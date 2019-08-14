#pragma once

#include "Scene.hpp"
#include "Renderer.hpp"

namespace Elcarim::Scene {
	class SceneManager {
	public:
		enum class SceneID {
			GameScene
		};

		SceneManager(Graphics::Renderer* const renderer);
		Graphics::Renderer* const getRenderer() const;
		void loadNewScene(const SceneID sceneID);
		void updateActiveScene();
		void renderActiveScene();
		void unloadActiveScene();
		~SceneManager();
	private:
		Graphics::Renderer* m_renderer = nullptr;
		Scene* m_activeScene = nullptr;
	};
}
