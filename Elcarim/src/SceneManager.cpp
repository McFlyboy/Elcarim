#include "SceneManager.hpp"

#include "GameScene.hpp"

namespace Elcarim::Scene {
	SceneManager::SceneManager(Graphics::Renderer* const renderer, Input::Device::Keyboard* const keyboard, Input::Device::Gamepad* const gamepad) :
		m_renderer(renderer),
		m_keyboard(keyboard),
		m_gamepad(gamepad)
	{
		loadNewScene(SceneID::GameScene);
	}
	Graphics::Renderer* const SceneManager::getRenderer() const {
		return m_renderer;
	}
	void SceneManager::loadNewScene(const SceneID sceneID) {
		unloadActiveScene();
		switch (sceneID) {
		case SceneID::GameScene:
			m_activeScene = new Scenes::GameScene(m_keyboard, m_gamepad);
			break;
		}
		m_activeScene->start();
	}
	void SceneManager::updateActiveScene() {
		m_activeScene->update();
	}
	void SceneManager::renderActiveScene() {
		m_activeScene->render(m_renderer);
	}
	void SceneManager::unloadActiveScene() {
		delete m_activeScene;
		m_activeScene = nullptr;
	}
	SceneManager::~SceneManager() {
		unloadActiveScene();
		m_renderer = nullptr;
	}
}
