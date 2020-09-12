#ifndef WINDOW_H
#define WINDOW_H
#include <glew.h>
#include <glfw3.h>
namespace Graficos1 {

	class Window {
	public:
		Window();
		~Window();
		int StartWindow(int width, int height, const char* windowName);
		void StopWindow();
		bool CheckIfWindowIsOpen();
		void SwapBuffers();
	};

}

#endif