#ifndef WINDOW_H
#define WINDOW_H

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