#include "GameBase.h"
#include <iostream>
#include <time.h>
#include <glew.h>
#include <glfw/glfw3.h>

#include "../src/Input/Input.h"
#include "../src/Sprite/Sprite.h"

namespace Graficos1 {
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
	}

	int GameBase::StartEngine() {
		if (!glfwInit()) {
			std::cout << "GLFW Initialization failed" << std::endl;
			glfwTerminate();
			return 0;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		_window->MakeWindow(1366, 768, "Coco", NULL);

		int bufferWidth;
		int bufferHeight;
		glfwGetFramebufferSize(_window->GetWindow(), &bufferWidth, &bufferHeight);

		_window->InitWindow();
		_input->SetWindow(_window->GetWindow());
		
		if (!_renderer->InitGlew()) {
			glfwTerminate();
			return 0;
		}

		_renderer->InitShaders();
	}

	void GameBase::UpdateEngine() {
		while (_window->CheckIfWindowIsOpen()) {
			Update();
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
	Input* GameBase::GetInput() {
		return _input;
	}
}