#include "Color3.hpp"

namespace Elcarim::Graphics {
	Color3::Color3(const float r, const float g, const float b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	Color3::Color3(const unsigned int color) {
		r = static_cast<float>((color & 0xFF0000u) >> 16u) / 255.0f;
		g = static_cast<float>((color & 0xFF00u) >> 8u) / 255.0f;
		b = static_cast<float>(color & 0xFFu) / 255.0f;
	}
	Color3::Color3(Color<3u>&& color) {
		r = color[0];
		g = color[1];
		b = color[2];
	}
	Color3::Color3(const Color4& color) {
		r = color.r;
		g = color.g;
		b = color.b;
	}
}
