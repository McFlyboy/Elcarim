#include "Background.hpp"

#include "TexturedModelComponent.hpp"

namespace Elcarim::Objects {
	Background::Background(Graphics::Model* const model, Graphics::Texture* const texture) {
		auto& transformation = getTransformation();
		transformation.setScale(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));
		addComponent(new Components::TexturedModelComponent(model, texture));
	}
}
