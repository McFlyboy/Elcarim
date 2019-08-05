#pragma once

#include <glm/glm.hpp>

namespace Elcarim {
	namespace Objects {
		class GameObject {
		public:
			glm::vec2& getPosition();
			glm::vec2& getScale();
			float& getAngle();
		private:
			glm::vec2 position;
			glm::vec2 scale = glm::vec2(1.0f, 1.0f);
			float angle;
		};
	}
}
