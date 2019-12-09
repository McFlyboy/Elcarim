#pragma once

#include <algorithm>

namespace Elcarim::Graphics {
	template<unsigned int N>
	struct Color {
		float& operator[](unsigned int index) {
			return components[index];
		}

		Color<N> capped(const Color<N>& color) const {
			Color<N> result;
			for (int i = 0; i < N; i++) {
				result[i] = std::min(std::max(color.components[i], 0.0f), 1.0f);
			}
			return result;
		}
		void cap() {
			for (int i = 0; i < N; i++) {
				components[i] = std::min(std::max(components[i], 0.0f), 1.0f);
			}
		}

		Color<N> operator+(const Color<N>&& color) const { return operator+(color); }
		Color<N> operator+(const Color<N>& color) const {
			Color<N> result;
			for (int i = 0; i < N; i++) {
				result[i] = components[i] + color.components[i];
			}
			return result;
		}
		void operator+=(const Color<N>&& color) { operator+=(color); }
		void operator+=(const Color<N>& color) {
			for (int i = 0; i < N; i++) {
				components[i] += color.components[i];
			}
		}

		Color<N> operator-(const Color<N>&& color) const { return operator-(color); }
		Color<N> operator-(const Color<N>& color) const {
			Color<N> result;
			for (int i = 0; i < N; i++) {
				result[i] = components[i] - color.components[i];
			}
			return result;
		}
		void operator-=(const Color<N>&& color) { operator-=(color); }
		void operator-=(const Color<N>& color) {
			for (int i = 0; i < N; i++) {
				components[i] -= color.components[i];
			}
		}

		Color<N> operator*(const float mul) const {
			Color<N> result;
			for (int i = 0; i < N; i++) {
				result[i] = components[i] * mul;
			}
			return result;
		}
		friend Color<N> operator*(const float mul, Color<N>& color) {
			Color<N> result;
			for (int i = 0; i < N; i++) {
				result[i] = color.components[i] * mul;
			}
			return result;
		}
		void operator*=(const float mul) {
			for (int i = 0; i < N; i++) {
				components[i] *= mul;
			}
		}

		Color<N> operator/(const float div) const {
			Color<N> result;
			if (div == 0.0f) {
				return result;
			}
			for (int i = 0; i < N; i++) {
				result[i] = components[i] / div;
			}
			return result;
		}
		friend Color<N> operator/(const float div, Color<N>& color) {
			Color<N> result;
			if (div == 0.0f) {
				return result;
			}
			for (int i = 0; i < N; i++) {
				result[i] = color.components[i] / div;
			}
			return result;
		}
		void operator/=(const float div) {
			if (div == 0.0f) {
				for (int i = 0; i < N; i++) {
					components[i] = 0.0f;
				}
				return;
			}
			for (int i = 0; i < N; i++) {
				components[i] /= div;
			}
		}
	private:
		float components[N] = {};
	};
}
