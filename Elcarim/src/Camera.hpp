#pragma once

#include "GameObject.hpp"

namespace Elcarim::Objects {
	class Camera : public GameObject {
	public:
		static const float PROJECTION_RESOLUTION_WIDTH;
		static const float PROJECTION_RESOLUTION_HEIGHT;

		static constexpr glm::vec2 getUpperLeftCorner() {
			return glm::vec2(-PROJECTION_RESOLUTION_WIDTH, PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
		}
		static constexpr glm::vec2 getLowerLeftCorner() {
			return glm::vec2(-PROJECTION_RESOLUTION_WIDTH, -PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
		}
		static constexpr glm::vec2 getUpperRightCorner() {
			return glm::vec2(PROJECTION_RESOLUTION_WIDTH, PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
		}
		static constexpr glm::vec2 getLowerRightCorner() {
			return glm::vec2(PROJECTION_RESOLUTION_WIDTH, -PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
		}
		static constexpr glm::vec2 getUpperEdge() {
			return glm::vec2(0.0f, PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
		}
		static constexpr glm::vec2 getLowerEdge() {
			return glm::vec2(0.0f, -PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
		}
		static constexpr glm::vec2 getLeftEdge() {
			return glm::vec2(-PROJECTION_RESOLUTION_WIDTH, 0.0f) / 2.0f;
		}
		static constexpr glm::vec2 getRightEdge() {
			return glm::vec2(PROJECTION_RESOLUTION_WIDTH, 0.0f) / 2.0f;
		}
	};
}
