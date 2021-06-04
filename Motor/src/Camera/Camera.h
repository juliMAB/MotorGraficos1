#ifndef CAMERA_H
#define CAMERA_H

#include "../Entity/Entity.h"
#include "../Exports/Exports.h"

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Camera : public Entity{
		uint _uniformCameraPosition;
		float _yaw;
		float _pitch;
	public:
		Camera(Renderer* r);
		~Camera();
		void InitCamera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch);
		glm::mat4 CalculateViewMatrix();
		void UpdateCamera();
		void UseCamera();
		void SetPitch(float p);
		void SetYaw(float y);
		float GetPitch();
		float GetYaw();
	};

}

#endif