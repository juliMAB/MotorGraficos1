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
		if (_model1 != NULL) {
			delete _model1;
			_model1 = NULL;
		}
		if (_model2 != NULL) {
			delete _model2;
			_model2 = NULL;
		}
		if (_model3 != NULL) {
			delete _model3;
			_model3 = NULL;
		}
		if (_model4 != NULL) {
			delete _model4;
			_model4 = NULL;
		}
		if (_model5 != NULL) {
			delete _model5;
			_model5 = NULL;
		}
	}

	void Game::Start() {
		StartEngine(1366, 768, "Coco");
		srand(time(NULL));
		
		_camera = new Camera(GetRenderer());

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


		_model1 = new Model(GetRenderer());
		_model1->LoadModel("res/models/Banfield Ghost/ghost.obj", "res/models/Banfield Ghost/","Ghost_lambert1_BaseColor.png");
		_model1->SetPos(-3, 0, 5);
		_model1->SetScale(0.5f, 0.5f, 0.5f);
		_model1->SetRotY(180);
		
		_model2 = new Model(GetRenderer());
		_model2->LoadModel("res/models/BokitaGhost/ghost.obj", "res/models/BokitaGhost/","Ghost_lambert1_BaseColor.png");
		_model2->SetPos(-1, 0, 5);
		_model2->SetScale(0.5f, 0.5f, 0.5f);
		_model2->SetRotY(180);
		
		_model3 = new Model(GetRenderer());
		_model3->LoadModel("res/models/ChacaritaGhost/ghost.obj", "res/models/ChacaritaGhost/","Ghost_lambert1_BaseColor.png");
		_model3->SetPos(1, 0, 5);
		_model3->SetScale(0.5f, 0.5f, 0.5f);
		_model3->SetRotY(180);

		_model4 = new Model(GetRenderer());
		_model4->LoadModel("res/models/Olimpo ghost/ghost.obj", "res/models/Olimpo ghost/", "Ghost_lambert1_BaseColor.png");
		_model4->SetPos(3, 0, 5);
		_model4->SetScale(0.5f, 0.5f, 0.5f);
		_model4->SetRotY(180);

		_model5 = new Model(GetRenderer());
		_model5->LoadModel("res/models/helicopter/uh60.obj", "res/models/helicopter/");
		_model5->SetPos(3, 0, 15);
		_model5->SetScale(0.25f, 0.25f, 0.25f);

		_camera->SetEntity(_model4);

		//_camera->LookAt(_model4->transform.position);
		//_model4->SetPos(_model4->transform.position, (_model4->transform.forward * 3.0f));

		//_shape = new Shape(GetRenderer());
		//_shape->InitShape(TypeShape::Cube, TypeShader::Texture);
		//_shape->SetScale(0.33f, 0.33f, 0.33f);
		//_shape->SetPos(0.0f, 0.0f, -3.0f);
		//_shape->LoadTexture("res/textures/img1.jpg");
		////_shape->SetMaterial(_goldMaterial);
		////
		//_shape2 = new Shape(GetRenderer());
		//_shape2->InitShape(TypeShape::Cube, TypeShader::Colour);
		//_shape2->SetScale(0.33f, 0.33f, 0.33f);
		//_shape2->SetPos(0.0f, 2.0f, -3.0f);
		//_shape2->SetMaterial(_goldMaterial);
		////
		//
		//

		//GetLightManager()->AddLight(TypeOfLight::Spot);
		//SpotLight* _lightAux = GetLightManager()->GetSpotLightByIndex(0);
		//if (_lightAux != NULL) {
		//	_lightAux->SetPos(0, 0, -2);
		//	_lightAux->SetColour(glm::vec3(1.0f, 1.0f, 1.0f));
		//	_lightAux->SetAmbient(glm::vec3(0.33f,0.33f,0.33f));
		//	_lightAux->SetDiffuse(glm::vec3( 0.5,0.5,0.5));
		//	_lightAux->SetSpecular(glm::vec3(1,1,1));
		//	_lightAux->SetConstantLinearQuadratic(1.0f, 0.09f, 0.032f);
		//	_lightAux->SetCutOff(33.0f);
		//	_lightAux->SetDirection(glm::vec3(0,0,1));
		//}

		//
		//GetLightManager()->AddLight(TypeOfLight::Point);
		//PointLight* _lightAux2 = GetLightManager()->GetPointLightByIndex(0);
		//if (_lightAux2 != NULL) {
		//	_lightAux2->SetPos(0,0,3);
		//	_lightAux2->SetColour(glm::vec3(1.0f,1.0f,1.0f));
		//	_lightAux2->SetAmbient(glm::vec3(0.2f, 0.2f, 0.2f));
		//	_lightAux2->SetDiffuse(glm::vec3(0.5f, 0.5f, 0.5f));
		//	_lightAux2->SetSpecular(glm::vec3(1.0f, 1.0f, 1.0f));
		//	_lightAux2->SetConstantLinearQuadratic(1.0f, 0.09f, 0.032f);
		//}
		
		// 
		//GetLightManager()->AddLight(TypeOfLight::Directional);
		//GetLightManager()->AddLight(TypeOfLight::Directional);
		////
		//DirectionalLight* dirAux = GetLightManager()->GetDirectionalLightByIndex(0);
		//if (dirAux != NULL) {
		//	dirAux->SetColour(glm::vec3(1, 1, 1));
		//	dirAux->SetDirection(glm::vec3(0, 0, 1));
		//	dirAux->SetAmbient(glm::vec3(0.5f, 0.5f, 0.5f));
		//	dirAux->SetDiffuse(glm::vec3(0.5f, 0.5f, 0.5f));
		//	dirAux->SetSpecular(glm::vec3(1.0f, 1.0f, 1.0f));
		//}
		//
		//dirAux = GetLightManager()->GetDirectionalLightByIndex(1);
		//
		//if (dirAux != NULL) {
		//	dirAux->SetColour(glm::vec3(1.0f, 0, 1.0f));
		//	dirAux->SetDirection(glm::vec3(0, -1, 0));
		//}
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

	bool inFirstPersonMode = true;

	void Game::Update(float deltaTime) {
		GetWindow()->ClearWindow(0.5f, 0.5f, 0.5f, 1.0f);


		rotY += deltaTime * 50.0f;

		_model1->SetRotY(rotY);
		_model2->SetRotY(rotY);
		_model3->SetRotY(rotY);
		_model4->SetRotY(rotY);

		if (Input::GetKeyDown(Keycode::ENTER)) {
			_camera->SetPos(0.0f, 0.0f, 0.0f);
			_camera->SetRotations(0, 0, 0);
			inFirstPersonMode = !inFirstPersonMode;
		}
		if (inFirstPersonMode) {
			if (Input::GetKeyDown(Keycode::ALPHA1))
				_camera->SetEntity(_model1);
			if (Input::GetKeyDown(Keycode::ALPHA2))
				_camera->SetEntity(_model2);
			if (Input::GetKeyDown(Keycode::ALPHA3))
				_camera->SetEntity(_model3);
			if (Input::GetKeyDown(Keycode::ALPHA4))
				_camera->SetEntity(_model4);

			_camera->LookFromEntity(glm::vec3(0, 1.66f, 0));
		}
		else {
			if (Input::GetKey(Keycode::W))
				_camera->SetPos(_camera->transform.position + (glm::vec3(0, 1, 0) * speed * deltaTime));
			else if (Input::GetKey(Keycode::S))
				_camera->SetPos(_camera->transform.position + (glm::vec3(0, -1, 0) * speed * deltaTime));
			
			if (Input::GetKey(Keycode::A))
				_camera->SetPos(_camera->transform.position + (glm::vec3(1, 0, 0) * speed * deltaTime));
			else if (Input::GetKey(Keycode::D))
				_camera->SetPos(_camera->transform.position + (glm::vec3(-1, 0, 0) * speed * deltaTime));
			
			if (Input::GetMouseButtonDown(MouseButtons::LEFT_MOUSE_BUTTON))
				_camera->SetPos(_camera->transform.position + (glm::vec3(0, 0, 1) * speed * deltaTime));
			else if (Input::GetMouseButtonDown(MouseButtons::RIGHT_MOUSE_BUTTON))
				_camera->SetPos(_camera->transform.position + (glm::vec3(0,0, -1) * speed * deltaTime));
			
			if (Input::GetKey(Keycode::Q))
				_camera->SetRotY(_camera->transform.rotation.y + (speedRotationCamera * deltaTime));
			else if (Input::GetKey(Keycode::E))
				_camera->SetRotY(_camera->transform.rotation.y - (speedRotationCamera * deltaTime));
			
			if (Input::GetKeyDown(Keycode::ALPHA0)) {
				_camera->SetPos(0.0f, 0.0f, 0.0f);
				_camera->SetRotations(0, 0, 0);
			}

			_camera->LookAt(_camera->transform.position + _camera->transform.forward);
		}
		_camera->UseCamera();
		GetLightManager()->UseLights();
		GetRenderer()->SetView(_camera->GetViewMatrix());

		//GetLightManager()->GetSpotLightByIndex(0)->SetDirection(_camera->transform.forward);
		//GetLightManager()->GetSpotLightByIndex(0)->SetPos(_camera->transform.position.x, _camera->transform.position.y, _camera->transform.position.z);
		
		//_shape->DrawShape();
		//
		_model1->DrawModel();
		_model2->DrawModel();
		_model3->DrawModel();
		_model4->DrawModel();
		_model5->DrawModel();

		//_shape2->DrawShape();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}