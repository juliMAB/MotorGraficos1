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
	//enum TypeOfModel {
	//	ThirdDimension, SecondDimension
	//};
	enum TypeShape {
		Triangle, Quad, Cube, Pyramid
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
		void SetIndexThings(int tam, uint* indexs, uint& ibo);
		void SetAttribs(glm::mat4 model, TypeShader t);
		void InitShaders();
		void UpdateModel(glm::mat4 model, glm::mat4 projection);
		void StopShaders();
		void Draw(TypeShape shape, int verts, uint vao, uint vbo, uint ibo, float* vertexs, float tamVertexs, TypeShader t);
		uint GetShader();
	};

}

#endif;