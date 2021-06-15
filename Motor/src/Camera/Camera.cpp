#include "Camera.h"
#include "glew.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Coco {
	
	Camera::Camera(Renderer* r) : Entity(r){}
	Camera::~Camera() {	}
	void Camera::InitCamera(glm::vec3 pos, glm::vec3 up) {
		SetPos(pos.x, pos.y, pos.z);
		_worldUp = up;
		_viewMatrix = glm::mat4(1.0f);
		_uniformCameraPosition = glGetUniformLocation(_renderer->GetShader(), "eyePosition");
		LookAt(glm::vec3(0, 0, -1));
	}
	glm::mat4 Camera::GetViewMatrix() {
		return _viewMatrix;
	}
	void Camera::LookAt(glm::vec3 position) {
		_viewMatrix = glm::lookAt(transform.position, position, _worldUp);
	}
	void Camera::UseCamera() {
		_renderer->UseCamera(transform.position, _uniformCameraPosition);
	}
}
