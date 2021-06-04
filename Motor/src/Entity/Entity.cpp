#include "Entity.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

#include <iostream>

namespace Coco {
	Entity::Entity(Renderer* rend) {
		_renderer = rend;

		matrix.model = glm::mat4(1.0f);
		matrix.translate = glm::mat4(1.0f);
		matrix.rotationX = glm::mat4(1.0f);
		matrix.rotationY = glm::mat4(1.0f);
		matrix.rotationZ = glm::mat4(1.0f);
		matrix.scale = glm::mat4(1.0f);

		SetPos(0.0f, 0.0f, 0.0f);
		SetRotX(0.0f);
		SetRotY(0.0f);
		SetRotZ(0.0f);
		SetScale(1.0f, 1.0f, 1.0f);
	}
	Entity::~Entity() {

	}
	void Entity::SetRenderer(Renderer* r) {
		_renderer = r;
	}
	Renderer* Entity::GetRenderer() {
		return _renderer;
	}
	void Entity::UpdateMatrixData() {
		matrix.model = matrix.translate * matrix.rotationX  * matrix.rotationY * matrix.rotationZ * matrix.scale;
	}
	void Entity::SetPos(float x, float y, float z) {
		transform.position = { x, y, z };
		matrix.translate = glm::translate(glm::mat4(1.0f), transform.position);
		UpdateMatrixData();
	}
	void Entity::SetRotX(float x) {
		transform.position.x = x ;
		matrix.rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(x), glm::vec3(1.0f, 0.0f, 0.0f));
		UpdateMatrixData();
	}
	void Entity::SetRotY(float y) {
		transform.position.y = y;
		matrix.rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(y), glm::vec3(0.0f, 1.0f, 0.0f));
		UpdateMatrixData();
	}
	void Entity::SetRotZ(float z) {
		transform.position.z = z;
		matrix.rotationZ = glm::rotate(glm::mat4(1.0f), glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
		UpdateMatrixData();
	}
	void Entity::SetScale(float x, float y, float z) {
		transform.scale = { x, y, z };
		matrix.scale = glm::scale(glm::mat4(1.0f), transform.scale);
		UpdateMatrixData();
	}
}