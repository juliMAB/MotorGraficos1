#ifndef MATERIAL_H
#define MATERIAL_H

#include "../src/Exports/Exports.h"
#include <glm/vec4.hpp>

namespace Graficos1 {

	class GraficosEngine_API  Material{
		glm::vec4 _mat;
	public:
		Material();
		Material(float r, float g, float b, float a);
		~Material();
		void SetMaterial(float r, float g, float b, float a);
		glm::vec4 GetMaterial();
	};

}

#endif