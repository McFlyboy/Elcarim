#pragma once

#include "GameObject.hpp"

#include <glm/glm.hpp>

#include "Model.hpp"
#include "Texture.hpp"

namespace Elcarim {
	namespace Objects {
		class Niam : public GameObject {
		public:
			Niam(const glm::vec2& position, Graphics::Model* const model, Graphics::Texture* const texture);
		};
	}
}
