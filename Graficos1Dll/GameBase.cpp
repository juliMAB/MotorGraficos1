//#include "pch.h"
//#include "GameBase.h"
//
//#include <glew.h>
//#include <glfw3.h>
//
//namespace Graficos1 {
//
//	GameBase::GameBase() {
//
//	}
//	GameBase::~GameBase() {
//
//	}
//	int GameBase::Play(int width, int height, const char* windowName) {
//		GLFWwindow* window;
//
//		if (!glfwInit())
//			return -1;
//
//		window = glfwCreateWindow(width, height, windowName, NULL, NULL);
//		if (!window) {
//			glfwTerminate();
//			return -1;
//		}
//
//		glfwMakeContextCurrent(window);
//
//		float positions[] = {
//			0.0f, 0.5f,
//			-0.5f, -0.5f,
//			0.5f, -0.5f,
//
//			0.5f, 0.5f,
//			-0.5f, 0.5f,
//			-0.5f, -0.5f
//		};
//
//		while (!glfwWindowShouldClose(window)) {
//			glClear(GL_COLOR_BUFFER_BIT);
//			glClearColor(0.5f, 0.0f, 1.0f, 1.0f);
//
//			glBegin(GL_TRIANGLES);
//
//			//glVertex2f(0.0f, 0.5f);
//			//glVertex2f(-0.5f, -0.5f);
//			//glVertex2f(0.5f, -0.5f);
//
//			glDrawArrays(GL_TRIANGLES, 0, 3);
//
//			glEnd();
//
//			glfwSwapBuffers(window);
//			glfwPollEvents();
//		}
//
//		glfwTerminate();
//		return 0;
//	}
//	void GameBase::Stop() {
//
//	}
//
//}

#include "pch.h"
#include "GameBase.h"
#include "glew.h"
#include "glfw3.h"
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