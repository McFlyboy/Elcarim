#include "SceneManager.hpp"

#include "GameScene.hpp"

namespace Elcarim::Scene {
	SceneManager::SceneManager(Graphics::Renderer* const renderer) : m_renderer(renderer) {
		m_activeScene = new Scenes::GameScene();
	}
	Graphics::Renderer* const SceneManager::getRenderer() const {
		return m_renderer;
	}
	void SceneManager::loadNewScene(const SceneID sceneID) {
		unloadActiveScene();
		switch (sceneID) {
		case SceneID::GameScene:
			m_activeScene = new Scenes::GameScene();
			break;
		}
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
