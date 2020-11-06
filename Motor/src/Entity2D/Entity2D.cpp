#include "Entity2D.h"

namespace Graficos1 {

	Entity2D::Entity2D() : Entity() {

	}

	Entity2D::Entity2D(Renderer* rend, Material* mat) : Entity(rend) {

	}
	Entity2D::~Entity2D() {
		if (_mat != NULL) {
			delete _mat;
			_mat = NULL;
		}
	}

	void Entity2D::SetMaterial(Material* mat) {
		_mat = mat;
	}

	Material* Entity2D::GetMaterial() {
		if (_mat != NULL)
			return _mat;
	}

}