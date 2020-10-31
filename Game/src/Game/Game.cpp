#include "Game.h"

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
		//GetWindow()->MakeWindow(1366, 768, "Coco", NULL);
		//GetWindow()->InitWindow();
		_shape = new Shape(GetRenderer(), NULL);
		_shapeSprite = new Sprite(GetRenderer(), NULL);
		
		_shape->InitShape(QUAD, TypeShader::Texture);
		_shape->CreateShape();
		_shapeSprite->LoadTexture("res/textures/img1.jpg");
	}
	void Game::Play() {
		UpdateEngine();
	}
	void Game::Update() {
		GetWindow()->ClearWindow(0.0f, 0.0f, 1.0f, 1.0f);

		_shape->DrawShape();
		_shapeSprite->UseTexture();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}