#include "Game.h"
#include <time.h>
#include <iostream>
namespace Graficos1 {
	Game::Game():GameBase() {

	}
	Game::~Game() {
		if (_shape != NULL) {
			delete _shape;
			_shape = NULL;
		}
		if (_shapeSprite != NULL) {
			delete _shapeSprite;
			_shapeSprite = NULL;
		}
	}
	void Game::Start() {
		StartEngine();
		_shape = new Shape(GetRenderer(), NULL);
		_shapeSprite = new Sprite(GetRenderer(), NULL);
		_shape2 = new Shape(GetRenderer(), NULL);
		_shapeSprite2 = new Sprite(GetRenderer(), NULL);

	
		_shape2->InitShape(QUAD, TypeShader::Texture);
		_shape2->CreateShape();
		_shapeSprite2->LoadTexture("res/textures/Sun.png");

		_shape2->SetPos(-0.5f, _shape2->positionVec.y, 0);
		_shape->SetPos(0.5f, _shape->positionVec.y, 0);
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

		if (Input::GetKey(Keycode::D))
			_shape->SetPos(_shape->positionVec.x + (speed * dt), _shape->positionVec.y, _shape->positionVec.z);

		_shape2->DrawShape();
		_shapeSprite2->UseTexture();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}