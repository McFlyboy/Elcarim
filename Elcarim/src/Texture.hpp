#pragma once

#include <string>

namespace Elcarim {
	namespace Graphics {
		class Texture {
		public:
			Texture(const std::string& filename);
			void bind() const;
			int getWidth() const;
			int getHeight() const;
			int getColorComp() const;
			static void unbind();
		private:
			unsigned int m_texture = 0;
			int m_width = 0;
			int m_height = 0;
			int m_colorComp = 0;
		};
	}
}
