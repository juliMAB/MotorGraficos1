#include "Material.h"
#include "../src/Shaders/VertexShader.h"
namespace Graficos1 {

	Material::Material() {
		_mat = { 0.0f, 0.0f, 0.0f, 1.0f };
	}
	Material::Material(float r, float g, float b, float a) {
		_mat = { r, g, b, a };
	}
	Material::~Material() {

	}
	void Material::SetMaterial(float r, float g, float b, float a) {
		_mat[0] = r;
		_mat[1] = g;
		_mat[2] = b;
		_mat[3] = a;
	}
	glm::vec4 Material::GetMaterial() {
		return _mat;
	}

}