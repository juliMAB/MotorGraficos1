#ifndef ENTITY2D_H
#define	ENTITY2D_H

#include "src/Exports/Exports.h"
#include <glew.h>
#include <glfw3.h>
#include "src/Entity/Entity.h"
#include "src/Material/Material.h"

namespace Graficos1 {

	class GraficosEngine_API Entity2D : public Entity {
		Material* _mat;
	public:							
		Entity2D();
		~Entity2D();
		void SetMaterial(Material* mat);
		Material* GetMaterial();
		//void SetVertexShader(float* vertices, tam, )
	};

}

#endif