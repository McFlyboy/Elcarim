#pragma once

#include <GLFW/glfw3.h>

namespace Elcarim {
	namespace Input {
		namespace Device {
			class Mouse {
			public:
				Mouse(GLFWwindow* const window);
				void setInvisible(const bool invisible);
				~Mouse();
			private:
				GLFWwindow* m_window = nullptr;
			};
		}
	}
}
