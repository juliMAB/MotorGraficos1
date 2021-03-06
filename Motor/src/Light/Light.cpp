#include "Light.h"
#include "glew.h"
namespace Coco {

	Light::Light(Renderer* rend, int index) : Entity(rend) {
		_colour = glm::vec3(1.0f, 1.0f, 1.0f);
		_ambient = glm::vec3(0.2f, 0.2f, 0.2f);
		_diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
		_specular = glm::vec3(1.0f, 1.0f, 1.0f);
		_direction = glm::vec3(0.0f, 0.0f, -1.0f);
		_usingLight = true;
		_index = index;
		SetUniforms();
	}
	Light::~Light() {}

	void Light::SetUniforms() {
		_uniformColour = glGetUniformLocation(_renderer->GetShader(), "baseLight.colour");
		_uniformAssignedLight = glGetUniformLocation(_renderer->GetShader(), "baseLight.assigned");
	}

	void Light::UseLight() {
		glUseProgram(_renderer->GetShader());
		glUniform3f(_uniformColour, _colour.x, _colour.y, _colour.z);
		glUniform1i(_uniformAssignedLight, true);
		glUseProgram(0);
		_renderer->SetLights(true);
	}
	void Light::SetColour(glm::vec3 c) {
		_colour = c;
	}
	void Light::SetDirection(glm::vec3 d) {
		_direction = d;
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
	glm::vec3 Light::GetDirection() {
		return _direction;
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
	bool Light::GetUsingLight() {
		return _usingLight;
	}

}