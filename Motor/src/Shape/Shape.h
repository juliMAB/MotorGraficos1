#ifndef SHAPE_H
#define SHAPE_H

#include "../src/Exports/Exports.h"
#include "../src/Entity/Entity.h"
#include "../src/Material/Material.h"

#define TRIANGLE 0x0004
#define QUAD 0x0007

namespace Graficos1 {

	typedef unsigned int uint;
	class GraficosEngine_API Shape : public Entity {
		float* _vb;
		uint _vbo;
		uint _vao;
		uint _ibo;

		float cubeVerticesCol[64]{
			-1.0, -1.0, 1.0,/**/ 0.0f, 0.0f, /**/ 0.0f, 0.0f, 0.0f,
			1.0, -1.0, 1.0,	/**/ 0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			1.0, 1.0, 1.0,	/**/ 0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			-1.0, 1.0, 1.0,	/**/ 0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			-1.0, -1.0, -1.0,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			1.0, -1.0, -1.0, /**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			1.0, 1.0, -1.0,	 /**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
			-1.0, 1.0, -1.0, /**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f
		};

		uint _uniformModel;
		uint _uniformView;
		uint _uniformProjection;
		uint _positionLocation;
		uint _texLocation;
		uint _normalLocation;

		Material* _material;
	public:
		Shape(Renderer* rend);
		~Shape();
		void InitShape(TypeShape type, TypeShader t);
		void DrawShape();
		void SetMaterial(Material* m);
		Material* GetMaterial();
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