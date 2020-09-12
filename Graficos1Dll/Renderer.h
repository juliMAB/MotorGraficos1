#ifndef RENDERER_H
#define RENDERER_H

#include <glew.h>
#include <glfw3.h>

namespace Graficos1 {

	class Renderer {
	public:
		Renderer();
		~Renderer();
		void Draw();
	};

}

#endif;