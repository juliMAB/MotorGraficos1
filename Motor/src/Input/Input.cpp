#include "Input.h"

#include "GLFW/glfw3.h"
#include <iostream>
namespace Graficos1 {
	static GLFWwindow* _window;
	//static bool keyPressed = false;
	//static Keycode keyP = Keycode::GRAVE_ACCENT;
	bool Input::GetKeyDown(Keycode k) {
		//if (k != keyP && glfwGetKey(_window, k) == GLFW_PRESS) {
		//	keyP = k;
		//	return (glfwGetKey(_window, k) == GLFW_PRESS);
		//}
		//else if (k == keyP && glfwGetKey(_window, k) == GLFW_PRESS) 
		//	return false;
		//else if (!glfwGetKey(_window, k) == GLFW_PRESS) {
		//	keyP = Keycode::GRAVE_ACCENT;
		//	return false;
		//}
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