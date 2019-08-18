#pragma once

#include "ErrorHandler.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Keyboard.hpp"
#include "Gamepad.hpp"
#include "SceneManager.hpp"

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
		Input::Devices::Keyboard* m_keyboard = nullptr;
		Input::Devices::Gamepad* m_gamepad = nullptr;
		Scene::SceneManager* m_sceneManager = nullptr;

		bool start();
		bool update();
		void render();
	};
}
