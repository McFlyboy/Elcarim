#pragma once

#include "GameObject.hpp"

#include <glm/glm.hpp>

#include "Model.hpp"
#include "Texture.hpp"

namespace Elcarim::Objects {
	class Background : public GameObject {
	public:
		Background(Graphics::Model* const model, Graphics::Texture* const texture);
	};
}
