#include "Light.h"

namespace Graficos1 {

	Light::Light() : Entity(NULL) {
		SetColorsLight(1.0f,1.0f,1.0f,1.0f);
		SetDirection(0.0f, -1.0f, 0.0f);
		SetDiffuseIntensity(1.0f);
	}
	Light::Light(Renderer* rend) : Entity (rend){
		SetColorsLight(1.0f, 1.0f, 1.0f, 1.0f);
		SetDirection(0.0f,-1.0f,0.0f);
		SetDiffuseIntensity(1.0f);
	}
	Light::Light(Renderer* rend, float r, float g, float b, float ambientIntensity, float dirX, float dirY, float dirZ, float diffuseIntensity) : Entity(rend) {
		SetColorsLight(r, g, b, ambientIntensity);
		SetDirection(dirX, dirY, dirZ);
		SetDiffuseIntensity(diffuseIntensity);
	}
	Light::~Light() {

	}
	void Light::UseLight() {
		_renderer->UseLight(_ambientIntensity, _colour,_direction, _diffuseIntensity, positionVec);
	}
	void Light::TurnOffLight() {
		_renderer->StopLight();
	}
	void Light::SetColorsLight(float r, float g, float b, float ambientIntensity) {
		_colour = glm::vec3(r, g, b);
		_ambientIntensity = ambientIntensity;
	}
	void Light::SetDirection(float dirX, float dirY, float dirZ) {
		_direction = glm::vec3(dirX, dirY, dirZ);
	}
	void Light::SetDiffuseIntensity(float diffuseIntensity) {
		_diffuseIntensity = diffuseIntensity;
	}


}