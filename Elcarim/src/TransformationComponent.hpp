#pragma once

#include <glm/glm.hpp>

#include "Component.hpp"

namespace Elcarim {
	namespace Objects {
		namespace Components {
			class TransformationComponent : public Component {
			public:
				glm::vec2& getPosition();
				glm::vec2& getScale();
				float& getAngle();
			private:
				glm::vec2 m_position;
				glm::vec2 m_scale = glm::vec2(1.0f, 1.0f);
				float m_angle;
			};
		}
	}
}
