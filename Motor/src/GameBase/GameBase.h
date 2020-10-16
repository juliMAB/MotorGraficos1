#ifndef GAMEBASE_H
#define GAMEBASE_H

#include "../src/Exports/Exports.h"
#include "../src/Window/Window.h"
#include "../src/Renderer/Renderer.h"
#include "../src/Shape/Shape.h"
struct GLFWmonitor;

namespace Graficos1 {

	class GraficosEngine_API GameBase {
		Window* _window;
		Renderer* _renderer;
		Shape* _shape;
	public:
		GameBase();
		~GameBase();
		int Play(int width, int height, const char* windowName, GLFWmonitor* fullScreen);
		void Stop();
	};

}

#endif