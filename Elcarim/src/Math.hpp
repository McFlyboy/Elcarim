#pragma once

#define _USE_MATH_DEFINES
#include <corecrt_math_defines.h>

namespace Elcarim::Util::Math {
	const float getSign(float value);
	constexpr float rad(const float value) {
		return value / 180.0f * static_cast<float>(M_PI);
	}
}
