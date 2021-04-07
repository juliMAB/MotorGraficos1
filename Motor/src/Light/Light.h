#ifndef LIGHT_H
#define LIGHT_H

#include "../Entity/Entity.h"

namespace Graficos1 {

	class GraficosEngine_API Light : public Entity {
		glm::vec3 _colour;
		float _ambientIntensity;
	public:
		Light();
		Light(Renderer* rend);
		Light(Renderer* rend, float r, float g, float b, float ambientIntensity);
		~Light();
		void UseLight();
		void TurnOffLight();
	};

}

#endif