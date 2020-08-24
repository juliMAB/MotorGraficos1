#include "pch.h"
#include "GameBase.h"
#include <glew.h>
#include <glfw3.h>
namespace Graficos1 {

	GameBase::GameBase() {

	}
	GameBase::~GameBase() {

	}
	int GameBase::Play(int width, int height, const char* windowName) {
		GLFWwindow* window;

		//Initialize the library /
		if (!glfwInit())
			return -1;

		// Create a windowed mode window and its OpenGL context /
		window = glfwCreateWindow(width, height, windowName, NULL, NULL);
		if (!window) {
			glfwTerminate();
			return -1;
		}

		// Make the window's context current /
		glfwMakeContextCurrent(window);

		//Loop until the user closes the window /
		while (!glfwWindowShouldClose(window)) {
			// Render here /
			glClear(GL_COLOR_BUFFER_BIT);

			// Swap front and back buffers /
			glfwSwapBuffers(window);

			// Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}
	void GameBase::Stop() {

	}

}