#ifndef ENTITY2D_H
#define ENTITY2D_H

#include "../src/Exports/Exports.h"
#include "../src/Entity/Entity.h"
#include "../src/Material/Material.h"

namespace Graficos1 {

	class GraficosEngine_API Entity2D : public Entity {
	protected:
		glm::vec3 _bc2D;
	public:
		Material* _mat;
		Entity2D(Renderer* rend, Material* mat);
		~Entity2D();
		void SetBoxCollider(float x, float y, float z);
		glm::vec3 GetBoxCollider();
		void SetMaterial(Material* mat);
		Material* GetMaterial();
	};

}

#endif