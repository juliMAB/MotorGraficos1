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
	}
	void Game::Start() {
		StartEngine();


		_sprite = new Sprite(GetRenderer(), NULL);
		_sprite->LoadTexture("res/textures/sprite2.png", true);
		_sprite->StartUseAnimation();
		_sprite->SetAnimation(8, 4, 8);
		for (int i = 0; i < 8; i++)
			_sprite->AddFrameToAnimation(i,0, 0, i);
		_sprite->SetScale(0.33f, 0.33f, 0.33f);
		_sprite->SetPos(0.5f, _sprite->positionVec.y, _sprite->positionVec.z);
		_sprite->SetBoxCollider(0.5f, 0.75f, 0.0f);

		_sprite2 = new Sprite(GetRenderer(), NULL);
		_sprite2->LoadTexture("res/textures/theolean.jpg",false);
		_sprite2->SetPos(-0.5f, _sprite2->positionVec.y, _sprite2->positionVec.z);
		_sprite2->SetScale(0.33f, 0.33f, 0.33f);
		_sprite2->SetBoxCollider(0.5f, 0.75f, 0.0f);

	}
	void Game::Play() {
		UpdateEngine();
	}

	float speed = 0.025f;

	void Game::Update() {
		GetWindow()->ClearWindow(0.0f, 0.0f, 1.0f, 1.0f);

		_sprite->UpdateAnimation(0);

		if (Input::GetKeyDown(Keycode::A)) 
			_sprite->SetPos(_sprite->positionVec.x - speed, _sprite->positionVec.y, _sprite->positionVec.z);
		else if (Input::GetKeyDown(Keycode::D)) 
			_sprite->SetPos(_sprite->positionVec.x + speed, _sprite->positionVec.y, _sprite->positionVec.z);

		if (Input::GetKeyDown(Keycode::W)) 
			_sprite->SetPos(_sprite->positionVec.x, _sprite->positionVec.y + speed, _sprite->positionVec.z);
		else if (Input::GetKeyDown(Keycode::S)) 
			_sprite->SetPos(_sprite->positionVec.x, _sprite->positionVec.y - speed, _sprite->positionVec.z);

		if (Input::GetKeyDown(Keycode::ENTER))
			system("cls");
		
		if (CollisionManager::OnTiggerEnter(_sprite, _sprite2)) {
			std::cout << "colision" << std::endl;
		}

		_sprite->DrawTexture();
		_sprite2->DrawTexture();
		
		GetWindow()->SwapBuffers();
	}
	void Game::End() {
		EndEngine();
	}
}