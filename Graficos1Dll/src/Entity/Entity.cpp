#include "pch.h"
#include "Entity.h"

namespace Graficos1 {
	Entity::Entity() {

	}
	Entity::Entity(Renderer* rend) {
		_renderer = rend;
	}

	Entity::~Entity() {
		if (_renderer != NULL)
			delete _renderer;
	}

	void Entity::SetRenderer(Renderer* r) {
		_renderer = r;
	}
	Renderer* Entity::GetRenderer() {
		return _renderer;
	}
}