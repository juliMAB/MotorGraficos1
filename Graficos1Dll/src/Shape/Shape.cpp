#include "pch.h"
#include "Shape.h"
#include <iostream>
#include <iterator>

namespace Graficos1 {
	float triangleVertices[] = {
		0.0f, 1.0f, 0.0f,	/**/ 1.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f,	/**/ 1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,	/**/ 1.0f, 0.0f, 1.0f
	};

	float quadVertices[] = {
	/* 0 */	-0.5,  0.5, 0.0f,	/**/ 1.0f, 0.0f, 0.0f,
	/* 1 */	-0.5, -0.5, 0.0f,	/**/ 0.0f, 1.0f, 0.0f,
	/* 2 */	 0.5, -0.5, 0.0f,	/**/ 0.0f, 0.0f, 1.0f,
	/* 3 */	 0.5,  0.5, 0.0f,	/**/ 0.0f, 0.0f, 0.0f
	};

	unsigned int posIndexs[] = {
		0, 1, 2,
		2, 3, 0
	};

	GLenum typeOfShape;

	Shape::Shape() {

	}
	Shape::~Shape() {

	}
	void Shape::InitShape(GLenum type) {
		typeOfShape = type;
	}
	void Shape::DrawShape() {
		if (typeOfShape == GL_TRIANGLES) {
			glDrawArrays(GL_TRIANGLES, 0, 3);
			return;
		}

		glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT, nullptr);
	}

	int Shape::GetVerticesArrLenght() {
		if (typeOfShape == GL_TRIANGLES)
			return (sizeof(triangleVertices) / sizeof(triangleVertices[0]));

		return (sizeof(quadVertices) / sizeof(quadVertices[0]));
	}
	int Shape::GetVerticesTam() {
		if (typeOfShape == GL_TRIANGLES)
			return sizeof(triangleVertices);

		return sizeof(quadVertices);
	}
	float* Shape::GetVertices() {
		if (typeOfShape == GL_TRIANGLES)
			return triangleVertices;

		return quadVertices;
	}
	float Shape::GetVertexIndex(int ind) {
		if (typeOfShape == GL_TRIANGLES)
			return triangleVertices[ind];

		return quadVertices[ind];
	}
	GLenum Shape::GetType() {
		return typeOfShape;
	}
	int Shape::GetIndexTam() {
		return sizeof(posIndexs);
	}
	unsigned int* Shape::GetIndexs() {
		return posIndexs;
	}
}