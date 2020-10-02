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
		glm::vec3 positionVec;
		glm::vec3 rotationVec;
		glm::vec3 scaleVec;

		glm::mat4 model;
		glm::mat4 translate;
		glm::mat4 rotationX;
		glm::mat4 rotationY;
		glm::mat4 rotationZ;
		glm::mat4 scale;
		Renderer* _renderer;
		void UpdateMatrixData();
	public:
		Entity();
		Entity(Renderer* rend);
		~Entity();
		void SetRenderer(Renderer* r);
		Renderer* GetRenderer();
		void SetPos(float x, float y, float z);
		void SetRotX(float x);
		void SetRotY(float y);
		void SetRotZ(float z);
		void SetScale(float x, float y, float z);
	};

}

#endif;