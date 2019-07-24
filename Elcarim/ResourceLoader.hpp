#pragma once

namespace Elcarim {
	namespace Util {
		namespace ResourceLoader {
			unsigned char* loadImage(std::string filename, int& width, int& height, int& colorComp);
			void freeImage(unsigned char* imgData);
		}
	}
}
