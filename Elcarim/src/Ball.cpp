#include "Ball.hpp"

#include "TexturedModelComponent.hpp"
#include "MovementComponent.hpp"

namespace Elcarim::Objects {
	Ball::Ball(const glm::vec2& position, Graphics::Model* const model, Graphics::Texture* const texture) {
		auto& transformation = getTransformation();
		transformation.getPosition() = position;
		transformation.setScale(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));
		addComponent(new Components::MovementComponent());
		addComponent(new Components::TexturedModelComponent(model, texture));
	}
}