#ifndef CAMERA_H
#define CAMERA_H

#include "../Entity/Entity.h"
#include "../Exports/Exports.h"

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Camera : public Entity{
		glm::vec3 _front;
		glm::vec3 _up;
		glm::vec3 _right;
		glm::vec3 _worldUp;
		uint _uniformCameraPosition;
		float _yaw;
		float _pitch;
	public:
		Camera();
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
		glm::vec3 GetFront();
		glm::vec3 GetUp();
		glm::vec3 GetRight();
	};

}

#endif