#ifndef CAMERA_H
#define CAMERA_H

#include "../Entity/Entity.h"
#include "../Exports/Exports.h"

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Camera : public Entity{
		uint _uniformCameraPosition;
		glm::mat4 _viewMatrix;
		Entity* _entity;
	public:
		Camera(Renderer* r);
		~Camera();
		glm::mat4 GetViewMatrix();
		void LookAt(glm::vec3 direction);
		void FirstPersonLook(glm::vec3 offset, bool drawEntity);
		void ThirdPersonLook(glm::vec3 offset, float distance, bool drawEntity);
		void SetEntity(Entity* entity);
		void UseCamera();
	};

}

#endif