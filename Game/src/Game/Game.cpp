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
		if (_model6 != NULL) {
			delete _model6;
			_model6 = NULL;
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

		_model5 = new Model(GetRenderer());
		_model5->LoadModel("res/models/dragon/source/pose3.fbx", "res/models/dragon/source/", TextureLoadType::Automatic);
		_model5->SetPositionModel(0,1,-5);
		_model5->SetScaleModel(0.005f, 0.005f, 0.005f);
		_model5->SetRotationXModel(-1.25f);
		_model5->SetMaterial(_goldMaterial);

		//_model2 = new Model(GetRenderer());
		//_model2->LoadModel("res/models/cat/source/cat_low.fbx", "res/models/cat/textures/");
		//_model2->SetPositionModel(0, 1, -5);
		////_model2->SetScaleModel(0.01f, 0.01f, 0.01f);
		//_model2->SetRotationXModel(-1.25f);

		_model1 = new Model(GetRenderer());
		_model1->LoadModel("res/models/Banfield Ghost/banfieldghost.obj", "res/models/Banfield Ghost/Ghost_lambert1_BaseColor.png", TextureLoadType::Manual);
		//_model1->SetMaterial(_obsidianMaterial);
		_model1->SetPositionModel(-3, -2, -5);
		_model1->SetScaleModel(0.5f, 0.5f, 0.5f);
		
		_model2 = new Model(GetRenderer());
		_model2->LoadModel("res/models/BokitaGhost/ghost.obj", "res/models/BokitaGhost/Ghost_lambert1_BaseColor.png", TextureLoadType::Manual);
		_model2->SetPositionModel(-1, -2, -5);
		_model2->SetScaleModel(0.5f, 0.5f, 0.5f);
		
		_model3 = new Model(GetRenderer());
		_model3->LoadModel("res/models/ChacaritaGhost/ChacaritaGhost.obj", "res/models/ChacaritaGhost/Ghost_lambert1_BaseColor.png", TextureLoadType::Manual);
		_model3->SetPositionModel(1, -2, -5);
		_model3->SetScaleModel(0.5f, 0.5f, 0.5f);
		
		_model4 = new Model(GetRenderer());
		_model4->LoadModel("res/models/Olimpo ghost/olimpoghost.obj", "res/models/Olimpo ghost/Ghost_lambert1_BaseColor.png" , TextureLoadType::Manual);
		_model4->SetPositionModel(3, -2, -5);
		_model4->SetScaleModel(0.5f, 0.5f, 0.5f);
		//
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
		
		GetLightManager()->AddLight(TypeOfLight::Spot);
		SpotLight* _lightAux = GetLightManager()->GetSpotLightByIndex(0);
		if (_lightAux != NULL) {
			_lightAux->SetPos(0, 3, -3);
			_lightAux->SetColour(glm::vec3(1.0f, 1.0f, 1.0f));
			_lightAux->SetAmbient(glm::vec3(0.2f, 0.2f, 0.2f));
			_lightAux->SetDiffuse(glm::vec3(0.5f, 0.5f, 0.5f));
			_lightAux->SetSpecular(glm::vec3(1.0f,1.0f,1.0f));
			_lightAux->SetConstantLinearQuadratic(1.0f, 0.007f, 0.0002f);
			_lightAux->SetCutOff(33.0f);
			_lightAux->SetDirection(glm::vec3(0, -1, 0));
		}

		//
		//GetLightManager()->AddLight(TypeOfLight::Point);
		//PointLight* _lightAux2 = GetLightManager()->GetPointLightByIndex(0);
		//if (_lightAux2 != NULL) {
		//	_lightAux2->SetPos(-3, 3,-5);
		//	_lightAux2->SetColour(glm::vec3(1.0f,1.0f,1.0f));
		//	_lightAux2->SetAmbient(glm::vec3(0.2f, 0.2f, 0.2f));
		//	_lightAux2->SetDiffuse(glm::vec3(0.5f, 0.5f, 0.5f));
		//	_lightAux2->SetSpecular(glm::vec3(1.0f, 1.0f, 1.0f));
		//	_lightAux2->SetConstantLinearQuadratic(1.0f, 0.09f, 0.032f);
		//}
		//
		// 
		//GetLightManager()->AddLight(TypeOfLight::Directional);
		//GetLightManager()->AddLight(TypeOfLight::Directional);
		////
		//DirectionalLight* dirAux = GetLightManager()->GetDirectionalLightByIndex(0);
		//if (dirAux != NULL) {
		//	dirAux->SetColour(glm::vec3(1, 1, 1));
		//	dirAux->SetDirection(glm::vec3(0, 0, -1));
		//	dirAux->SetAmbient(glm::vec3(0.2f, 0.2f, 0.2f));
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

		//_model6 = new Model(GetRenderer());
		//_model6->LoadModel("res/models/mona/mona model/mona.fbx", "res/models/mona/mona model/", TextureLoadType::Automatic);
		//_model6->SetPositionModel(0, -1, -3);
		////_model6->SetScaleModel(0.5f,0.5f,0.5f);
		//_model6->SetRotationXModel(-1.25f);
		//_sprite = new Sprite(GetRenderer());
		//_sprite->LoadTexture("res/textures/textura final.jpg",false);
	}
	void Game::Play() {
		UpdateEngine();
	}

	float speed = 5.0f;
	float speedRotationCamera = 200.0f;
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

		rotY += timer * 5.0f;

		//_model1->SetRotationModel(rotY,rotY,rotY);
		//_model2->SetRotationModel(rotY,rotY,rotY);
		//_model3->SetRotationModel(rotY,rotY,rotY);
		//_model4->SetRotationModel(rotY,rotY,rotY);
		//
		GetLightManager()->GetSpotLightByIndex(0)->SetDirection(_camera->GetFront());
		GetLightManager()->GetSpotLightByIndex(0)->SetPos(_camera->positionVec.x, _camera->positionVec.y, _camera->positionVec.z);

		_camera->UseCamera();
		GetLightManager()->UseLights();

		//_shape->DrawShape();
		//
		_model1->DrawModel();
		_model2->DrawModel();
		_model3->DrawModel();
		_model4->DrawModel();
		_model5->DrawModel();
		//_model6->DrawModel();
		//
		//_shape2->DrawShape();

		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}