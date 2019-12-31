#pragma once

#include "GameObject.hpp"

#include <glm/glm.hpp>

#include "Model.hpp"
#include "Texture.hpp"

namespace Elcarim::Objects {
	class Shot : public GameObject {
	public:
		Shot(const glm::vec2& position, Graphics::Model* const model, Graphics::Texture* const texture);
	};
}
