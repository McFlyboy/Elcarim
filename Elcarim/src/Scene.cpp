#include "Scene.hpp"

namespace Elcarim::Scene {
	const float Scene::RELATIVE_SCENE_UNIT = Objects::Camera::PROJECTION_RESOLUTION_HEIGHT / 2.0f;
	const bool Scene::isRunning() const{
		return m_running;
	}
	Timing::Timer Scene::getTimer() const {
		return m_timer;
	}
	void Scene::start() {
		if (m_running) {
			return;
		}
		m_timer.start();
		m_running = true;
	}
	void Scene::pause() {
		if (!m_running) {
			return;
		}
		m_timer.pause();
		m_running = false;
	}
	void Scene::update() {
		update(m_deltaTimer.getDeltaTime());
	}
	Scene::~Scene() {}
}
