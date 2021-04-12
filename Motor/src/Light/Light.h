#ifndef LIGHT_H
#define LIGHT_H

#include "../Entity/Entity.h"

namespace Graficos1 {

	class GraficosEngine_API Light : public Entity {
		glm::vec3 _colour;
		float _ambientIntensity;
		glm::vec3 _direction;
		float _diffuseIntensity;
	public:
		Light();
		Light(Renderer* rend);
		Light(Renderer* rend, float r, float g, float b, float ambientIntensity, float dirX, float dirY, float dirZ, float diffuseIntensity);
		~Light();
		void UseLight();
		void TurnOffLight();
		void SetColorsLight(float r, float g, float b, float ambientIntensity);
		void SetDirection(float dirX, float dirY, float dirZ);
		void SetDiffuseIntensity(float diffuseIntensity);
	};

}

#endif