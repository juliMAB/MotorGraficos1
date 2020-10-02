#ifndef RENDERER_H
#define RENDERER_H

#include "../src/Exports/Exports.h"
#include "../src/Shaders/VertexShader.shader"
#include "../src/Shaders/FragmentShader.shader"

namespace Graficos1 {
	typedef unsigned int uint;
	class GraficosEngine_API  Renderer {
		uint _shader;
		void AddShader(uint program, const char* shaderCode, uint type);
		void CompileShaders();
	public:
		Renderer();
		~Renderer();
		int InitGlew();
		void InitShaders();
		void StopShaders();
		void Draw(uint shape, int verts, uint vao);
		uint GetShader();
	};

}

#endif;