#include "DeltaTimer.hpp"

#include <GLFW/glfw3.h>

namespace Elcarim::Timing {
	DeltaTimer::DeltaTimer(Timer* const baseTimer) : m_baseTimer(baseTimer) {
		m_startTime = getBaseTime();
	}
	Timer* const DeltaTimer::getBaseTimer() const {
		return m_baseTimer;
	}
	void DeltaTimer::setBaseTimer(Timer* const baseTimer) {
		this->m_baseTimer = baseTimer;
	}
	const float DeltaTimer::getDeltaTime() {
		double currentTime = getBaseTime();
		float deltaTime = static_cast<float>(currentTime - m_startTime);
		m_startTime = currentTime;
		return deltaTime;
	}
	const double DeltaTimer::getBaseTime() const {
		return m_baseTimer ? m_baseTimer->getTime() : glfwGetTime();
	}
}
