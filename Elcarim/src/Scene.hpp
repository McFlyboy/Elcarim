#pragma once

#include "Timer.hpp"
#include "DeltaTimer.hpp"
#include "Renderer.hpp"
#include "Keyboard.hpp"
#include "Gamepad.hpp"
#include "Camera.hpp"

namespace Elcarim::Scene {
	class Scene {
	public:
		static const float RELATIVE_SCENE_UNIT;

		const bool isRunning() const;
		Timing::Timer getTimer() const;
		void start();
		void pause();
		void update();
		virtual void render(Graphics::Renderer* const renderer) = 0;
		virtual ~Scene();
	protected:
		virtual void update(const float deltaTime) = 0;
	private:
		bool m_running = false;
		Timing::Timer m_timer = Timing::Timer();
		Timing::DeltaTimer m_deltaTimer = Timing::DeltaTimer(&m_timer);
	};
}
