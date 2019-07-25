#include <GLFW/glfw3.h>

#include "Time.hpp"

namespace Elcarim {
	namespace Timing {
		Time* Time::s_instance = nullptr;

		Time::Time() {}
		double Time::getCurrentTime() {
			return glfwGetTime();
		}
		Time::~Time() {
			s_instance = nullptr;
		}
		Time* Time::getInstance() {
			if (!s_instance) {
				s_instance = new Time();
			}
			return s_instance;
		}
	}
}
