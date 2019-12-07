#pragma once

#include <glm/glm.hpp>

#include "Component.hpp"

namespace Elcarim::Objects::Components {
	class MovementComponent : public Component {
	public:
		glm::vec2& getVelocity();
		void setVelocity(const float x, const float y);
		glm::vec2& getAcceleration();
		void setAcceleration(const float x, const float y);
	private:
		glm::vec2 m_velocity = glm::vec2();
		glm::vec2 m_acceleration = glm::vec2();
	};
}
