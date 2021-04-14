#ifndef MATERIAL_H
#define MATERIAL_H

#include "../src/Exports/Exports.h"

namespace Graficos1 {

	class GraficosEngine_API  Material {
		float _specularIntensity;
		float _shininess;
	public:
		Material();
		Material(float sIntensity, float shine);
		~Material();

		float GetSpecularIntensity();
		float GetShininess();
		void SetSpecularIntensity(float si);
		void SetShininess(float s);
	};

}

#endif