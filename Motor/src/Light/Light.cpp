#include "Light.h"

namespace Graficos1 {

	Light::Light() : Entity(NULL) {
		_ambient = glm::vec3(0.0f, 0.0f, 0.0f);
		_diffuse = glm::vec3(0.0f, 0.0f, 0.0f);
		_specular = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	Light::Light(Renderer* rend) : Entity (rend) {
		_ambient = glm::vec3(0.0f, 0.0f, 0.0f);
		_diffuse = glm::vec3(0.0f, 0.0f, 0.0f);
		_specular = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	Light::~Light() {}
	void Light::UseLight() {
		_renderer->UseLight(_colour, _ambient, _diffuse, _specular, positionVec);
	}
	void Light::TurnOffLight() {
		_renderer->StopLight();
	}
	void Light::SetColour(glm::vec3 c) {
		_colour = c;
	}
	void Light::SetAmbient(glm::vec3 a) {
		_ambient = a;
	}
	void Light::SetDiffuse(glm::vec3 d) {
		_diffuse = d;
	}
	void Light::SetSpecular(glm::vec3 s) {
		_specular = s;
	}
	glm::vec3 Light::GetColour() {
		return _colour;
	}
	glm::vec3 Light::GetAmbient() {
		return _ambient;
	}
	glm::vec3 Light::GetDiffuse() {
		return _diffuse;
	}
	glm::vec3 Light::GetSpecular() {
		return _specular;
	}

}