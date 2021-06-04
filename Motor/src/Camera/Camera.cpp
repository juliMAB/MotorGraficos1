#include "Camera.h"
#include "glew.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Coco {
	
	Camera::Camera(Renderer* r) : Entity(r){}
	Camera::~Camera() {	}
	void Camera::InitCamera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch) {
		SetPos(pos.x, pos.y, pos.z);
		_worldUp = up;
		_yaw = yaw;
		_pitch = pitch;
		transform.forward = glm::vec3(0.0f, 0.0f, -1.0f);
		_uniformCameraPosition = glGetUniformLocation(_renderer->GetShader(), "eyePosition");
		UpdateCamera();
	}
	glm::mat4 Camera::CalculateViewMatrix() {
		return glm::lookAt(transform.position, transform.position + transform.forward, transform.up);
	}
	void Camera::UpdateCamera() {
		transform.forward.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		transform.forward.y = sin(glm::radians(_pitch));
		transform.forward.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
		transform.forward = glm::normalize(transform.forward);

		transform.right = glm::normalize(glm::cross(transform.forward, _worldUp));
		transform.up = glm::normalize(glm::cross(transform.right, transform.forward));
	}
	void Camera::UseCamera() {
		_renderer->UseCamera(transform.position, _uniformCameraPosition);
	}
	void Camera::SetPitch(float p) {
		_pitch = p;
		UpdateCamera();
	}
	void Camera::SetYaw(float y) {
		_yaw = y;
		UpdateCamera();
	}
	float Camera::GetPitch() {
		return _pitch;
	}
	float Camera::GetYaw() {
		return _yaw;
	}
}
