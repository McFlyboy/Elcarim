#include "Color4.hpp"

namespace Elcarim::Graphics {
	Color4::Color4(const float r, const float g, const float b, const float a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	Color4::Color4(const unsigned int color) {
		r = static_cast<float>((color & 0xFF0000u) >> 16u) / 255.0f;
		g = static_cast<float>((color & 0xFF00u) >> 8u) / 255.0f;
		b = static_cast<float>(color & 0xFFu) / 255.0f;
		a = static_cast<float>((color & 0xFF000000u) >> 24u) / 255.0f;
	}
	Color4::Color4(Color<4u>&& color) {
		r = color[0];
		g = color[1];
		b = color[2];
		a = color[3];
	}
	Color4::Color4(const Color3& color, float alpha) {
		r = color.r;
		g = color.g;
		b = color.b;
		a = alpha;
	}
}
