#include "Timer.hpp"

#include "Window.hpp"

namespace Elcarim::Timing {
	Timer::Timer(Timer* const baseTimer, const bool running) : m_baseTimer(baseTimer), m_running(running) {
		if (running) {
			start();
		}
	}
	Timer* const Timer::getBaseTimer() const {
		return m_baseTimer;
	}
	void Timer::setBaseTimer(Timer* const baseTimer) {
		this->m_baseTimer = baseTimer;
		reset();
	}
	const double Timer::getTime() const {
		if (m_running) {
			return getBaseTime() - m_startTime;
		}
		else {
			return m_recordedTime;
		}
	}
	void Timer::setTime(const double time) {
		m_startTime = getBaseTime() - time;
		m_recordedTime = time;
	}
	void Timer::start() {
		if (m_running) {
			return;
		}
		m_startTime = getBaseTime() - m_recordedTime;
		m_running = true;
	}
	void Timer::pause() {
		if (!m_running) {
			return;
		}
		m_recordedTime = getTime();
		m_running = false;
	}
	void Timer::stop() {
		m_recordedTime = 0.0;
		m_running = false;
	}
	void Timer::reset() {
		m_recordedTime = 0.0;
		m_startTime = getBaseTime();
	}
	const double Timer::getBaseTime() const {
		return m_baseTimer ? m_baseTimer->getTime() : Window::getInstance()->getTime();
	}
}
