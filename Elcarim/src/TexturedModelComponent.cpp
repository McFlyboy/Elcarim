#include "TexturedModelComponent.hpp"

namespace Elcarim::Objects::Components {
	TexturedModelComponent::TexturedModelComponent(Graphics::Model* const model, Graphics::Texture* const texture) :
		m_model(model),
		m_texture(texture)
	{}
	Graphics::Model* const TexturedModelComponent::getModel() const {
		return m_model;
	}
	void TexturedModelComponent::setModel(Graphics::Model* model) {
		m_model = model;
	}
	Graphics::Texture* const TexturedModelComponent::getTexture() const {
		return m_texture;
	}
	void TexturedModelComponent::setTexture(Graphics::Texture* texture) {
		m_texture = texture;
	}
}
