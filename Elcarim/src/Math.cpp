#include "Math.hpp"

namespace Elcarim::Util::Math {
	const float getSign(float value) {
		unsigned int& uintValue = *reinterpret_cast<unsigned int*>(&value);
		uintValue &= 0x80000000u;
		uintValue |= 0x3f800000u;
		return value;
		//return static_cast<float>(((!(static_cast<int>(value) >> (sizeof(int) * 8 - 1))) << 1) - 1);
	}
}
