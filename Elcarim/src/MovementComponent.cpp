#include "MovementComponent.hpp"

namespace Elcarim::Objects::Components {
	MovementComponent::MovementComponent(glm::vec2& position) : 
		m_position(position),
		m_velocity(glm::vec2()),
		m_acceleration(glm::vec2())
	{}
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
	void MovementComponent::update(float deltaTime) {
		m_velocity += m_acceleration * deltaTime;
		m_position += m_velocity * deltaTime;
	}
}
