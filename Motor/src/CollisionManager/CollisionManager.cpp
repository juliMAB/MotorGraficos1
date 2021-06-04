#include "CollisionManager.h"
#include <iostream>
namespace Coco {

	static bool collisionX = false;
	static bool collisionY = false;
	bool CollisionManager::RectangleCollision(Entity2D* f, Entity2D* s, glm::vec3 bcF, glm::vec3 bcS) {

		// collision x-axis?
		collisionX = f->transform.position.x + bcF.x >= s->transform.position.x &&
			s->transform.position.x + bcS.x >= f->transform.position.x;
		// collision y-axis?
		collisionY = f->transform.position.y + bcF.y >= s->transform.position.y &&
			s->transform.position.y + bcS.y >= f->transform.position.y;
		// collision only if on both axes
		return collisionX && collisionY;
	}

	bool CollisionManager::OnTiggerEnter(Entity2D* first, Entity2D* second) {
		return (RectangleCollision(first, second, first->GetBoxCollider(), second->GetBoxCollider()));
	}

}