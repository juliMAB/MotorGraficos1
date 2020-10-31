#ifndef RENDERER_H
#define RENDERER_H

#include "../src/Exports/Exports.h"
#include "../src/Shaders/VertexShader.shader"
#include "../src/Shaders/FragmentShader.shader"
#include "../src/Shaders/FragmentShaderTex.shader"
#include <glm/mat4x4.hpp>

namespace Graficos1 {
	typedef unsigned int uint;
	static enum TypeShader {
		Colour,
		Texture
	};
	class GraficosEngine_API  Renderer {
		uint _shader;
		TypeShader _typeShader;
		void AddShader(uint program, const char* shaderCode, uint type);
		void CompileShaders();
	public:
		Renderer();
		~Renderer();
		int InitGlew();
		void SetBuffers(int tam, float* verts, uint& vbo, uint& vao);
		void SetQuadThings(int tam, uint* indexs);
		void SetAttribs(glm::mat4 model);
		void SetTypeOfShader(TypeShader t);
		void InitShaders();
		void UpdateModel(glm::mat4 model);
		void StopShaders();
		void Draw(uint shape, int verts, uint vao);
		uint GetShader();
	};

}

#endif;