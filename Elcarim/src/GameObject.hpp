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
			void addComponent(Components::Component* const component);
			template<typename T>
			T* const getFirstComponentOfType() const {
				for (Components::Component* component : m_components) {
					if (T* t = dynamic_cast<T*>(component)) {
						return t;
					}
				}
				return nullptr;
			}
			template<typename T>
			void const getAllComponentsOfType(std::vector<T*>& components) const {
				for (Components::Component* component : m_components) {
					if (T* t = dynamic_cast<T*>(component)) {
						components.push_back(t);
					}
				}
			}
			virtual ~GameObject();
		private:
			Components::TransformationComponent m_transformation;
			std::vector<Components::Component*> m_components;
		};
	}
}
