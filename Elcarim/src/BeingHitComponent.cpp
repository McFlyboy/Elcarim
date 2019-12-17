#include "BeingHitComponent.hpp"

namespace Elcarim::Objects::Components {
	bool BeingHitComponent::isBeingHit() const {
		return m_beingHit;
	}
	void BeingHitComponent::setBeingHit(const bool hitting) {
		m_beingHit = hitting;
	}
}
