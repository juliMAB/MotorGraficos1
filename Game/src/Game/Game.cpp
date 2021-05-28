#include "Game.h"
#include <time.h>
#include <iostream>
#include "../src/Timer/Timer.h"
#include <time.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Coco {

	Game::Game() :GameBase() {}
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
		if (_goldMaterial != NULL) {
			delete _goldMaterial;
			_goldMaterial = NULL;
		}
		if (_obsidianMaterial != NULL) {
			delete _obsidianMaterial;
			_obsidianMaterial = NULL;
		}
	}
	void Game::Start() {
		StartEngine(1366, 768, "Coco");
		srand(time(NULL));

		_camera = new Camera(GetRenderer());
		_camera->InitCamera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);
		_camera->SetPos(0.0f, 0.0f, 0.0f);
		GetRenderer()->SetView(_camera->CalculateViewMatrix());

		_goldMaterial = new Material(GetRenderer());
		_goldMaterial->SetAmbient(glm::vec3(0.24725f, 0.1995f, 0.0745f));
		_goldMaterial->SetDiffuse(glm::vec3(0.75164f, 0.60648f, 0.22648f));
		_goldMaterial->SetSpecular(glm::vec3(0.628281f, 0.555802f, 0.366065f));
		_goldMaterial->SetShininess(0.4f);

		_obsidianMaterial = new Material(GetRenderer());
		_obsidianMaterial->SetAmbient(glm::vec3(0.05375f, 0.05f, 0.06625f));
		_obsidianMaterial->SetDiffuse(glm::vec3(0.18275f, 0.17f, 0.22525f));
		_obsidianMaterial->SetSpecular(glm::vec3(0.332741f, 0.328634f, 0.346435f));
		_obsidianMaterial->SetShininess(0.3f);

		_shape = new Shape(GetRenderer());
		_shape->InitShape(TypeShape::Cube, TypeShader::Colour);
		_shape->SetScale(0.33f, 0.33f, 0.33f);
		_shape->SetPos(0.0f, 0.0f, -3.0f);
		_shape->SetMaterial(_goldMaterial);

		_shape2 = new Shape(GetRenderer());
		_shape2->InitShape(TypeShape::Cube, TypeShader::Colour);
		_shape2->SetScale(0.33f, 0.33f, 0.33f);
		_shape2->SetPos(0.0f, 1.0f, -3.0f);
		_shape2->SetMaterial(_obsidianMaterial);

		GetLightManager()->AddLight(TypeOfLight::Point);
		GetLightManager()->AddLight(TypeOfLight::Spot);

		PointLight* _lightAux = GetLightManager()->GetPointLightByIndex(0);
		if (_lightAux != NULL) {
			_lightAux->SetPos(0, 3, -3);
			_lightAux->SetColour(glm::vec3(1.0f, 0.0f, 0.0f));
			_lightAux->SetAmbient(glm::vec3(0.2f, 0.2f, 0.2f));
			_lightAux->SetDiffuse(glm::vec3(0.5f, 0.5f, 0.5f));
			_lightAux->SetSpecular(glm::vec3(1.0f, 1.0f, 1.0f));
			_lightAux->SetConstantLinearQuadratic(1.0f, 0.09f, 0.032f);
		}

		SpotLight* _lightAux2 = GetLightManager()->GetSpotLightByIndex(0);
		if (_lightAux2 != NULL) {
			_lightAux2->SetPos(0, -2, -3);
			_lightAux2->SetColour(glm::vec3(0.0f, 1.0f, 0.0f));
			_lightAux2->SetAmbient(glm::vec3(0.2f, 0.2f, 0.2f));
			_lightAux2->SetDiffuse(glm::vec3(0.5f, 0.5f, 0.5f));
			_lightAux2->SetSpecular(glm::vec3(1.0f, 1.0f, 1.0f));
			_lightAux2->SetConstantLinearQuadratic(1.0f, 0.09f, 0.032f);
			_lightAux2->SetCutOff(3);
			_lightAux2->SetDirection(glm::vec3(0, 1, 0));
		}
		
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

	float rotY = 0;

	void Game::Update() {
		GetWindow()->ClearWindow(0.5f, 0.5f, 0.5f, 1.0f);
		GetRenderer()->SetView(_camera->CalculateViewMatrix());

		Timer::DeltaTime(timer);

		if (Input::GetKeyDown(Keycode::W))
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y + (speed * timer), _camera->positionVec.z);
		else if (Input::GetKeyDown(Keycode::S))
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y - (speed * timer), _camera->positionVec.z);

		if (Input::GetKeyDown(Keycode::A))
			_camera->SetPos(_camera->positionVec.x - (speed * timer), _camera->positionVec.y, _camera->positionVec.z);
		else if (Input::GetKeyDown(Keycode::D))
			_camera->SetPos(_camera->positionVec.x + (speed * timer), _camera->positionVec.y, _camera->positionVec.z);
		if (Input::GetKeyDown(Keycode::Q))
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y, _camera->positionVec.z + (speed * timer));
		else if (Input::GetKeyDown(Keycode::E))
			_camera->SetPos(_camera->positionVec.x, _camera->positionVec.y, _camera->positionVec.z - (speed * timer));


		if (Input::GetMouseButtonDown(MouseButtons::LEFT_MOUSE_BUTTON))
			_camera->SetPitch(_camera->GetPitch() + (speedRotationCamera * timer));
		else if (Input::GetMouseButtonDown(MouseButtons::RIGHT_MOUSE_BUTTON))
			_camera->SetPitch(_camera->GetPitch() - (speedRotationCamera * timer));

		if (Input::GetKeyDown(Keycode::R))
			_camera->SetYaw(_camera->GetYaw() + (speedRotationCamera * timer));
		else if (Input::GetKeyDown(Keycode::T))
			_camera->SetYaw(_camera->GetYaw() - (speedRotationCamera * timer));

		if (Input::GetKeyDown(Keycode::ALPHA0)) {
			_camera->SetPos(0.0f, 0.0f, 0.0f);
			_camera->SetPitch(0.0f);
			_camera->SetYaw(-90.0f);
		}

		_camera->UseCamera();
		GetLightManager()->UseLights();

		_shape->DrawShape();
		_shape2->DrawShape();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}