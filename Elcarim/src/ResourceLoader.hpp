#pragma once

#include <cstdint>

namespace Elcarim {
	namespace Util {
		namespace ResourceLoader {
			uint8_t* loadImage(std::string filename, int& width, int& height, int& colorComp, bool flip);
			void freeImage(uint8_t* imgData);
		}
	}
}
