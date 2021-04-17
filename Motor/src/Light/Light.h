#ifndef LIGHT_H
#define LIGHT_H

#include "../Entity/Entity.h"

namespace Graficos1 {
	typedef unsigned int uint;
	class GraficosEngine_API Light : public Entity {
		glm::vec3 _colour;
		glm::vec3 _ambient;
		glm::vec3 _diffuse;
		glm::vec3 _specular;

		uint _uniformColour;
		uint _uniformAmbient;
		uint _uniformDiffuse;
		uint _uniformSpecular;
		uint _uniformPosition;
		uint _uniformUsingLight;
	public:
		Light(Renderer* rend);
		~Light();
		void UseLight();
		void TurnOffLight();
		void SetColour(glm::vec3 c);
		void SetAmbient(glm::vec3 a);
		void SetDiffuse(glm::vec3 d);
		void SetSpecular(glm::vec3 s);
		glm::vec3 GetColour();
		glm::vec3 GetAmbient();
		glm::vec3 GetDiffuse();
		glm::vec3 GetSpecular();
	};

}

#endif