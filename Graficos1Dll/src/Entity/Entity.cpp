#include "pch.h"
#include "Entity.h"

namespace Graficos1 {
	Entity::Entity() {
		model = glm::mat4(1.0f);
		translate = glm::mat4(1.0f);
		rotationX = glm::mat4(1.0f);
		rotationY = glm::mat4(1.0f);
		rotationZ = glm::mat4(1.0f);
		scale = glm::mat4(1.0f);

		SetPos(0.0f, 0.0f, 0.0f);
		SetRotX(0.0f);
		SetRotY(0.0f);
		SetRotZ(0.0f);
		SetScale(1.0f, 1.0f, 1.0f);
	}
	Entity::Entity(Renderer* rend) {
		_renderer = rend;

		model = glm::mat4(1.0f);
		translate = glm::mat4(1.0f);
		rotationX = glm::mat4(1.0f);
		rotationY = glm::mat4(1.0f);
		rotationZ = glm::mat4(1.0f);
		scale = glm::mat4(1.0f);

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
		model = translate * rotationX  * rotationY * rotationZ * scale;
	}
	void Entity::SetPos(float x, float y, float z) {
		positionVec = { x, y, z };
		translate = glm::translate(glm::mat4(1.0f), positionVec);
		UpdateMatrixData();
	}
	void Entity::SetRotX(float x) {
		rotationVec[0] = x;
		rotationX = glm::rotate(glm::mat4(1.0f), x, glm::vec3(1.0f, 0.0f, 0.0f));
		UpdateMatrixData();
	}
	void Entity::SetRotY(float y) {
		rotationVec[1] = y;
		rotationY = glm::rotate(glm::mat4(1.0f), y, glm::vec3(0.0f, 1.0f, 0.0f));
		UpdateMatrixData();
	}
	void Entity::SetRotZ(float z) {
		rotationVec[2] = z;
		rotationZ = glm::rotate(glm::mat4(1.0f), z, glm::vec3(0.0f, 0.0f, 1.0f));
		UpdateMatrixData();
	}
	void Entity::SetScale(float x, float y, float z) {
		scaleVec = { x, y, z };
		scale = glm::scale(glm::mat4(1.0f), scaleVec);
		UpdateMatrixData();
	}

}