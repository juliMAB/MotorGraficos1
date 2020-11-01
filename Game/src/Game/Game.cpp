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


		//_shape->InitShape(QUAD, TypeShader::Texture);
		//_shape->CreateShape();
		//_shapeSprite->LoadTexture("res/textures/yd.png", false);
	
		_sprite->LoadTexture("res/textures/player.png", true);
		_sprite->BlendSprite();
	}
	void Game::Play() {
		UpdateEngine();
	}

	float speed = 10;

		double oldTimer = clock();
	void Game::Update() {
		GetWindow()->ClearWindow(0.0f, 0.0f, 1.0f, 1.0f);

		double timer = clock();
		float dt = (float)((timer - oldTimer) / 1000.0f);
		oldTimer = timer;


		//_shape->DrawShape();
		//_shapeSprite->UseTexture();

		_sprite->DrawTexture();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}