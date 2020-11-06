#include "CollisionManager.h"

namespace Graficos1 {

	CollisionManager::CollisionManager() {
	
	}
	CollisionManager::~CollisionManager() {
	
	}
	bool CollisionManager::RectangleCollision(Entity2D* f, Entity2D* s) {
		return false;
	}

	bool CollisionManager::OnTiggerEnter(Entity2D* first, Entity2D* second) {
		return (RectangleCollision(first, second));
	}

}