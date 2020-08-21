#include "Game.h"
#include "glew.h"
#include "glfw3.h"

namespace Graficos1 {
	Game::Game() {

	}
	Game::~Game() {
		if (gb)
			delete gb;
	}
	void Game::Play() {
		gb = new GameBase();
		if (gb)
			gb->Play();

	}
	void Game::Stop() {

	}
}