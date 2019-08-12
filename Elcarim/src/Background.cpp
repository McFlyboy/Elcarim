#include "Background.hpp"

#include "Renderer.hpp"
#include "TexturedModelComponent.hpp"

namespace Elcarim {
	namespace Objects {
		Background::Background(Graphics::Model* const model, Graphics::Texture* const texture) {
			auto& transformation = getTransformation();
			transformation.getPosition() = glm::vec2(Graphics::Renderer::PROJECTION_RESOLUTION_WIDTH / 2.0f, Graphics::Renderer::PROJECTION_RESOLUTION_HEIGHT / 2.0f);
			transformation.setScale(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));
			addComponent(new Components::TexturedModelComponent(model, texture));
		}
	}
}
