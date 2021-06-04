#include "PointLight.h"
#include "glew.h"
#include <iostream>
namespace Coco {
	PointLight::PointLight(Renderer* rend, int index) : Light(rend, index) {
		_constant = 1.0f;
		_linear = 1.0f;
		_quadratic = 1.0f;

		SetUniforms();
	}
	PointLight::PointLight(Renderer* rend, float constant, float linear, float quadratic, int index) : Light(rend, index) {
		_constant = constant;
		_linear = linear;
		_quadratic = quadratic;
		SetUniforms();
	}
	PointLight::~PointLight() {

	}
	void PointLight::SetUniforms() {
		std::string indexSTR = std::to_string(_index).c_str();

		_uniformPosition = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].position").c_str());
		_uniformColour = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].colour").c_str());
		_uniformAmbient = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].ambient").c_str());
		_uniformDiffuse = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].diffuse").c_str());
		_uniformSpecular = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].specular").c_str());
		_uniformConstant = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].constant").c_str());
		_uniformLinear = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].linear").c_str());
		_uniformQuadratic = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].quadratic").c_str());
		_uniformAssignedLight = glGetUniformLocation(_renderer->GetShader(), ("pointLight[" + indexSTR + "].assigned").c_str());
	}
	void PointLight::UseLight() {
		glUseProgram(_renderer->GetShader());
		glUniform3f(_uniformPosition, transform.position.x, transform.position.y, transform.position.z);
		glUniform3f(_uniformColour, _colour.x, _colour.y, _colour.z);
		glUniform3f(_uniformAmbient, _ambient.x, _ambient.y, _ambient.z);
		glUniform3f(_uniformDiffuse, _diffuse.x, _diffuse.y, _diffuse.z);
		glUniform3f(_uniformSpecular, _specular.x, _specular.y, _specular.z);

		glUniform1f(_uniformConstant, _constant);
		glUniform1f(_uniformLinear, _linear);
		glUniform1f(_uniformQuadratic, _quadratic);

		glUniform1i(_uniformAssignedLight, true);
		glUseProgram(0);
		_renderer->SetLights(true);
	}
	void PointLight::SetConstantLinearQuadratic(float c, float l, float q) {
		SetConstant(c);
		SetLinear(l);
		SetQuadratic(q);
	}
	void PointLight::SetConstant(float c) {
		_constant = c;
	}
	void PointLight::SetLinear(float l) {
		_linear = l;
	}
	void PointLight::SetQuadratic(float q) {
		_quadratic = q;
	}
	float PointLight::GetConstant() {
		return _constant;
	}
	float PointLight::GetLinear() {
		return _linear;
	}
	float PointLight::GetQuadratic() {
		return _quadratic;
	}
}