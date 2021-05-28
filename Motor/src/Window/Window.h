#ifndef WINDOW_H
#define WINDOW_H

#include "../src/Exports/Exports.h"
struct GLFWwindow;
struct GLFWmonitor;
namespace Coco {

	class GraficosEngine_API Window {
	GLFWwindow* _window; 
	public:
		Window();
		~Window();
		int MakeWindow(int width, int height, const char* windowName, GLFWmonitor* fullScreen);
		void InitWindow();
		int CheckIfWindowIsOpen();
		void ClearWindow(float r, float g, float b, float a);
		void SwapBuffers();
		void DestroyWindow();
		GLFWwindow* GetWindow();
	};

}

#endif