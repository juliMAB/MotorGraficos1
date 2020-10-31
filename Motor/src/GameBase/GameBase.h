#ifndef GAMEBASE_H
#define GAMEBASE_H

#include "../src/Exports/Exports.h"
#include "../src/Window/Window.h"
#include "../src/Renderer/Renderer.h"
#include "../src/Shape/Shape.h"
#include "../src/Sprite/Sprite.h"
struct GLFWmonitor;

namespace Graficos1 {

	class GraficosEngine_API GameBase {
		Window* _window;
		Renderer* _renderer;
	public:
		GameBase();
		~GameBase();

		int StartEngine();
		void UpdateEngine();
		void EndEngine();

		Window* GetWindow();
		Renderer* GetRenderer();

		virtual void Start() = 0;
		virtual void Update() = 0;
		void virtual End() = 0;
	};

}

#endif