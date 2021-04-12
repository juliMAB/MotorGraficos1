#include "Game.h"
#include <time.h>
#include <iostream>
#include "../src/Timer/Timer.h"
#include <time.h>

namespace Graficos1 {

	Game::Game() :GameBase() {
	}
	Game::~Game() {
		if (_shape != NULL) {
			delete _shape;
			_shape = NULL;
		}
		if (_shape != NULL) {
			delete _shape2;
			_shape2 = NULL;
		}
		if (_camera != NULL) {
			delete _camera;
			_camera = NULL;
		}
		if (_light != NULL) {
			delete _light;
			_light = NULL;
		}
	}
	void Game::Start() {
		StartEngine(1366, 768, "Coco");
		srand(time(NULL));

		_camera = new Camera();
		_camera->InitCamera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);
		_camera->SetPos(0.0f, 0.0f, 0.0f);
		GetRenderer()->SetView(_camera->CalculateViewMatrix());

		_shape = new Shape(GetRenderer(), NULL);
		_shape->InitShape(TypeShape::Cube, TypeShader::Colour);
		_shape->CreateShape();
		_shape->SetScale(0.33f, 0.33f, 0.33f);
		_shape->SetPos(0.0f, 0.0f, -3.0f);

		_shape2 = new Shape(GetRenderer(), NULL);
		_shape2->InitShape(TypeShape::Cube, TypeShader::Colour);
		_shape2->CreateShape();
		_shape2->SetScale(0.33f, 0.33f, 0.33f);
		_shape2->SetPos(0.0f, 1.0f, -3.0f);
		
		_light = new Light(GetRenderer(), 1.0f, 1.0f, 1.0f, 0.2f, 0.0f,1.0f,0.0f, 1.0f);
	}
	void Game::Play() {
		UpdateEngine();
	}

	float speed = 5.0f;
	float speedRotationCamera = 50.0f;
	float timer = 0.0f;
	bool usingLight = true;

	float timerLight = 0.0f;
	const float maxTimerLight = 1.5f;
	void Game::Update() {
		GetWindow()->ClearWindow(0.5f, 0.5f, 0.5f, 1.0f);
		GetRenderer()->SetView(_camera->CalculateViewMatrix());
		_light->UseLight();	
		Timer::DeltaTime(timer);


		if (Input::GetKeyDown(Keycode::W)) {
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y + (speed * timer), _camera->positionVec.z);
			//std::cout << "Y: " << _camera->positionVec.y << std::endl;
		}
		else if (Input::GetKeyDown(Keycode::S)) {
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y - (speed * timer), _camera->positionVec.z);
			//std::cout << "Y: " << _camera->positionVec.y << std::endl;
		}

		if (Input::GetKeyDown(Keycode::A)) {
			_camera->SetPos(_camera->positionVec.x - (speed * timer), _camera->positionVec.y, _camera->positionVec.z);
			//std::cout << "X: " << _camera->positionVec.x << std::endl;
		}
		else if (Input::GetKeyDown(Keycode::D)) {
			_camera->SetPos(_camera->positionVec.x + (speed * timer), _camera->positionVec.y, _camera->positionVec.z);
			//std::cout << "X: " << _camera->positionVec.x << std::endl;
		}
		if (Input::GetKeyDown(Keycode::Q)) {
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y, _camera->positionVec.z + (speed * timer));
			//std::cout << "Z: " << _camera->positionVec.z << std::endl;
		}
		else if (Input::GetKeyDown(Keycode::E)) {
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y, _camera->positionVec.z - (speed * timer));
			//std::cout << "Z: " << _camera->positionVec.z << std::endl;
		}
		if (Input::GetMouseButtonDown(MouseButtons::LEFT_MOUSE_BUTTON)) {
			_camera->SetPitch(_camera->GetPitch() + (speedRotationCamera * timer));
			//std::cout << "Pitch: " << _camera->GetPitch() << std::endl;
		}
		else if (Input::GetMouseButtonDown(MouseButtons::RIGHT_MOUSE_BUTTON)) {
			_camera->SetPitch(_camera->GetPitch() - (speedRotationCamera * timer));
			//std::cout << "Pitch: " << _camera->GetPitch() << std::endl;
		}

		if (Input::GetKeyDown(Keycode::R)) {
			_camera->SetYaw(_camera->GetYaw() + (speedRotationCamera * timer));
			//std::cout << "Yaw: " << _camera->GetYaw() << std::endl;
		}
		else if (Input::GetKeyDown(Keycode::T)) {
			_camera->SetYaw(_camera->GetYaw() - (speedRotationCamera * timer));
			//std::cout << "Yaw: " << _camera->GetYaw() << std::endl;
		}


		if (Input::GetKeyDown(Keycode::ENTER))
			system("cls");
		if (Input::GetKeyDown(Keycode::ALPHA0)) {
			_camera->SetPos(0.0f, 0.0f, 0.0f);
			_camera->SetPitch(0.0f);
			_camera->SetYaw(-90.0f);
		}
		

		_shape->DrawShape();
		_shape2->DrawShape();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}