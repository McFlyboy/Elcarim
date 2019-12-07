#include "MovementComponent.hpp"

namespace Elcarim::Objects::Components {
	glm::vec2& MovementComponent::getVelocity() {
		return m_velocity;
	}
	void MovementComponent::setVelocity(const float x, const float y) {
		m_velocity.x = x;
		m_velocity.y = y;
	}
	glm::vec2& MovementComponent::getAcceleration() {
		return m_acceleration;
	}
	void MovementComponent::setAcceleration(const float x, const float y) {
		m_acceleration.x = x;
		m_acceleration.y = y;
	}
}
