#include "CollisionComponent.hpp"

namespace Elcarim::Objects::Components {
	CollisionComponent::CollisionComponent(glm::vec2& center) :
		m_center(center),
		m_radius(0.0f)
	{}
	glm::vec2& CollisionComponent::getCenter() {
		return m_center;
	}
	float CollisionComponent::getRadius() const {
		return m_radius;
	}
	void CollisionComponent::setRadius(float radius) {
		m_radius = radius;
	}
	bool CollisionComponent::isColliding(CollisionComponent& cc) {
		float distance = glm::length(cc.m_center - m_center);
		return distance < m_radius + cc.m_radius;
	}
}
