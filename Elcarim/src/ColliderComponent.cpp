#include "ColliderComponent.hpp"

namespace Elcarim::Objects::Components {
	ColliderComponent::ColliderComponent(glm::vec2& center) :
		m_center(center),
		m_radius(0.0f)
	{}
	glm::vec2& ColliderComponent::getCenter() {
		return m_center;
	}
	float ColliderComponent::getRadius() const {
		return m_radius;
	}
	void ColliderComponent::setRadius(float radius) {
		m_radius = radius;
	}
	bool ColliderComponent::isColliding(ColliderComponent& cc) {
		float distance = glm::length(cc.m_center - m_center);
		return distance < m_radius + cc.m_radius;
	}
}
