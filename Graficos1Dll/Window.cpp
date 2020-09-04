#include "pch.h"
#include "Window.h"
#include <glew.h>
#include <glfw3.h>

namespace Graficos1 {
	GLFWwindow* window;
	Window::Window() {
		
	}
	Window::~Window() {
		if (window != NULL)
			delete window;
	}

	int Window::StartWindow(int width, int height, const char* windowName) {

		window = glfwCreateWindow(width, height, windowName, NULL, NULL);
		if (!window) {
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);
	}

	void Window::StopWindow() {
		glfwTerminate();
	}

	bool Window::CheckIfWindowIsOpen() {
		if (window != NULL)
			return true;

		return false;
	}
	void Window::SwapBuffers() {
		glfwSwapBuffers(window);
	}
}