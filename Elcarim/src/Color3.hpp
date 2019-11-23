#pragma once

#include "Color.hpp"
#include "Color4.hpp"

namespace Elcarim::Graphics {
	struct Color4;
	struct Color3 : Color<3u> {
		float& r = operator[](0);
		float& g = operator[](1);
		float& b = operator[](2);

		Color3(const float r = 0.0f, const float g = 0.0f, const float b = 0.0f);
		Color3(const unsigned int color);
		Color3(Color<3u>&& color);
		Color3(const Color4& color);
	};
}
