#include "Timer.h"
#include <time.h>
#include <iostream>
namespace Coco {

	double oldT = clock();
	void Timer::DeltaTime(float& time){
		double t = clock();
		float dt = (float)((t - oldT) / 1000.0f);
		oldT = t;
		time = dt;
	}
}