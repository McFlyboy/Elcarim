#pragma once

namespace Elcarim {
	namespace Math {
		struct Vector2f {
			float x = 0.0f;
			float y = 0.0f;

			Vector2f(const float x = 0.0f, const float y = 0.0f);

			Vector2f operator+(const Vector2f& vec) const;
			void operator+=(const Vector2f& vec);

			Vector2f operator-(const Vector2f& vec) const;
			void operator-=(const Vector2f& vec);

			Vector2f operator*(const float scalar) const;
			friend Vector2f operator*(const float scalar, const Vector2f& vec);
			void operator*=(const float scalar);

			Vector2f operator/(const float scalar) const;
			friend Vector2f operator/(const float scalar, const Vector2f& vec);
			void operator/=(const float scalar);

			Vector2f getDot(const Vector2f& vec) const;

			float getLength() const;

			Vector2f getNormalized() const;
			void normalize();
		};
	}
}
