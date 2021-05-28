#include "SpotLight.h"
#include "glew.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Coco {
	SpotLight::SpotLight(Renderer* rend) : PointLight(rend,0.0f,0.0f,0.0f){
		_cutOff = 0;
		_typeOfLight = TypeOfLight::Spot;
		SetUniforms();
	}
	SpotLight::SpotLight(Renderer* rend, float constant, float linear, float quadratic, float cutOff) : PointLight(rend, constant, linear, quadratic) {
		_cutOff = cos(glm::radians(cutOff));
		_typeOfLight = TypeOfLight::Spot;
		SetUniforms();
	}
	SpotLight::~SpotLight() {
	}
	void SpotLight::SetUniforms() {
		_uniformPosition = glGetUniformLocation(_renderer->GetShader(), "spotLight.pLight.position");
		_uniformColour = glGetUniformLocation(_renderer->GetShader(), "spotLight.pLight.colour");
		_uniformAmbient = glGetUniformLocation(_renderer->GetShader(), "spotLight.pLight.ambient");
		_uniformDiffuse = glGetUniformLocation(_renderer->GetShader(), "spotLight.pLight.diffuse");
		_uniformSpecular = glGetUniformLocation(_renderer->GetShader(), "spotLight.pLight.specular");
		_uniformConstant = glGetUniformLocation(_renderer->GetShader(), "spotLightpLight..constant");
		_uniformLinear = glGetUniformLocation(_renderer->GetShader(), "spotLight.pLight.linear");
		_uniformQuadratic = glGetUniformLocation(_renderer->GetShader(), "spotLight.pLight.quadratic");
		_uniformDirection = glGetUniformLocation(_renderer->GetShader(), "spotLight.direction");
		_uniformCutOff = glGetUniformLocation(_renderer->GetShader(), "spotLight.cutOff");
		_uniformTypeOfLight = glGetUniformLocation(_renderer->GetShader(), "typeOfLight");
	}
	void SpotLight::UseLight() {
		glUseProgram(_renderer->GetShader());
		glUniform3f(_uniformPosition, positionVec.x, positionVec.y, positionVec.z);
		glUniform3f(_uniformColour, _colour.x, _colour.y, _colour.z);
		glUniform3f(_uniformAmbient, _ambient.x, _ambient.y, _ambient.z);
		glUniform3f(_uniformDiffuse, _diffuse.x, _diffuse.y, _diffuse.z);
		glUniform3f(_uniformSpecular, _specular.x, _specular.y, _specular.z);

		glUniform1f(_uniformConstant, _constant);
		glUniform1f(_uniformLinear, _linear);
		glUniform1f(_uniformQuadratic, _quadratic);

		glUniform3f(_uniformDirection, _direction.x, _direction.y, _direction.z);
		glUniform1f(_uniformCutOff, _cutOff);

		glUniform1i(_uniformTypeOfLight, _typeOfLight);
		glUseProgram(0);
		_renderer->SetLights(true);
	}
	void SpotLight::SetCutOff(float c) {
		_cutOff = cos(glm::radians(c));
	}
	float SpotLight::GetCutOff() {
		return _cutOff;
	}
}