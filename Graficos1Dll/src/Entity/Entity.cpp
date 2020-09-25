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
	void Entity::UpdateMatrixData() {
		model = translate * rotation * scale;
	}
	void Entity::SetPos(float x, float y, float z) {
		positionVec = { x, y, z };
		translate = glm::translate(glm::mat4(1.0f),positionVec);
		UpdateMatrixData();
	}
	void Entity::SetRotX(float x) {
		rotationVec[0] = x;
		rotation = glm::rotate(glm::mat4(1.0f), x,glm::vec3(1.0f,0.0f,0.0f));
		UpdateMatrixData();
	}
	void Entity::SetRotY(float y) {
		rotationVec[1] = y;
		rotation = glm::rotate(glm::mat4(1.0f), y, glm::vec3(0.0f,1.0f,0.0f));
		UpdateMatrixData();
	}
	void Entity::SetRotZ(float z) {
		rotationVec[2] = z;
		rotation = glm::rotate(glm::mat4(1.0f), z, glm::vec3(0.0f, 0.0f, 1.0f));
		UpdateMatrixData();
	}
	void Entity::SetScale(float x, float y, float z) {
		scaleVec = { x, y, z };
		scale = glm::scale(glm::mat4(1.0f), scaleVec);
		UpdateMatrixData();
	}

}