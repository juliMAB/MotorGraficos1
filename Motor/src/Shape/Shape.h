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
		
	public:
		Shape();
		Shape(Renderer* rend, Material* mat);
		~Shape();
		void InitShape(uint type, TypeShader t);
		void CreateShape();
		void DrawShape();
		void SetColor(float c1[3], float c2[3], float c3[3]);
		int GetVerticesArrLenght();
		int GetVerticesTam();
		float* GetVertices();
		float GetVertexIndex(int ind);
		uint GetType();
		int GetIndexTam();
		unsigned int* GetIndexs();
	};

}

#endif