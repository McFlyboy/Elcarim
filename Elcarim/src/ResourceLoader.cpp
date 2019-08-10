#include "ResourceLoader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "ErrorHandler.hpp"

namespace Elcarim {
	namespace Util {
		uint8_t* ResourceLoader::loadImage(const std::string& filename, int& width, int& height, int& colorComp, bool flip) {
			stbi_set_flip_vertically_on_load(flip);
			uint8_t* imgData = stbi_load(("assets/images/" + filename).c_str(), &width, &height, &colorComp, STBI_rgb_alpha);
			if (!imgData) {
				ErrorHandler::getInstance()->write("Failed to load image: assets/images/" + filename + "\n");
			}
			return imgData;
		}
		void ResourceLoader::freeImage(uint8_t* imgData) {
			stbi_image_free(imgData);
		}
	}
}
