#include "Material.h"
namespace Graficos1 {

	Material::Material() {
		_specularIntensity = 0.0f;
		_shininess = 0.0f;
	}
	Material::Material(float sIntensity, float shine) {
		_specularIntensity = sIntensity;
		_shininess = shine;
	}
	Material::~Material() {

	}
	float Material::GetSpecularIntensity() {
		return _specularIntensity;
	}
	float Material::GetShininess() {
		return _shininess;
	}
	void Material::SetSpecularIntensity(float si) {
		_specularIntensity = si;
	}
	void Material::SetShininess(float s) {
		_shininess = s;
	}

}