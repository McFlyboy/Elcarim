#pragma once

#include "Component.hpp"

#include <glm/glm.hpp>

namespace Elcarim::Objects::Components {
	class CollisionComponent : public Component {
	public:
		CollisionComponent(glm::vec2& center);
		glm::vec2& getCenter();
		float getRadius() const;
		void setRadius(float radius);
		bool isColliding(CollisionComponent& cc);
	private:
		glm::vec2& m_center;
		float m_radius;
	};
}
