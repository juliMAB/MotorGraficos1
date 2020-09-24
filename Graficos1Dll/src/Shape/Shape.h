#ifndef SHAPE_H
#define SHAPE_H

#include "src/Exports/Exports.h"
#include <glew.h>
#include <glfw3.h>
#include "src/Entity2D/Entity2D.h"
#include "src/Renderer/Renderer.h"
#include "src/Material/Material.h"

namespace Graficos1 {

	class GraficosEngine_API Shape : public Entity2D {
	public:
		Shape();
		Shape(Renderer* rend, Material* mat);
		~Shape();
		void InitShape(GLenum type);
		void CreateShape();
		void DrawShape();
		void SetColor(float r, float g, float b);
		int GetVerticesArrLenght();
		int GetVerticesTam();
		float* GetVertices();
		float GetVertexIndex(int ind);
		GLenum GetType();
		int GetIndexTam();
		unsigned int* GetIndexs();
	};
		
}

#endif