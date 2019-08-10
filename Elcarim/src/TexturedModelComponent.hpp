#pragma once

#include "Model.hpp"
#include "Texture.hpp"
#include "Component.hpp"

namespace Elcarim {
	namespace Objects {
		namespace Components {
			class TexturedModelComponent : public Component {
			public:
				TexturedModelComponent(Graphics::Model* const model = nullptr, Graphics::Texture* const texture = nullptr);
				Graphics::Model* const getModel() const;
				void setModel(Graphics::Model* model);
				Graphics::Texture* const getTexture() const;
				void setTexture(Graphics::Texture* texture);
			private:
				Graphics::Model* m_model = nullptr;
				Graphics::Texture* m_texture = nullptr;
			};
		}
	}
}
