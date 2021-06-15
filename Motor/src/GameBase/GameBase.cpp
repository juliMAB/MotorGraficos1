#include "GameBase.h"
#include <iostream>
#include <time.h>
#include <glew.h>
#include <glfw/glfw3.h>

#include "../src/Input/Input.h"
#include "../src/Sprite/Sprite.h"
namespace Coco {
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
		if (_collisionManager != NULL)
			delete _collisionManager;
		if (_lightManager != NULL)
			delete _lightManager;
	}

	int GameBase::StartEngine(int width, int height, const char* windowName) {
		if (!glfwInit()) {
			std::cout << "GLFW Initialization failed" << std::endl;
			glfwTerminate();
			return 0;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		_window->MakeWindow(width, height, windowName, NULL);

		int bufferWidth;
		int bufferHeight;
		glfwGetFramebufferSize(_window->GetWindow(), &bufferWidth, &bufferHeight);

		_window->InitWindow();
		Input::SetWindow(_window->GetWindow());
		Input::StartInputSystem();
		
		if (!_renderer->InitGlew()) {
			glfwTerminate();
			return 0;
		}
		glEnable(GL_DEPTH);
		
		_renderer->CreateShader("res/Shaders/vertex.shader", "res/Shaders/fragment.shader");
		_lightManager = new LightManager(_renderer);
	}
	float deltaTime;
	void GameBase::UpdateEngine() {
		while (_window->CheckIfWindowIsOpen()) {
			Timer::DeltaTime(deltaTime);
			Update(deltaTime);
			Input::CheckClearInputList();
			glfwPollEvents();
		}
	}
	void GameBase::EndEngine() {
		_renderer->StopShaders();
		glfwTerminate();
	}

	Window*	GameBase::GetWindow() {
		return _window;
	}
	Renderer* GameBase::GetRenderer() {
		return _renderer;
	}
	LightManager* GameBase::GetLightManager() {
		return _lightManager;
	}
}