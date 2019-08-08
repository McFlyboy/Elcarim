#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "Component.hpp"
#include "TransformationComponent.hpp"

namespace Elcarim {
	namespace Objects {
		class GameObject {
		public:
			Components::TransformationComponent& getTransformation();
			void addComponent(const Components::Component& component);
		private:
			Components::TransformationComponent m_transformation;
			std::vector<Components::Component> m_components;
		};
	}
}
