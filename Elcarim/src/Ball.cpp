#include "Ball.hpp"

#include "TexturedModelComponent.hpp"
#include "MovementComponent.hpp"
#include "CollisionComponent.hpp"

namespace Elcarim::Objects {
	Ball::Ball(const glm::vec2& position, Graphics::Model* const model, Graphics::Texture* const texture) {
		auto& transformation = getTransformation();
		transformation.getPosition() = position;
		transformation.setScale(static_cast<float>(texture->getWidth()) / 2.0f, static_cast<float>(texture->getHeight()) / 2.0f);
		addComponent(new Components::MovementComponent(transformation.getPosition()));
		addComponent(new Components::TexturedModelComponent(model, texture));
		auto cc = new Components::CollisionComponent(transformation.getPosition());
		cc->setRadius(transformation.getScale().x);
		addComponent(cc);
	}
}
