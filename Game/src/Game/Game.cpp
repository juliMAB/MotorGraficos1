#include "Game.h"
#include <time.h>
#include <iostream>
#include "../src/Timer/Timer.h"

namespace Graficos1 {

	Game::Game():GameBase() {
	}
	Game::~Game() {
		if (_shape != NULL) {
			delete _shape;
			_shape = NULL;
		}
	}
	void Game::Start() {
		StartEngine(1366,768, "Coco");

		_shape = new Shape(GetRenderer(), NULL);
		_shape->InitShape(TypeShape::Cube, TypeShader::Colour);
		_shape->CreateShape();
		_shape->SetScale(0.33f, 0.33f, 0.33f);
	}
	void Game::Play() {
		UpdateEngine();
	}
	void Game::Update() {
		GetWindow()->ClearWindow(0.5f, 0.5f, 0.5f, 1.0f);

		_shape->SetRotY(_shape->rotationVec.y + 0.01f);
		_shape->SetRotX(_shape->rotationVec.x + 0.01f);
		
		_shape->DrawShape();
		
		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}