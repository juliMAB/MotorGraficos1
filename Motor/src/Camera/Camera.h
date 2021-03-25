#ifndef CAMERA_H
#define CAMERA_H

#include "../Entity/Entity.h"
#include "../Exports/Exports.h"

namespace Graficos1 {

	class GraficosEngine_API Camera : Entity{
	public:
		Camera();
		~Camera();
		void InitCamera();
	};

}

#endif