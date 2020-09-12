#ifndef GAMEBASE_H
#define GAMEBASE_H
#include "Exports.h"

#include "Window.h"
#include "Renderer.h"
#include <glew.h>
#include <glfw3.h>

namespace Graficos1 {

	class GraficosEngine_API GameBase {
		Window* _window;
		Renderer* _renderer;
	public:
		GameBase();
		~GameBase();
		int Play(int width, int height, const char* windowName, GLFWmonitor* fullScreen);
		void Stop();
	};

}

#endif