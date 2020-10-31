#include "GameBase.h"
#include <iostream>
#include <time.h>
#include <glew.h>
#include <glfw/glfw3.h>


#include "../src/Input/Input.h"
#include "../src/Sprite/Sprite.h"

namespace Graficos1 {
	Sprite* tex;
	GameBase::GameBase() {
		srand(time(0));
		_window = new Window();
		_renderer = new Renderer();
		
	}
	GameBase::~GameBase() {
		if (_window != NULL)
			delete _window;
		if (_renderer != NULL)
			delete _renderer;
		if (_shape != NULL)
			delete _shape;
		if (tex != NULL)
			delete tex;
	}
	int GameBase::Play(int width, int height, const char* windowName, GLFWmonitor* fullScreen) {
		if (!glfwInit()) {
			std::cout << "GLFW Initialization failed" << std::endl;
			glfwTerminate();
			return 1;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


		if (_window != NULL)
			_window->MakeWindow(width, height, windowName, fullScreen);

		int bufferWidth;
		int bufferHeight;
		glfwGetFramebufferSize(_window->GetWindow(), &bufferWidth, &bufferHeight);

		if (_window != NULL)
			_window->InitWindow();

		if (_renderer != NULL)
			if (!_renderer->InitGlew()) {
				glfwTerminate();
				return -1;
			}

		if (_renderer != NULL)
			_renderer->InitShaders();

		tex = new Sprite(_renderer, nullptr);
		_shape = new Shape(_renderer, nullptr);
		if (_shape != NULL) {
			_shape->InitShape(GL_QUADS, TypeShader::Texture);
			_shape->CreateShape();
			tex->LoadTexture("res/textures/theolean.jpg");
		}

		double oldTimer = clock();
		float posX = 0;
		float posY = 0;
		float posZ = 0;

		float rotX = 0;
		float rotY = 0;
		float rotZ = 0;

		float scaleX = 1;
		float scaleY = 1;
		float scaleZ = 1;

		float speed = 1000;

		float t = 0;

		float c1[3];
		float c2[3];
		float c3[3];

		bool buttonPressed = false;
		if (_shape != NULL) {
			for (int i = 0; i < 3; i++) {
				c1[i] = (rand() % 254 + 1) / 255.0f;
				c2[i] = (rand() % 254 + 1) / 255.0f;
				c3[i] = (rand() % 254 + 1) / 255.0f;
			}
			_shape->SetColor(c1, c2, c3);
		}

		if (_window != NULL) {
			while (_window->CheckIfWindowIsOpen()) {
				glClear(GL_COLOR_BUFFER_BIT);
				glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

				double timer = clock();
				float dt = (float)((timer - oldTimer) / 1000.0f);
				oldTimer = timer;

				if (Input::GetKeyDown(_window->GetWindow(), Keycode::R)) {
					posX = 0;
					posY = 0;
					posZ = 0;

					rotX = 0;
					rotY = 0;
					rotZ = 0;

					scaleX = 1;
					scaleY = 1;
					scaleZ = 1;
				}

				if (Input::GetKey(_window->GetWindow(), Keycode::W))
					posY += speed * dt;
				else if (Input::GetKey(_window->GetWindow(), Keycode::S))
					posY -= speed * dt;

				if (Input::GetKey(_window->GetWindow(), Keycode::A))
					posX -= speed * dt;
				else if (Input::GetKey(_window->GetWindow(), Keycode::D))
					posX += speed * dt;

				if (Input::GetKey(_window->GetWindow(), Keycode::ALPHA1))
					rotZ -= speed * dt;
				else if (Input::GetKey(_window->GetWindow(), Keycode::ALPHA2))
					rotZ += speed * dt;

				if (Input::GetKey(_window->GetWindow(), Keycode::ALPHA3))
					rotX += speed * dt;
				else if (Input::GetKey(_window->GetWindow(), Keycode::ALPHA4))
					rotX -= speed * dt;

				if (Input::GetKey(_window->GetWindow(), Keycode::ALPHA5))
					rotY -= speed * dt;
				else if (Input::GetKey(_window->GetWindow(), Keycode::ALPHA6))
					rotY += speed * dt;

				if (Input::GetKey(_window->GetWindow(), Keycode::Q))
					scaleX -= 5 * dt;
				else if (Input::GetKey(_window->GetWindow(), Keycode::E))
					scaleX += 5 * dt;

				if (Input::GetKey(_window->GetWindow(), Keycode::Z))
					scaleY -= 5 * dt;
				else if (Input::GetKey(_window->GetWindow(), Keycode::X))
					scaleY += 5 * dt;

				if (Input::GetKey(_window->GetWindow(), Keycode::C)) {
					if (!buttonPressed) {
						for (int i = 0; i < 3; i++) {
							c1[i] = (rand() % 254 + 1) / 255.0f;
							c2[i] = (rand() % 254 + 1) / 255.0f;
							c3[i] = (rand() % 254 + 1) / 255.0f;
							if(_shape!=NULL)
							_shape->SetColor(c1, c2, c3);
						}
					}
					buttonPressed = true;
				}
				else if (Input::GetKeyUp(_window->GetWindow(), Keycode::C)) {
					buttonPressed = false;
				}

				if (_shape != NULL) {
					_shape->SetPos((posX / 960.0f), (posY / 540.0f), posZ);
					_shape->SetRotX((rotX / 180.0f));
					_shape->SetRotY((rotY / 180.0f));
					_shape->SetRotZ((rotZ / 180.0f));
					_shape->SetScale(scaleX, scaleY, scaleZ);
				}

				if (_shape != NULL)
					_shape->DrawShape();
				tex->UseTexture();

				if (_window != NULL)
					_window->SwapBuffers();

				glfwPollEvents();
			}
		}
		if (_window != NULL)
			_window->DestroyWindow();
		glfwTerminate();
		return 0;
	}
	void GameBase::Stop() {

	}

}