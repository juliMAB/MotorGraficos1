#include "Input.h"

#include "GLFW/glfw3.h"
#include <iostream>
namespace Graficos1 {
	static GLFWwindow* _window;
	bool Input::GetKeyDown(Keycode k) {
		return (glfwGetKey(_window, k) == GLFW_PRESS);
	}
	bool Input::GetKeyUp(Keycode k) {
		return (glfwGetKey(_window, k) == GLFW_RELEASE);
	}
	bool Input::GetKey(Keycode k) {
		return (glfwGetKey(_window, k) == GLFW_PRESS);
	}
	void Input::SetWindow(GLFWwindow* w) {
		_window = w;
	}

}