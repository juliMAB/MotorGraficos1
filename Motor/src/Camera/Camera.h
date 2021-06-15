#ifndef CAMERA_H
#define CAMERA_H

#include "../Entity/Entity.h"
#include "../Exports/Exports.h"

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Camera : public Entity{
		uint _uniformCameraPosition;
		glm::mat4 _viewMatrix;
	public:
		Camera(Renderer* r);
		~Camera();
		void InitCamera(glm::vec3 pos, glm::vec3 up);
		glm::mat4 GetViewMatrix();
		void LookAt(glm::vec3 direction);
		void UseCamera();
	};

}

#endif