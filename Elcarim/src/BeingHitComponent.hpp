#pragma once

#include "Component.hpp"

namespace Elcarim::Objects::Components {
	class BeingHitComponent : public Component {
	public:
		bool isBeingHit() const;
		void setBeingHit(const bool hitting);
	private:
		bool m_beingHit = false;
	};
}
