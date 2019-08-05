#include "GameObject.hpp"

namespace Elcarim {
	namespace Objects {
		glm::vec2& GameObject::getPosition() {
			return position;
		}
		glm::vec2& GameObject::getScale() {
			return scale;
		}
		float& GameObject::getAngle(){
			return angle;
		}
	}
}
