#include "Input.h"

#include "GLFW/glfw3.h"
#include <iostream>
namespace Graficos1 {

	bool Input::GetKeyDown(GLFWwindow* w, Keycode k) {
		return (glfwGetKey(w, k) == GLFW_PRESS);
	}
	bool Input::GetKeyUp(GLFWwindow* w, Keycode k) {
		return (glfwGetKey(w, k) == GLFW_RELEASE);
	}
	bool Input::GetKey(GLFWwindow* w, Keycode k) {
		return (glfwGetKey(w, k) == GLFW_PRESS);
	}

}