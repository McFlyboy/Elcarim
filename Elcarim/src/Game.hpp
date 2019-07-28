#pragma once

#include "ErrorHandler.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Gamepad.hpp"
#include "Model.hpp"

namespace Elcarim {
	class Game {
	public:
		static const char* const TITLE;

		bool run();
		~Game();
	private:
		Util::ErrorHandler* m_errorHandler = nullptr;
		Window* m_window = nullptr;
		Graphics::Renderer* m_renderer = nullptr;
		Input::Device::Keyboard* m_keyboard = nullptr;
		Input::Device::Mouse* m_mouse = nullptr;
		Input::Device::Gamepad* m_gamepad = nullptr;
		Graphics::Model* m_model = nullptr;

		bool start();
		bool update();
		void render();
	};
}
