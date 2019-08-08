#include "GameObject.hpp"

namespace Elcarim {
	namespace Objects {
		Components::TransformationComponent& GameObject::getTransformation() {
			return m_transformation;
		}
		void GameObject::addComponent(const Components::Component& component) {
			m_components.push_back(component);
		}
	}
}
