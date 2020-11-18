#include "Game.h"
#include <time.h>
#include <iostream>
#include "../src/Timer/Timer.h"
namespace Graficos1 {
	Game::Game():GameBase() {

	}
	Game::~Game() {
		if (_sprite != NULL) {
			delete _sprite;
			_sprite = NULL;
		}
		if (_sprite2 != NULL) {
			delete _sprite2;
			_sprite2 = NULL;
		}
		if (_shape != NULL) {
			delete _shape;
			_shape = NULL;
		}
		if (_shape2 != NULL) {
			delete _shape2;
			_shape2 = NULL;
		}
	}
	void Game::Start() {
		StartEngine();


		_sprite = new Sprite(GetRenderer(), NULL);
		//_sprite->BlendSprite();
		_sprite->LoadTexture("res/textures/sprite.png", true);
		//_sprite->UnBlendSprite();
		_sprite->StartUseAnimation();
		_sprite->SetAnimation(9, 4, 16);
		for (int i = 0; i < 7; i++)
			_sprite->AddFrameToAnimation(i,0, 0, i);
		_sprite->SetScale(0.33f, 0.33f, 0.33f);
		//_sprite->SetScale(10, 1, 1);

		//_sprite2 = new Sprite(GetRenderer(), NULL);
		//_sprite2->LoadTexture("res/textures/theolean.jpg",false);
		//_sprite2->SetPos(-0.5f, _sprite2->positionVec.y, _sprite2->positionVec.z);
		//_sprite2->SetScale(0.33f, 0.33f, 0.33f);
		//
		//
		//_shape = new Shape(GetRenderer(), NULL);
		//_shape->InitShape(QUAD, TypeShader::Colour);
		//_shape->CreateShape();
		//float c1[3] = { 1.0f, 0.0f, 0.0f };
		//float c2[3] = { 1.0f, 0.0f, 0.0f };
		//float c3[3] = { 1.0f, 0.0f, 0.0f };
		//_shape->SetColor(c1, c2, c3);
		//_shape->SetPos(0.5f, 0.0f, 0.0f);
		//_shape->SetScale(0.33f, 0.33f, 0.33f);
		//
		//_shape2 = new Shape(GetRenderer(), NULL);
		//_shape2->InitShape(QUAD, TypeShader::Colour);
		//_shape2->CreateShape();
		//
		//float c4[3] = { 1.0f, 0.0f, 0.0f };
		//float c5[3] = { 0.0f, 1.0f, 0.0f };
		//float c6[3] = { 0.0f, 0.0f, 1.0f };
		//
		//_shape2->SetColor(c4, c5, c6);
		//_shape2->SetPos(-0.5f, 0.0f, 0.0f);
		//_shape2->SetScale(0.5f, 0.5f, 0.5f);
	}
	void Game::Play() {
		UpdateEngine();
	}

	float speed = 10;
	bool animationChanged = false;
	int actualAnim = 0;
	float scale = 0.0001f;
	void Game::Update() {
		GetWindow()->ClearWindow(0.0f, 0.0f, 1.0f, 1.0f);

		_sprite->UpdateAnimation(0);

		//if (Input::GetKeyDown(Keycode::W)&&animationChanged == false) {
		//	animationChanged = true;
		//	actualAnim++; 
		//	if (actualAnim >= 4)
		//		actualAnim = 0;
		//	_sprite->set(9, 9, 0.1f, 4, actualAnim);
		//}
		//else if(!Input::GetKeyDown(Keycode::W)) {
		//	animationChanged = false;
		//}

		//if (Input::GetKey(Keycode::D)) {
		//	if (_sprite->positionVec.x >= 1.0f)
		//		_sprite->positionVec.x = -1.0f;
		//
		//	_sprite->SetPos(_sprite->positionVec.x + 0.01f, _sprite->positionVec.y, _sprite->positionVec.z);
		//}

		//_shape->DrawShape();
		//
		//_shape2->DrawShape();
		//
		_sprite->DrawTexture();
		//
		//_sprite2->DrawTexture();
		
		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}