#include "DirectionalLight.h"
#include "glew.h"

namespace Coco {

	DirectionalLight::DirectionalLight(Renderer* rend) : Light(rend) {
		_typeOfLight = TypeOfLight::Directional;
		SetUniforms();
	}
	DirectionalLight::~DirectionalLight() {

	}
	void DirectionalLight::SetUniforms() {
		_uniformColour = glGetUniformLocation(_renderer->GetShader(), "directionalLight.colour");
		_uniformDirection = glGetUniformLocation(_renderer->GetShader(), "directionalLight.direction");
		_uniformAmbient = glGetUniformLocation(_renderer->GetShader(), "directionalLight.ambient");
		_uniformDiffuse = glGetUniformLocation(_renderer->GetShader(), "directionalLight.diffuse");
		_uniformSpecular = glGetUniformLocation(_renderer->GetShader(), "directionalLight.specular");
		_uniformTypeOfLight = glGetUniformLocation(_renderer->GetShader(), "typeOfLight");
	}
	void DirectionalLight::UseLight() {
		glUseProgram(_renderer->GetShader());
		glUniform3f(_uniformColour, _colour.x, _colour.y, _colour.z);
		glUniform3f(_uniformDirection, _direction.x, _direction.y, _direction.z);
		glUniform3f(_uniformAmbient, _ambient.x, _ambient.y, _ambient.z);
		glUniform3f(_uniformDiffuse, _diffuse.x, _diffuse.y, _diffuse.z);
		glUniform3f(_uniformSpecular, _specular.x, _specular.y, _specular.z);
		glUniform1i(_uniformTypeOfLight, _typeOfLight);
		glUseProgram(0);
		_renderer->SetLights(true);
	}

}