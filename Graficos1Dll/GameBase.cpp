#include "pch.h"
#include "GameBase.h"

namespace Graficos1 {

	GameBase::GameBase() {

	}
	GameBase::~GameBase() {
		if (window != NULL)
			delete window;
		if (renderer != NULL)
			delete renderer;
	}
	int GameBase::Play(int width, int height, const char* windowName) {
		//glfwInit();
		if (!glfwInit())
			return -1;

		window = new Window();
		if (window != NULL)
			window->StartWindow(width, height, windowName);

		renderer = new Renderer();
		if (!renderer)
			return -1;

		if (!window)
			return -1;

		while (window->CheckIfWindowIsOpen()) {
			renderer->Draw();
			window->SwapBuffers();
			glfwPollEvents();
		}

		window->StopWindow();
		return 0;
	}
	void GameBase::Stop() {

	}

}