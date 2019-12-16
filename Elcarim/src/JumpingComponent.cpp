#include "JumpingComponent.hpp"

namespace Elcarim::Objects::Components {
	bool JumpingComponent::isJumping() const {
		return m_jumping;
	}
	void JumpingComponent::setJumping(const bool jumping) {
		m_jumping = jumping;
	}
}
