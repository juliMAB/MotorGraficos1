#include "Game.h"
#include <time.h>
#include <iostream>
#include "../src/Timer/Timer.h"

namespace Graficos1 {

	Game::Game():GameBase() {

	}
	Game::~Game() {
		//if (_sprite != NULL) {
		//	delete _sprite;
		//	_sprite = NULL;
		//}
		//if (_sprite2 != NULL) {
		//	delete _sprite2;
		//	_sprite2 = NULL;
		//}
		if (_shape != NULL) {
			delete _shape;
			_shape = NULL;
		}
	}
	void Game::Start() {
		StartEngine();

		//_sprite = new Sprite(GetRenderer(), NULL);
		//_sprite->LoadTexture("res/textures/sprite2.png", true);
		//_sprite->StartUseAnimation();
		//_sprite->SetAnimation(8, 4, 16);
		//_sprite->SetAnimation(8, 4, 16);
		//_sprite->SetAnimation(8, 4, 16);
		//_sprite->SetAnimation(8, 4, 16);
		//
		//for (int i = 0; i < 8; i++)
		//	_sprite->AddFrameToAnimation(i, 0, 0, i);
		//for (int i = 0; i < 8; i++)
		//	_sprite->AddFrameToAnimation(i, 1, 1, i);
		//for (int i = 0; i < 8; i++)
		//	_sprite->AddFrameToAnimation(i, 2, 2, i);
		//for (int i = 0; i < 8; i++)
		//	_sprite->AddFrameToAnimation(i, 3, 3, i);
		//
		//_sprite->SetScale(0.33f, 0.33f, 0.33f);
		//_sprite->SetPos(0.5f, _sprite->positionVec.y, _sprite->positionVec.z);
		//_sprite->SetBoxCollider(0.5f, 0.75f, 0.0f);
		//_sprite->SetLastPos();
		//
		//_sprite2 = new Sprite(GetRenderer(), NULL);
		//_sprite2->LoadTexture("res/textures/theolean.jpg",false);
		//_sprite2->SetPos(-0.5f, _sprite2->positionVec.y, _sprite2->positionVec.z);
		//_sprite2->SetScale(0.33f, 0.33f, 0.33f);
		//_sprite2->SetBoxCollider(0.5f, 0.75f, 0.0f);
		//_sprite2->SetLastPos();

		_shape = new Shape(GetRenderer(), NULL);
		_shape->InitShape(TypeShape::Cube, TypeShader::Colour);
		_shape->CreateShape();
		_shape->SetScale(0.33f, 0.33f, 0.33f);
	}
	void Game::Play() {
		UpdateEngine();
	}
	float speedForces = 0.001f;
	float speed = 0.05f;

	const float maxForce = 0.025f;

	void Game::Update() {
		GetWindow()->ClearWindow(0.0f, 0.0f, 1.0f, 1.0f);

		//_sprite->UpdateAnimation();
		//
		//_sprite->SetLastPos();
		//if (Input::GetKeyDown(Keycode::A)) {
		//	_sprite->SetPos(_sprite->positionVec.x - speed, _sprite->positionVec.y, _sprite->positionVec.z);
		//	//if(_sprite->forcesVec.x > -maxForce)
		//	//	_sprite->AddForce(-speedForces, 0, 0);
		//	_sprite->ChangeAnimation(3);
		//}
		//else if (Input::GetKeyDown(Keycode::D)) {
		//	_sprite->SetPos(_sprite->positionVec.x + speed, _sprite->positionVec.y, _sprite->positionVec.z);
		//	//if (_sprite->forcesVec.x < maxForce)
		//	//	_sprite->AddForce(speedForces, 0, 0);
		//	_sprite->ChangeAnimation(2);
		//}
		//if (Input::GetKeyDown(Keycode::W)) {
		//	_sprite->SetPos(_sprite->positionVec.x, _sprite->positionVec.y + speed, _sprite->positionVec.z);
		//	//if (_sprite->forcesVec.y < maxForce * 0.5f)
		//	//	_sprite->AddForce(0, speedForces, 0);
		//	_sprite->ChangeAnimation(1);
		//}
		//else if (Input::GetKeyDown(Keycode::S)) {
		//	_sprite->SetPos(_sprite->positionVec.x, _sprite->positionVec.y - speed, _sprite->positionVec.z);
		//	//if (_sprite->forcesVec.y > -maxForce * 0.5f)
		//	//	_sprite->AddForce(0, -speedForces, 0);
		//	_sprite->ChangeAnimation(0);
		//}

		//_sprite->UpdateForces();
		//_sprite2->UpdateForces();

		//if (Input::GetKeyDown(Keycode::ENTER)) {
		//	_sprite->SetForces(0.0f, 0.0f, 0.0f);
		//	system("cls");
		//}
		//
		//if (CollisionManager::OnCollisionEnter(_sprite, _sprite2, false, false))
		//	std::cout << "colision" << std::endl;
		//
		//_sprite->DrawTexture();
		//_sprite2->DrawTexture();
		
		_shape->SetRotY(_shape->rotationVec.y + 0.01f);
		_shape->SetRotX(_shape->rotationVec.x + 0.01f);
		
		_shape->DrawShape();

		
		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}