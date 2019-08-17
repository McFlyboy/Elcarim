#include "Camera.hpp"

#include "Renderer.hpp"

namespace Elcarim::Objects {
	const float Camera::PROJECTION_RESOLUTION_WIDTH = 512.0f;
	const float Camera::PROJECTION_RESOLUTION_HEIGHT = 288.0f;

	glm::vec2 Camera::getUpperLeftCorner() {
		return glm::vec2(-PROJECTION_RESOLUTION_WIDTH, PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
	}
	glm::vec2 Camera::getLowerLeftCorner() {
		return glm::vec2(-PROJECTION_RESOLUTION_WIDTH, -PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
	}
	glm::vec2 Camera::getUpperRightCorner() {
		return glm::vec2(PROJECTION_RESOLUTION_WIDTH, PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
	}
	glm::vec2 Camera::getLowerRightCorner() {
		return glm::vec2(PROJECTION_RESOLUTION_WIDTH, -PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
	}
	glm::vec2 Camera::getUpperEdge() {
		return glm::vec2(0.0f, PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
	}
	glm::vec2 Camera::getLowerEdge() {
		return glm::vec2(0.0f, -PROJECTION_RESOLUTION_HEIGHT) / 2.0f;
	}
	glm::vec2 Camera::getLeftEdge() {
		return glm::vec2(-PROJECTION_RESOLUTION_WIDTH, 0.0f) / 2.0f;
	}
	glm::vec2 Camera::getRightEdge() {
		return glm::vec2(PROJECTION_RESOLUTION_WIDTH, 0.0f) / 2.0f;
	}
}
