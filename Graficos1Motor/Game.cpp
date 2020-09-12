#include "Game.h"

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
			gb->Play(1024, 768, "Coco", NULL);

	}
	void Game::Stop() {

	}
}