#include "Shape.h"
#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {
	float triangleVertices[] = {
		 0.0f,  0.5f, 0.0f,	/**/ 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f
	};

	float triangleModel[] = {
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f
	};

	float quadVertices[] = {
		/* 0 */	-0.5,  0.5, 0.0f, /**/ 1.0f, 0.0f, 0.0f,
		/* 1 */	-0.5, -0.5, 0.0f, /**/ 0.0f, 1.0f, 0.0f,
		/* 2 */	 0.5, -0.5, 0.0f, /**/ 0.0f, 0.0f, 1.0f,
		/* 3 */	 0.5,  0.5, 0.0f, /**/ 0.0f, 0.0f, 0.0f
	};

	unsigned int posIndexs[] = {
		0, 1, 2,
		2, 3, 0
	};

	typedef unsigned int uint;

	uint typeOfShape;

	uint tamVerts;

	Shape::Shape() : Entity2D() { }
	Shape::Shape(Renderer* rend, Material* mat) : Entity2D(rend, mat) {	}
	Shape::~Shape() {
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
	}
	void Shape::InitShape(uint type) {
		typeOfShape = type;
		if (type == GL_TRIANGLES) {
			_vb = triangleVertices;
			tamVerts = sizeof(triangleVertices);

			return;
		}

		_vb = quadVertices;
		tamVerts = sizeof(quadVertices);
	}
	void Shape::CreateShape() {
		_renderer->SetAttribs(GetVerticesTam(), _vb, _vbo, _vao, model);
		//if (typeOfShape == GL_QUADS) {
		//	unsigned int ibo;
		//	glGenBuffers(1, &ibo);
		//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexTam(), GetIndexs(), GL_STATIC_DRAW);
		//}
	}
	void Shape::DrawShape() {
		_renderer->UpdateModel(model);

		if (typeOfShape == GL_TRIANGLES) {
			_renderer->Draw(typeOfShape, 3, _vao);
			return;
		}

		_renderer->Draw(typeOfShape, 6, _vao);
	}
	void Shape::SetColor(float c1[3], float c2[3], float c3[3]) {
		if (typeOfShape == GL_TRIANGLES) {
			triangleVertices[3] = c1[0];
			triangleVertices[4] = c1[1];
			triangleVertices[5] = c1[2];

			triangleVertices[9] = c2[0];
			triangleVertices[10] = c2[1];
			triangleVertices[11] = c2[2];

			triangleVertices[15] = c3[0];
			triangleVertices[16] = c3[1];
			triangleVertices[17] = c3[2];

			_renderer->SetAttribs(GetVerticesTam(), _vb, _vbo, _vao, model);

			return;
		}

		quadVertices[3] = c1[0];
		quadVertices[4] = c1[1];
		quadVertices[5] = c1[2];

		quadVertices[9] = c2[0];
		quadVertices[10] = c2[1];
		quadVertices[11] = c2[2];

		quadVertices[15] = c3[0];
		quadVertices[16] = c3[1];
		quadVertices[17] = c3[2];

		quadVertices[21] = 0.0f;
		quadVertices[22] = 0.0f;
		quadVertices[23] = 0.0f;

		unsigned int ibo;
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexTam(), GetIndexs(), GL_STATIC_DRAW);

		_renderer->SetAttribs(GetVerticesTam(), _vb, _vbo, _vao, model);
	}
	int Shape::GetVerticesArrLenght() {
		return tamVerts / sizeof(float);
		
		//if (typeOfShape == GL_TRIANGLES)
		//	return (sizeof(triangleVertices) / sizeof(triangleVertices[0]));
		//
		//return (sizeof(quadVertices) / sizeof(quadVertices[0]));
	}
	int Shape::GetVerticesTam() {
		return tamVerts;
	}
	float* Shape::GetVertices() {
		return _vb;
		
		//if (typeOfShape == GL_TRIANGLES)
		//	return triangleVertices;
		//
		//return quadVertices;
	}
	float Shape::GetVertexIndex(int ind) {
		return _vb[ind];

	//	if (typeOfShape == GL_TRIANGLES)
	//		return triangleVertices[ind];
	//
	//	return quadVertices[ind];
	}
	uint Shape::GetType() {
		return typeOfShape;
	}
	int Shape::GetIndexTam() {
		return sizeof(posIndexs);
	}
	unsigned int* Shape::GetIndexs() {
		return posIndexs;
	}
}