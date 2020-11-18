#include "Timer.h"
#include <time.h>
#include <iostream>
namespace Graficos1 {

	double oldT = clock();
	float Timer::DeltaTime(){
		double t = clock();
		float dt = (float)((t - oldT) / 1000.0f);
		oldT = t;
		return dt;
	}
	int Timer::GetFPS() {
		return (int)(1.0f / DeltaTime());
	}
}