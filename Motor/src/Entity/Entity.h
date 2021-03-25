#ifndef ENTITY_H
#define ENTITY_H

#include "../src/Exports/Exports.h"
#include "../src/Renderer/Renderer.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace Graficos1 {

	class GraficosEngine_API Entity {
	private:
	protected:
		glm::mat4 model;
		glm::mat4 projection = glm::perspective(45.0f, 1366.0f / 768.0f, 0.1f, 100.0f);
		glm::mat4 translate;
		glm::mat4 rotationX;
		glm::mat4 rotationY;
		glm::mat4 rotationZ;
		glm::mat4 scale;
		glm::vec3 lastPos;
		Renderer* _renderer;
		void UpdateMatrixData();
	public:
		Entity();
		Entity(Renderer* rend);
		~Entity();
		glm::vec3 positionVec;
		glm::vec3 rotationVec;
		glm::vec3 scaleVec;
		glm::vec3 forcesVec;
		void SetRenderer(Renderer* r);
		Renderer* GetRenderer();
		void SetProjection(glm::mat4 proj);
		void SetPos(float x, float y, float z);
		void SetRotX(float x);
		void SetRotY(float y);
		void SetRotZ(float z);
		void SetLastPos();
		void SetScale(float x, float y, float z);
		void AddForce(float x, float y, float z);
		void SetForces(float x, float y, float z);
		void UpdateForces();
		void ResetPos();
	};

}

#endif;