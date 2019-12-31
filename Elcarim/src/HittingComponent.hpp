#pragma once

#include "Component.hpp"

#include <glm/glm.hpp>

namespace Elcarim::Objects::Components {
	class HittingComponent : public Component {
	public:
		HittingComponent(float& xDirectionRef);
		bool isHitting() const;
		void setHitting(const bool hitting);
		const glm::vec2 getHitDirection();
		void updateHitDirection();
	private:
		bool m_hitting = false;
		float m_hitXDirection = 1.0f;
		float& m_xDirectionRef;
	};
}
