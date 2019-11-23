#pragma once

#include "Color.hpp"
#include "Color3.hpp"

namespace Elcarim::Graphics {
	struct Color3;
	struct Color4 : Color<4u> {
		float& r = operator[](0);
		float& g = operator[](1);
		float& b = operator[](2);
		float& a = operator[](3);

		Color4(const float r = 0.0f, const float g = 0.0f, const float b = 0.0f, const float a = 0.0f);
		Color4(const unsigned int color);
		Color4(Color<4u>&& color);
		Color4(const Color3& color, float alpha = 1.0f);
	};
}
