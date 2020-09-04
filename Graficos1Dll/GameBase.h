//#ifndef GAMEBASE_H
//#define GAMEBASE_H
//#include "Exports.h"
//
//namespace Graficos1 {
//
//	class GraficosEngine_API GameBase {
//	public:
//		GameBase();
//		~GameBase();
//		int Play(int width, int height, const char* windowName);
//		void Stop();
//	};
//
//}
//
//#endif

#ifndef GAMEBASE_H
#define GAMEBASE_H
#include "Exports.h"

#include "Window.h"
#include "Renderer.h"

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