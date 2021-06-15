#include "Camera.h"
#include "glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

namespace Coco {
	
	Camera::Camera(Renderer* r) : Entity(r){
		_entity = NULL;
		_worldUp = glm::vec3(0,1,0);
		_viewMatrix = glm::mat4(1.0f);
		_uniformCameraPosition = glGetUniformLocation(_renderer->GetShader(), "eyePosition");
		LookAt(glm::vec3(0, 0, 1));
	}
	Camera::~Camera() {	}
	glm::mat4 Camera::GetViewMatrix() {
		return _viewMatrix;
	}
	void Camera::LookAt(glm::vec3 position) {
		_viewMatrix = glm::lookAt(transform.position, position, _worldUp);
	}
	void Camera::LookFromEntity() {
		LookFromEntity(glm::vec3(0, 0, 0));
	}
	void Camera::LookFromEntity(glm::vec3 offset) {
		if (_entity != NULL) {
			_entity->SetCanDraw(false);
			SetPos(_entity->transform.position+offset);
			SetRotations(_entity->transform.rotation);
			LookAt(transform.position + transform.forward);
		}
	}
	void Camera::SetEntity(Entity* entity) {
		_entity = entity;
	}
	void Camera::UseCamera() {
		_renderer->UseCamera(transform.position, _uniformCameraPosition);
	}
}
