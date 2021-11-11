#include "Game.h"
#include <time.h>
#include <iostream>
#include <time.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Coco {

	Game::Game() :GameBase() {}
	Game::~Game() {
		if (_shape != NULL) {
			delete _shape;
			_shape = NULL;
		}
		if (_camera != NULL) {
			delete _camera;
			_camera = NULL;
		}
	}

	void Game::Start() {
		StartEngine(1366,768, "Coco");
		srand(time(NULL));

		_camera = new Camera(GetRenderer());

		//_camera->SetEntity(_shape);

		_shape = new Shape(GetRenderer());
		_shape->InitShape(TypeShape::Cube, TypeShader::Colour);
		_shape->SetScale(0.33f, 0.33f, 0.33f);
		_shape->SetPos(-1.0f, -1, 5);
		_shape->LoadTexture("res/textures/", "img1.jpg");

	}
	void Game::Play() {
		UpdateEngine();
	}

	float speed = 5.0f;
	float speedRotationCamera = 100.0f;
	bool usingLight = true;

	float timerLight = 0.0f;
	const float maxTimerLight = 1.5f;

	float rotY = 0;

	bool inFirstPersonMode = false;

	float posXModel = 0.0f;
	float posXFootModel = 0.0f;

	void Game::Update(float deltaTime) {
		GetWindow()->ClearWindow(0.15f, 0.15f, 0.15f, 1.0f);

		
		_camera->LookAt(_camera->transform.position + _camera->transform.forward);

		_camera->UseCamera();
		GetRenderer()->SetView(_camera->GetViewMatrix());

		_shape->DrawShape();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}