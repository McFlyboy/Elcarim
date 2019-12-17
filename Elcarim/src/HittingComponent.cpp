#include "HittingComponent.hpp"

namespace Elcarim::Objects::Components {
	bool HittingComponent::isHitting() const {
		return m_hitting;
	}
	void HittingComponent::setHitting(const bool hitting) {
		m_hitting = hitting;
	}
}
