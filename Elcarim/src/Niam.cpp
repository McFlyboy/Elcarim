#include "Niam.hpp"

#include "TexturedModelComponent.hpp"

namespace Elcarim {
	namespace Objects {
		Niam::Niam(const glm::vec2& position, Graphics::Model* const model, Graphics::Texture* const texture) {
			auto& transformation = getTransformation();
			transformation.getPosition() = position;
			transformation.setScale(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));
			addComponent(new Components::TexturedModelComponent(model, texture));
		}
	}
}
