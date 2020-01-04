#pragma once

#include "Component.hpp"

#include <glm/glm.hpp>

namespace Elcarim::Objects::Components {
	class ColliderComponent : public Component {
	public:
		ColliderComponent(glm::vec2& center);
		glm::vec2& getCenter();
		float getRadius() const;
		void setRadius(float radius);
		bool isColliding(ColliderComponent& cc);
	private:
		glm::vec2& m_center;
		float m_radius;
	};
}
