#ifndef ENTITY_H
#define ENTITY_H

#include "../src/Exports/Exports.h"
#include "../src/Renderer/Renderer.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace Coco {

	class GraficosEngine_API Entity {
	private:
		struct Transform {
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;

			glm::vec3 forward;
			glm::vec3 up;
			glm::vec3 right;
		};
		struct Matrix {
			glm::mat4 model;
			glm::mat4 translate;
			glm::mat4 rotationX;
			glm::mat4 rotationY;
			glm::mat4 rotationZ;
			glm::mat4 scale;
		};
	protected:
		glm::vec3 _worldUp;
		Renderer* _renderer;
		void UpdateMatrixData();

		uint _uniformModel;
		uint _uniformView;
		uint _uniformProjection;
		uint _positionLocation;
		uint _texLocation;
		uint _normalLocation;
	public:
		Entity(Renderer* rend);
		~Entity();

		Transform transform;
		Matrix matrix;

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