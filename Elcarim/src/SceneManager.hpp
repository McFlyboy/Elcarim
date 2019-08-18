#pragma once

#include "Scene.hpp"
#include "Renderer.hpp"

namespace Elcarim::Scene {
	class SceneManager {
	public:
		enum class SceneID {
			GameScene
		};

		SceneManager(Graphics::Renderer* const renderer, Input::Devices::Keyboard* const keyboard, Input::Devices::Gamepad* const gamepad);
		Graphics::Renderer* const getRenderer() const;
		void loadNewScene(const SceneID sceneID);
		void updateActiveScene();
		void renderActiveScene();
		void unloadActiveScene();
		~SceneManager();
	private:
		Graphics::Renderer* m_renderer = nullptr;
		Input::Devices::Keyboard* m_keyboard = nullptr;
		Input::Devices::Gamepad* m_gamepad = nullptr;
		Scene* m_activeScene = nullptr;
	};
}
