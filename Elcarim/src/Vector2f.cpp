#include <cmath>

#include "Vector2f.hpp"

namespace Elcarim {
	namespace Math {
		Vector2f::Vector2f(const float x, const float y) : x(x), y(y) {}

		Vector2f Vector2f::operator+(const Vector2f& vec) const {
			return Vector2f(x + vec.x, y + vec.y);
		}
		void Vector2f::operator+=(const Vector2f& vec) {
			x += vec.x;
			y += vec.y;
		}

		Vector2f Vector2f::operator-(const Vector2f& vec) const {
			return Vector2f(x - vec.x, y - vec.y);
		}
		void Vector2f::operator-=(const Vector2f& vec) {
			x -= vec.x;
			y -= vec.y;
		}

		Vector2f Vector2f::operator*(const float scalar) const {
			return Vector2f(x * scalar, y * scalar);
		}
		Vector2f operator*(const float scalar, const Vector2f& vec) {
			return Vector2f(vec.x * scalar, vec.y * scalar);
		}
		void Vector2f::operator*=(const float scalar) {
			x *= scalar;
			y *= scalar;
		}

		Vector2f Vector2f::operator/(const float scalar) const {
			return Vector2f(x / scalar, y / scalar);
		}
		Vector2f operator/(const float scalar, const Vector2f& vec) {
			return Vector2f(vec.x / scalar, vec.y / scalar);
		}
		void Vector2f::operator/=(const float scalar) {
			x /= scalar;
			y /= scalar;
		}

		Vector2f Vector2f::getDot(const Vector2f& vec) const {
			return x * vec.x + y * vec.y;
		}

		float Vector2f::getLength() const {
			return std::sqrtf(x * x + y * y);
		}

		Vector2f Vector2f::getNormalized() const {
			float length = getLength();
			if (length == 0.0f) {
				return Vector2f();
			}
			return Vector2f(x / length, y / length);
		}
		void Vector2f::normalize() {
			float length = getLength();
			if (length == 0.0f) {
				return;
			}
			x /= length;
			y /= length;
		}
	}
}
