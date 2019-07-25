#pragma once

namespace Elcarim {
	namespace Timing {
		class Time {
		public:
			double getCurrentTime();
			~Time();
			static Time* getInstance();
		private:
			static Time* s_instance;

			Time();
		};
	}
}
