#include "PointLight.h"
#include "glew.h"

namespace Coco {
	PointLight::PointLight(Renderer* rend) : Light(rend) {
		_constant = 1.0f;
		_linear = 1.0f;
		_quadratic = 1.0f;
		_typeOfLight = TypeOfLight::Point;

		SetUniforms();

	}
	PointLight::PointLight(Renderer* rend, float constant, float linear, float quadratic) : Light(rend) {
		_constant = constant;
		_linear = linear;
		_quadratic = quadratic;
		_typeOfLight = TypeOfLight::Point;
		SetUniforms();
	}
	PointLight::~PointLight() {
	
	}
	void PointLight::SetUniforms() {
		_uniformPosition = glGetUniformLocation(_renderer->GetShader(), "pointLight.position");
		_uniformColour = glGetUniformLocation(_renderer->GetShader(), "pointLight.colour");
		_uniformAmbient = glGetUniformLocation(_renderer->GetShader(), "pointLight.ambient");
		_uniformDiffuse = glGetUniformLocation(_renderer->GetShader(), "pointLight.diffuse");
		_uniformSpecular = glGetUniformLocation(_renderer->GetShader(), "pointLight.specular");
		_uniformConstant = glGetUniformLocation(_renderer->GetShader(), "pointLight.constant");
		_uniformLinear = glGetUniformLocation(_renderer->GetShader(), "pointLight.linear");
		_uniformQuadratic = glGetUniformLocation(_renderer->GetShader(), "pointLight.quadratic");
		_uniformTypeOfLight = glGetUniformLocation(_renderer->GetShader(), "typeOfLight");
	}
	void PointLight::UseLight() {
		glUseProgram(_renderer->GetShader());
		glUniform3f(_uniformPosition, positionVec.x, positionVec.y, positionVec.z);
		glUniform3f(_uniformColour, _colour.x, _colour.y, _colour.z);
		glUniform3f(_uniformAmbient, _ambient.x, _ambient.y, _ambient.z);
		glUniform3f(_uniformDiffuse, _diffuse.x, _diffuse.y, _diffuse.z);
		glUniform3f(_uniformSpecular, _specular.x, _specular.y, _specular.z);

		glUniform1f(_uniformConstant, _constant);
		glUniform1f(_uniformLinear, _linear);
		glUniform1f(_uniformQuadratic, _quadratic);

		glUniform1i(_uniformTypeOfLight, _typeOfLight);
		glUseProgram(0);
		_renderer->SetLights(true);
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