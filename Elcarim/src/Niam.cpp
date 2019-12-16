#include "Niam.hpp"

#include "TexturedModelComponent.hpp"
#include "MovementComponent.hpp"
#include "JumpingComponent.hpp"
#include "CollisionComponent.hpp"

namespace Elcarim::Objects {
	Niam::Niam(const glm::vec2& position, Graphics::Model* const model, Graphics::Texture* const texture) {
		auto& transformation = getTransformation();
		transformation.getPosition() = position;
		transformation.setScale(static_cast<float>(texture->getWidth()) / 2.0f, static_cast<float>(texture->getHeight()) / 2.0f);
		addComponent(new Components::TexturedModelComponent(model, texture));
		addComponent(new Components::MovementComponent(transformation.getPosition()));
		auto cc = new Components::CollisionComponent(transformation.getPosition());
		cc->setRadius(transformation.getScale().x * 0.75f);
		addComponent(new Components::JumpingComponent());
		addComponent(cc);
	}
}
