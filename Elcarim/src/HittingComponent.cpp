#include "HittingComponent.hpp"

#include "Math.hpp"

namespace Elcarim::Objects::Components {
	HittingComponent::HittingComponent(float& xDirectionRef) : m_xDirectionRef(xDirectionRef) {}
	bool HittingComponent::isHitting() const {
		return m_hitting;
	}
	void HittingComponent::setHitting(const bool hitting) {
		m_hitting = hitting;
	}
	const glm::vec2 HittingComponent::getHitDirection() {
		return glm::normalize(glm::vec2(Util::Math::getSign(m_hitXDirection), 2.0f)) * (m_xDirectionRef != 0.0f ? 440.0f : 350.0f);
	}
	void HittingComponent::updateHitDirection() {
		if (m_xDirectionRef != 0.0f) {
			m_hitXDirection = m_xDirectionRef;
		}
	}
}
