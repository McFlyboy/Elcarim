#include "GameObject.hpp"

namespace Elcarim {
	namespace Objects {
		Components::TransformationComponent& GameObject::getTransformation() {
			return m_transformation;
		}
		void GameObject::addComponent(Components::Component* const component) {
			m_components.push_back(component);
		}
		GameObject::~GameObject() {
			for (Components::Component*& component : m_components) {
				delete component;
				component = nullptr;
			}
		}
	}
}
