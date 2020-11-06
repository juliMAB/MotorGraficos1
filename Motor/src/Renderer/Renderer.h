#ifndef RENDERER_H
#define RENDERER_H

#include "../src/Exports/Exports.h"
#include "../src/Shaders/VertexShader.shader"
#include "../src/Shaders/FragmentShader.shader"
#include <glm/mat4x4.hpp>
#include "../src/Window/Window.h"
namespace Graficos1 {
	typedef unsigned int uint;
	static enum TypeShader {
		Colour,
		Texture
	};
	class GraficosEngine_API  Renderer {
		uint _shader;
		void AddShader(uint program, const char* shaderCode, uint type);
		void CompileShaders();
	public:
		Renderer();
		~Renderer();
		int InitGlew();
		void SetBuffers(int tam, float* verts, uint& vbo, uint& vao);
		void SetQuadThings(int tam, uint* indexs);
		void SetAttribs(glm::mat4 model, TypeShader t);
		void InitShaders();
		void UpdateModel(glm::mat4 model);
		void StopShaders();
		void Draw(uint shape, int verts, uint vao);
		uint GetShader();
	};

}

#endif;