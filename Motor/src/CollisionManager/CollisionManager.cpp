#include "CollisionManager.h"

namespace Graficos1 {

	CollisionManager::CollisionManager() {
	
	}
	CollisionManager::~CollisionManager() {
	
	}

	bool CollisionManager::RectangleCollision(Entity2D* f, Entity2D* s, glm::vec3 bcF, glm::vec3 bcS) {

		// collision x-axis?
		bool collisionX = f->positionVec.x + bcF.x >= s->positionVec.x &&
			s->positionVec.x + bcS.x >= f->positionVec.x;
		// collision y-axis?
		bool collisionY = f->positionVec.y + bcF.y >= s->positionVec.y &&
			s->positionVec.y + bcS.y >= f->positionVec.y;
		// collision only if on both axes
		return collisionX && collisionY;
	}

	bool CollisionManager::OnTiggerEnter(Entity2D* first, Entity2D* second) {
		return (RectangleCollision(first, second, first->GetBoxCollider(), second->GetBoxCollider()));
	}

}