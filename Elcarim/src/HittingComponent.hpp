#pragma once

#include "Component.hpp"

namespace Elcarim::Objects::Components {
	class HittingComponent : public Component {
	public:
		bool isHitting() const;
		void setHitting(const bool hitting);
	private:
		bool m_hitting = false;
	};
}
