#include "Input.h"

#include "GLFW/glfw3.h"
#include <iostream>
namespace Coco {
	static GLFWwindow* _window;
	static int usedInputs = 0;
	static const int _inputsListSize = 12;
	static int _inputs[_inputsListSize];

	void Input::StartInputSystem() {
		for (int i = 0; i < _inputsListSize; i++)
			_inputs[i] = -1;
	}

	void Input::CheckClearInputList() {
		for (int i = 0; i < _inputsListSize; i++)
			if (_inputs[i] != -1)
				if ( glfwGetKey(_window, _inputs[i]) == GLFW_RELEASE )
					_inputs[i] = -1;
	}

	bool Input::GetKeyDown(Keycode k) {
		if (glfwGetKey(_window, k) == GLFW_PRESS) {
			for (int i = 0; i < _inputsListSize; i++)
				if (k == _inputs[i])
					return false;
			
			_inputs[usedInputs] = k;
			usedInputs++;
			if (usedInputs >= _inputsListSize)
				usedInputs = 0;
			
			return true;
		}
		return false;
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
	bool Input::GetMouseButtonDown(MouseButtons mb) {
		return (glfwGetMouseButton(_window, mb) == GLFW_PRESS);
	}
}