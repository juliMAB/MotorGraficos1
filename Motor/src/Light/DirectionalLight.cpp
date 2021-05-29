#include "DirectionalLight.h"
#include "glew.h"
#include <iostream>
namespace Coco {

	DirectionalLight::DirectionalLight(Renderer* rend, int index) : Light(rend, index) {
		SetUniforms();
	}
	DirectionalLight::~DirectionalLight() {

	}
	void DirectionalLight::SetUniforms() {
		std::string indexSTR = std::to_string(_index).c_str();

		_uniformColour = glGetUniformLocation(_renderer->GetShader(),		("directionalLight["+indexSTR+"].colour")		.c_str());
		_uniformDirection = glGetUniformLocation(_renderer->GetShader(),	("directionalLight["+indexSTR+"].direction")	.c_str());
		_uniformAmbient = glGetUniformLocation(_renderer->GetShader(),		("directionalLight["+indexSTR+"].ambient")		.c_str());
		_uniformDiffuse = glGetUniformLocation(_renderer->GetShader(),		("directionalLight["+indexSTR+"].diffuse")		.c_str());
		_uniformSpecular = glGetUniformLocation(_renderer->GetShader(),		("directionalLight["+indexSTR+"].specular")		.c_str());
		_uniformAssignedLight = glGetUniformLocation(_renderer->GetShader(),("directionalLight["+indexSTR+"].assigned")		.c_str());
	}
	void DirectionalLight::UseLight() {
		glUseProgram(_renderer->GetShader());
		glUniform3f(_uniformColour, _colour.x, _colour.y, _colour.z);
		glUniform3f(_uniformDirection, _direction.x, _direction.y, _direction.z);
		glUniform3f(_uniformAmbient, _ambient.x, _ambient.y, _ambient.z);
		glUniform3f(_uniformDiffuse, _diffuse.x, _diffuse.y, _diffuse.z);
		glUniform3f(_uniformSpecular, _specular.x, _specular.y, _specular.z);
		glUniform1i(_uniformAssignedLight, true);
		glUseProgram(0);
		_renderer->SetLights(true);
	}

}