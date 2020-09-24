#ifndef RENDERER_H
#define RENDERER_H

#include "src/Exports/Exports.h"
#include <glew.h>
#include <glfw3.h>
#include "src/Shaders/VertexShader.h"
#include "src/Shaders/FragmentShader.h"

namespace Graficos1 {
	typedef unsigned int uint;
	class GraficosEngine_API  Renderer {
		uint _shader;
		void AddShader(uint program, const char* shaderCode, GLenum type);
		void CompileShaders();
	public:
		Renderer();
		~Renderer();
		int InitGlew();
		void InitShaders();
		void StopShaders();
		void Draw(GLenum shape, int verts, uint vao);
		uint GetShader();
	};

}

#endif;