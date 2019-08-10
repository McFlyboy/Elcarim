#include "Texture.hpp"

#include <cstdint>

#include <glad/glad.h>

#include "ResourceLoader.hpp"

namespace Elcarim {
	namespace Graphics {
		Texture::Texture(const std::string& filename) {
			uint8_t* imgData = Util::ResourceLoader::loadImage("textures/" + filename, m_width, m_height, m_colorComp, true);
			glGenTextures(1, &m_texture);
			bind();
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
			Util::ResourceLoader::freeImage(imgData);
		}
		void Texture::bind() const {
			glBindTexture(GL_TEXTURE_2D, m_texture);
		}
		int Texture::getWidth() const {
			return m_width;
		}
		int Texture::getHeight() const {
			return m_height;
		}
		int Texture::getColorComp() const {
			return m_colorComp;
		}
		void Texture::unbind() {
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}
