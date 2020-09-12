#include "pch.h"
#include "Window.h"
#include <iostream>

namespace Graficos1 {
	
	Window::Window() {

	}
	Window::~Window() {
		if (_window != NULL)
			delete _window;
	}

	int Window::StartWindow(int width, int height, const char* windowName, GLFWmonitor* fullScreen) {

		_window = glfwCreateWindow(width, height, windowName, fullScreen, NULL);
		if (!_window) {
			
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(_window);
	}

	void Window::StopWindow() {
		glfwTerminate();
	}

	int Window::CheckIfWindowIsOpen() {
		if (glfwWindowShouldClose(_window))
			return false;

		return true;

	}
	void Window::SwapBuffers() {
		glfwSwapBuffers(_window);
	}

	GLFWwindow* Window::GetWindow(){
		return _window;
	}
}