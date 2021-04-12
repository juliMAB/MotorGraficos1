#ifndef SHAPE_H
#define SHAPE_H

#include "../src/Exports/Exports.h"
#include "../src/Entity2D/Entity2D.h"
#include "../src/Material/Material.h"

#define TRIANGLE 0x0004
#define QUAD 0x0007

namespace Graficos1 {

	typedef unsigned int uint;
	class GraficosEngine_API Shape : public Entity2D {
		float* _vb;
		uint _vbo;
		uint _vao;
		uint _ibo;

		float cubeVerticesCol[88]{
			-1.0, -1.0, 1.0,/**/  1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/ 0.0f, 0.0f, 0.0f,
			1.0, -1.0, 1.0,	/**/  1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			1.0, 1.0, 1.0,	/**/  1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			-1.0, 1.0, 1.0,	/**/  1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			-1.0, -1.0, -1.0,/**/ 1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			1.0, -1.0, -1.0, /**/ 1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			1.0, 1.0, -1.0,	 /**/ 1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			-1.0, 1.0, -1.0, /**/ 1.0f,0.0f,0.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f
		};
		
	public:
		Shape();
		Shape(Renderer* rend, Material* mat);
		~Shape();
		void InitShape(TypeShape type, TypeShader t);
		void CreateShape();
		void DrawShape();
		int GetVerticesArrLenght();
		int GetVerticesTam();
		float* GetVertices();
		float GetVertexIndex(int ind);
		uint GetType();
		int GetIndexTam();
		unsigned int* GetIndexs();
		void CalcAverageNormals(uint * indices, uint indiceCount, float * vertices, uint verticeCount, uint vLength, uint normalOffset);
	};

}

#endif