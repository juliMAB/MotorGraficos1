#ifndef ENTITY_H
#define ENTITY_H

#include "src/Exports/Exports.h"
#include <glew.h>
#include <glfw3.h>
#include "src/Renderer/Renderer.h"

namespace Graficos1 {

	class GraficosEngine_API Entity {
	protected:
		Renderer* _renderer;
	public:
		Entity();
		Entity(Renderer* rend);
		~Entity();
		void SetRenderer(Renderer* r);
		Renderer* GetRenderer();
	};

}

#endif;