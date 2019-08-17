#pragma once

#include "GameObject.hpp"

namespace Elcarim::Objects {
	class Camera : public GameObject {
	public:
		static const float PROJECTION_RESOLUTION_WIDTH;
		static const float PROJECTION_RESOLUTION_HEIGHT;

		static glm::vec2 getUpperLeftCorner();
		static glm::vec2 getLowerLeftCorner();
		static glm::vec2 getUpperRightCorner();
		static glm::vec2 getLowerRightCorner();
		static glm::vec2 getUpperEdge();
		static glm::vec2 getLowerEdge();
		static glm::vec2 getLeftEdge();
		static glm::vec2 getRightEdge();
	};
}
