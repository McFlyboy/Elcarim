#include "TransformationComponent.hpp"

namespace Elcarim {
	namespace Objects {
		namespace Components {
			glm::vec2& TransformationComponent::getPosition() {
				return m_position;
			}
			void TransformationComponent::setPosition(const float x, const float y) {
				m_position.x = x;
				m_position.y = y;
			}
			glm::vec2& TransformationComponent::getScale() {
				return m_scale;
			}
			void TransformationComponent::setScale(const float x, const float y) {
				m_scale.x = x;
				m_scale.y = y;
			}
			float& TransformationComponent::getAngle() {
				return m_angle;
			}
			void TransformationComponent::setAngle(const float angle) {
				m_angle = angle;
			}
		}
	}
}
