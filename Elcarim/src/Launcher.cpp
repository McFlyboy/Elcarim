#if false && defined(_WIN32)
#pragma comment(linker, "/subsystem:WINDOWS")
#pragma comment(linker, "/entry:mainCRTStartup")
#endif

#include "Game.hpp"

int main() {
	return Elcarim::Game().run() ? 0 : 1;
}
