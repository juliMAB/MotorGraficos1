#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "../src/Exports/Exports.h"
#include "../src/Entity2D/Entity2D.h"

namespace Coco {

	class GraficosEngine_API CollisionManager {
		static bool RectangleCollision(Entity2D* f, Entity2D* s, glm::vec3 bcF, glm::vec3 bcS);
	public:
		static bool OnTiggerEnter(Entity2D* first, Entity2D* second);
	};

}

#endif