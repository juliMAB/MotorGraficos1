#include "Light.h"

namespace Graficos1 {

	Light::Light() : Entity(NULL) {
		_colour = glm::vec3(1.0f, 1.0f, 1.0f);
		_ambientIntensity = 1.0f;
	}
	Light::Light(Renderer* rend) : Entity (rend){
		_colour = glm::vec3(1.0f, 1.0f, 1.0f);
		_ambientIntensity = 1.0f;
	}
	Light::Light(Renderer* rend,float r, float g, float b, float ambientIntensity) : Entity(rend) {
		_colour = glm::vec3(r, g, b);
		_ambientIntensity = ambientIntensity;
	}
	Light::~Light() {

	}
	void Light::UseLight() {
		_renderer->UseLight(_ambientIntensity, _colour);
	}
	void Light::TurnOffLight() {
		_renderer->StopLight();
	}
	


}