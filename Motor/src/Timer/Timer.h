#ifndef TIMER_H
#define TIMER_H

#include "../src/Exports/Exports.h"
namespace Graficos1{

	class GraficosEngine_API Timer {
	public:
		static float DeltaTime();
		static int GetFPS();
	};

}

#endif