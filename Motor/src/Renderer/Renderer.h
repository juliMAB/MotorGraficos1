#ifndef RENDERER_H
#define RENDERER_H

#include "../src/Exports/Exports.h"
#include "../Shader/Shader.h"
#include <glm/mat4x4.hpp>
#include "../src/Window/Window.h"
namespace Coco {
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
		Shader* _shader;
	public:
		Renderer();
		~Renderer();
		int InitGlew();
		void CreateShader(const char* vertexCode, const char* fragmentCode);
		void SetProjection(glm::mat4 p);
		void SetView(glm::mat4 v);
		void SetBuffers(int tam, float* verts, uint& vbo, uint& vao);
		void SetIndexThings(int tam, uint* indexs, uint& ibo);
		void SetAttribs(uint location, int size, int stride, int offset);
		void UpdateMVP(glm::mat4 model, uint uniformModel, uint uniformView, uint uniformProjection);
		void StopShaders();
		void Draw(TypeShape shape, int verts, uint vao, uint vbo, uint ibo, float* vertexs, float tamVertexs, TypeShader t, bool affectedByLight);
		void DrawMesh(int verts, uint vao, uint vbo, uint ibo, bool affectedByLight);
		void SetLights(bool value);
		void UseCamera(glm::vec3 cameraPos, uint uniformCameraPos);
		void UseMaterial(glm::vec3 amb, glm::vec3 spec, glm::vec3 diff, float shine,
			uint uniformAmbient, uint uniformSpecular, uint uniformDiffuse, uint uniformShininess);
		uint GetShader();

		glm::mat4 GetView();
	};

}

#endif;