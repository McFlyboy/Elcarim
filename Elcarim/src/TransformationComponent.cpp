#include "TransformationComponent.hpp"

namespace Elcarim {
	namespace Objects {
		namespace Components {
			glm::vec2& TransformationComponent::getPosition() {
				return m_position;
			}
			glm::vec2& TransformationComponent::getScale() {
				return m_scale;
			}
			float& TransformationComponent::getAngle() {
				return m_angle;
			}
		}
	}
}
