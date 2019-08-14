#pragma once

namespace Elcarim::Timing {
	class Timer {
	public:
		Timer(Timer* const baseTimer = nullptr, const bool running = false);
		Timer* const getBaseTimer() const;
		void setBaseTimer(Timer* const baseTimer);
		const double getTime() const;
		void setTime(const double time);
		void start();
		void pause();
		void stop();
		void reset();
	private:
		Timer* m_baseTimer = nullptr;
		bool m_running = false;
		double m_startTime = 0.0;
		double m_recordedTime = 0.0;

		const double getBaseTime() const;
	};
}
