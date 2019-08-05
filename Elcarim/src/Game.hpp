#pragma once

#include <string>

#include "ErrorHandler.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Gamepad.hpp"
#include "Model.hpp"
#include "Models.hpp"
#include "Texture.hpp"
#include "GameObject.hpp"

namespace Elcarim {
	class Game {
	public:
		static const char* const TITLE;

		bool run();
		~Game();
	private:
		ErrorHandler* m_errorHandler = nullptr;
		Window* m_window = nullptr;
		Graphics::Renderer* m_renderer = nullptr;
		Input::Device::Keyboard* m_keyboard = nullptr;
		Input::Device::Mouse* m_mouse = nullptr;
		Input::Device::Gamepad* m_gamepad = nullptr;
		Graphics::Model* m_square = nullptr;
		Graphics::Texture* m_texture = nullptr;
		Objects::GameObject m_niam;

		bool start();
		bool update();
		void render();
	};
}
