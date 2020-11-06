#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "../src/Exports/Exports.h"
#include "../src/Entity2D/Entity2D.h"

namespace Graficos1 {

	class GraficosEngine_API CollisionManager {
		bool RectangleCollision(Entity2D* f, Entity2D* s);
	public:
		CollisionManager();
		~CollisionManager();

		bool OnTiggerEnter(Entity2D* first, Entity2D* second);
	};

}

#endif