#include "Game.h"
#include <time.h>
#include <iostream>
namespace Graficos1 {
	Game::Game():GameBase() {

	}
	Game::~Game() {
		if (_sprite != NULL) {
			delete _sprite;
			_sprite = NULL;
		}
	}
	void Game::Start() {
		StartEngine();
		_sprite = new Sprite(GetRenderer(), NULL);
	
		_sprite->LoadTexture("res/textures/player.png", true);
		_sprite->SetAnimation(6,0.05f);
		_sprite->BlendSprite();
	}
	void Game::Play() {
		UpdateEngine();
	}

	float speed = 10;

	void Game::Update() {
		GetWindow()->ClearWindow(0.0f, 0.0f, 1.0f, 1.0f);

		_sprite->UpdateAnimation();
		_sprite->DrawTexture();
		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}