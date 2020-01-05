#if false && defined(_WIN32)
#pragma comment(linker, "/subsystem:WINDOWS")
#pragma comment(linker, "/entry:mainCRTStartup")
#endif

#include "Game.hpp"
#include <iostream>

int main() {
	Elcarim::Game* game = new Elcarim::Game();
	int quitStatus = game->run() ? 0 : 1;
	delete game;
	game = nullptr;
	return quitStatus;
}
