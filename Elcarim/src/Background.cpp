#include "Background.hpp"

#include "TexturedModelComponent.hpp"

namespace Elcarim::Objects {
	Background::Background(Graphics::Model* const model, Graphics::Texture* const texture) {
		auto& transformation = getTransformation();
		transformation.setScale(static_cast<float>(texture->getWidth()) / 2.0f, static_cast<float>(texture->getHeight()) / 2.0f);
		addComponent(new Components::TexturedModelComponent(model, texture));
	}
}
