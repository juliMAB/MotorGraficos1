#ifndef LIGHT_H
#define LIGHT_H

#include "../Entity/Entity.h"

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Light : public Entity {
	protected:
		glm::vec3 _colour;
		glm::vec3 _direction;
		glm::vec3 _ambient;
		glm::vec3 _diffuse;
		glm::vec3 _specular;

		uint _uniformColour;
		uint _uniformPosition;
		uint _uniformDirection;
		uint _uniformAmbient;
		uint _uniformDiffuse;
		uint _uniformSpecular;

		uint _uniformAssignedLight;
		bool _usingLight;

		int _index;
		virtual void SetUniforms();
	public:
		Light(Renderer* rend, int index);
		~Light();
		virtual void UseLight();
		void SetColour(glm::vec3 c);
		void SetDirection(glm::vec3 d);
		void SetAmbient(glm::vec3 a);
		void SetDiffuse(glm::vec3 d);
		void SetSpecular(glm::vec3 s);
		glm::vec3 GetColour();
		glm::vec3 GetDirection();
		glm::vec3 GetAmbient();
		glm::vec3 GetDiffuse();
		glm::vec3 GetSpecular();
		bool GetUsingLight();
	};

}

#endif