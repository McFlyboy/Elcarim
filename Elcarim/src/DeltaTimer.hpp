#pragma once

#include "Timer.hpp"

namespace Elcarim::Timing {
	class DeltaTimer {
	public:
		DeltaTimer(Timer* const baseTimer);
		Timer* const getBaseTimer() const;
		void setBaseTimer(Timer* const baseTimer);
		const float getDeltaTime();
	private:
		Timer* m_baseTimer = nullptr;
		double m_startTime = 0.0;

		const double getBaseTime() const;
	};
}
