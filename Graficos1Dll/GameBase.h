#ifndef GAMEBASE_H
#define GAMEBASE_H
#include "Exports.h"

#include "Window.h"
#include "Renderer.h"
#include <glew.h>
#include <glfw3.h>

namespace Graficos1 {

	class GraficosEngine_API GameBase {
		Window* window;
		Renderer* renderer;
	public:
		GameBase();
		~GameBase();
		int Play(int width, int height, const char* windowName);
		void Stop();
	};

}

#endif