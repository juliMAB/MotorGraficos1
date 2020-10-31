#include "Game.h"

namespace Graficos1 {
	Game::Game() {

	}
	Game::~Game() {
		if (gb != NULL)
			delete gb;
	}
	void Game::Play() {
		gb = new GameBase();
		if (gb != NULL)
			gb->Play(1366, 768, "Coco", NULL);

	}
	void Game::Stop() {

	}
}