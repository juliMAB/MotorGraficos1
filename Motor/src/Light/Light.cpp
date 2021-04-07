#include "Light.h"

namespace Graficos1 {

	Light::Light() : Entity(NULL) {
		SetColorsLight(1.0f,1.0f,1.0f,1.0f);
	}
	Light::Light(Renderer* rend) : Entity (rend){
		SetColorsLight(1.0f, 1.0f, 1.0f, 1.0f);
	}
	Light::Light(Renderer* rend,float r, float g, float b, float ambientIntensity) : Entity(rend) {
		SetColorsLight(r, g, b, ambientIntensity);
	}
	Light::~Light() {

	}
	void Light::UseLight() {
		_renderer->UseLight(_ambientIntensity, _colour);
	}
	void Light::TurnOffLight() {
		_renderer->StopLight();
	}
	void Light::SetColorsLight(float r, float g, float b, float ambientIntensity) {
		_colour = glm::vec3(r, g, b);
		_ambientIntensity = ambientIntensity;
	}
	


}