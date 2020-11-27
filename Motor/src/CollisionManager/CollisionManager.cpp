#include "CollisionManager.h"
#include <iostream>
namespace Graficos1 {

	CollisionManager::CollisionManager() {}
	CollisionManager::~CollisionManager() {}
	static bool collisionX = false;
	static bool collisionY = false;
	bool CollisionManager::RectangleCollision(Entity2D* f, Entity2D* s, glm::vec3 bcF, glm::vec3 bcS) {

		// collision x-axis?
		collisionX = f->positionVec.x + bcF.x >= s->positionVec.x &&
			s->positionVec.x + bcS.x >= f->positionVec.x;
		// collision y-axis?
		collisionY = f->positionVec.y + bcF.y >= s->positionVec.y &&
			s->positionVec.y + bcS.y >= f->positionVec.y;
		// collision only if on both axes
		return collisionX && collisionY;
	}

	bool CollisionManager::OnTiggerEnter(Entity2D* first, Entity2D* second) {
		return (RectangleCollision(first, second, first->GetBoxCollider(), second->GetBoxCollider()));
	}

	bool CollisionManager::OnCollisionEnter(Entity2D* first, Entity2D* second, bool firstReject, bool secondReject) {
		if (RectangleCollision(first, second, first->GetBoxCollider(), second->GetBoxCollider())) {
			if (firstReject)
				first->SetForces(-first->forcesVec.x * 0.5f, -first->forcesVec.y * 0.5f, -first->forcesVec.z * 0.5f);
			else
				first->SetForces(0.0f, 0.0f, 0.0f);
			first->ResetPos();

			if (secondReject)
				second->SetForces(-second->forcesVec.x * 0.5f, -second->forcesVec.y * 0.5f, -second->forcesVec.z * 0.5f);
			else
				second->SetForces(0.0f, 0.0f, 0.0f);
			second->ResetPos();

			return true;
		}

		return false;
	}
}