#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "ErrorHandler.hpp"
#include "ResourceLoader.hpp"

namespace Elcarim {
	namespace Util {
		uint8_t* ResourceLoader::loadImage(std::string filename, int& width, int& height, int& colorComp) {
			filename.insert(0, "assets/images/");
			uint8_t* imgData = stbi_load(filename.c_str(), &width, &height, &colorComp, STBI_rgb_alpha);
			if (!imgData) {
				ErrorHandler::getInstance()->write("Failed to load image: " + filename + "\n");
			}
			return imgData;
		}
		void ResourceLoader::freeImage(uint8_t* imgData) {
			stbi_image_free(imgData);
		}
	}
}
