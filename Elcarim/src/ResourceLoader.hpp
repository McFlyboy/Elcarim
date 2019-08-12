#pragma once

#include <cstdint>
#include <string>

namespace Elcarim::Util {
	namespace ResourceLoader {
		uint8_t* loadImage(const std::string& filename, int& width, int& height, int& colorComp, bool flip);
		void freeImage(uint8_t* imgData);
	}
}
