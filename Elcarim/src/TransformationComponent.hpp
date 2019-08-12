#pragma once

#include <glm/glm.hpp>

#include "Component.hpp"

namespace Elcarim {
	namespace Objects {
		namespace Components {
			class TransformationComponent : public Component {
			public:
				glm::vec2& getPosition();
				void setPosition(const float x, const float y);
				glm::vec2& getScale();
				void setScale(const float x, const float y);
				float& getAngle();
				void setAngle(const float angle);
			private:
				glm::vec2 m_position = glm::vec2();
				glm::vec2 m_scale = glm::vec2(1.0f, 1.0f);
				float m_angle = 0.0f;
			};
		}
	}
}
