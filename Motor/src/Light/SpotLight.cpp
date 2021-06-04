#include "SpotLight.h"
#include "glew.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

namespace Coco {
	SpotLight::SpotLight(Renderer* rend, int index) : PointLight(rend, 0.0f, 0.0f, 0.0f, index) {
		_cutOff = 0;
		SetUniforms();
	}
	SpotLight::SpotLight(Renderer* rend, float constant, float linear, float quadratic, float cutOff, int index) : PointLight(rend, constant, linear, quadratic, index) {
		_cutOff = cos(glm::radians(cutOff));
		SetUniforms();
	}
	SpotLight::~SpotLight() {
	}
	void SpotLight::SetUniforms() {
		std::string indexSTR = std::to_string(_index).c_str();

		_uniformPosition = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.position").c_str());
		_uniformColour = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.colour").c_str());
		_uniformAmbient = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.ambient").c_str());
		_uniformDiffuse = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.diffuse").c_str());
		_uniformSpecular = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.specular").c_str());
		_uniformConstant = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.constant").c_str());
		_uniformLinear = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.linear").c_str());
		_uniformQuadratic = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.quadratic").c_str());
		_uniformDirection = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].direction").c_str());
		_uniformCutOff = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].cutOff").c_str());
		_uniformAssignedLight = glGetUniformLocation(_renderer->GetShader(), ("spotLight[" + indexSTR + "].pLight.assigned").c_str());
	}
	void SpotLight::UseLight() {
		glUseProgram(_renderer->GetShader());
		glUniform3f(_uniformPosition, transform.position.x, transform.position.y, transform.position.z);
		glUniform3f(_uniformColour, _colour.x, _colour.y, _colour.z);
		glUniform3f(_uniformAmbient, _ambient.x, _ambient.y, _ambient.z);
		glUniform3f(_uniformDiffuse, _diffuse.x, _diffuse.y, _diffuse.z);
		glUniform3f(_uniformSpecular, _specular.x, _specular.y, _specular.z);

		glUniform1f(_uniformConstant, _constant);
		glUniform1f(_uniformLinear, _linear);
		glUniform1f(_uniformQuadratic, _quadratic);

		glUniform3f(_uniformDirection, _direction.x, _direction.y, _direction.z);
		glUniform1f(_uniformCutOff, _cutOff);

		glUniform1i(_uniformAssignedLight, true);
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