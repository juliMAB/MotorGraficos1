#ifndef MATERIAL_H
#define MATERIAL_H

#include "../src/Exports/Exports.h"
#include "glm/vec3.hpp"
namespace Graficos1 {

	class GraficosEngine_API  Material {
		float _specularIntensity;
		float _shininess;
		glm::vec3 _ambient;
		glm::vec3 _diffuse;
		glm::vec3 _specular;
	public:
		Material();
		~Material();

		void SetAmbient(glm::vec3 amb);
		void SetDiffuse(glm::vec3 diff);
		void SetSpecular(glm::vec3 spec);
		void SetShininess(float s);
		glm::vec3 GetAmbient();
		glm::vec3 GetDiffuse();
		glm::vec3 GetSpecular();
		float GetShininess();
	};

}

#endif