#ifndef WINDOW_H
#define WINDOW_H
#include <glew.h>
#include <glfw3.h>
namespace Graficos1 {

	class Window {
	GLFWwindow* _window; 
	public:
		Window();
		~Window();
		int StartWindow(int width, int height, const char* windowName, GLFWmonitor* fullScreen);
		void StopWindow();
		int CheckIfWindowIsOpen();
		void SwapBuffers();
		GLFWwindow* GetWindow();
	};

}

#endif