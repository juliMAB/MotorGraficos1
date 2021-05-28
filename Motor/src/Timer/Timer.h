#ifndef TIMER_H
#define TIMER_H

#include "../src/Exports/Exports.h"
namespace Coco{

	class GraficosEngine_API Timer {
	public:
		static void DeltaTime(float& time);
	};

}

#endif