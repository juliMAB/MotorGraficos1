#include "Entity.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

#include <iostream>

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
		SetForces(0.0f, 0.0f, 0.0f);
		lastPos = positionVec;
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
		SetForces(0.0f, 0.0f, 0.0f);
		lastPos = positionVec;
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
	void Entity::SetLastPos() {
		lastPos = positionVec;
	}
	void Entity::AddForce(float x, float y, float z) {
		forcesVec.x += x;
		forcesVec.y += y;
		forcesVec.z += z;
	}
	void Entity::SetForces(float x, float y, float z) {
		forcesVec.x = x;
		forcesVec.y = y;
		forcesVec.z = z;
	}
	void Entity::UpdateForces() {
		if (forcesVec.x > 0.0001f)
			forcesVec.x -= 0.0001f;
		else if (forcesVec.x < -0.0001)
			forcesVec.x += 0.0001f;
		else
			forcesVec.x =0.0f;

		if (forcesVec.y > 0.0001f)
			forcesVec.y -= 0.0001f;
		else if (forcesVec.y < -0.0001)
			forcesVec.y += 0.0001f;
		else
			forcesVec.y = 0;

		if (forcesVec.z > 0.0001f)
			forcesVec.z -= 0.0001f;
		else if (forcesVec.z < -0.0001)
			forcesVec.z += 0.0001f;
		else
			forcesVec.z = 0.0f;

		SetPos(positionVec.x + forcesVec.x, positionVec.y + forcesVec.y, positionVec.z + forcesVec.z);
	}
	void Entity::ResetPos() {
		SetPos(lastPos.x, lastPos.y, lastPos.z);
	}
}