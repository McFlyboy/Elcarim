#pragma once

#include "Component.hpp"

namespace Elcarim::Objects::Components {
	class JumpingComponent : public Component {
	public:
		bool isJumping() const;
		void setJumping(const bool jumping);
	private:
		bool m_jumping = false;
	};
}
