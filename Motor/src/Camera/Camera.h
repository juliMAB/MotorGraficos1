#ifndef CAMERA_H
#define CAMERA_H

#include "../Entity/Entity.h"
#include "../Exports/Exports.h"

namespace Graficos1 {

	class GraficosEngine_API Camera : public Entity{
		glm::vec3 _front;
		glm::vec3 _up;
		glm::vec3 _right;
		glm::vec3 _worldUp;

		float _yaw;
		float _pitch;
	public:
		Camera();
		~Camera();
		void InitCamera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch);
		glm::mat4 CalculateViewMatrix();
		void UpdateCamera();
	};

}

#endif