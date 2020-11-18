#include "Shape.h"
#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {

	float triangleVerticesCol[24] = {
		0.0f, 1.0f, 0.0f,	/**/ 1.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f
	};

	float quadVerticesCol[32] = {
		-1.0, 1.0, 1.0f, /**/ 1.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f,
		-1.0, -1.0, 1.0f, /**/ 0.0f, 1.0f, 0.0f,/**/ 0.0f, 0.0f,
		1.0, -1.0, 1.0f, /**/ 0.0f, 0.0f, 1.0f,/**/ 0.0f, 0.0f,
		1.0, 1.0, 1.0f, /**/ 0.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f
	};

	unsigned int posIndexs[] = {
		0, 1, 2,
		2, 3, 0
	};

	typedef unsigned int uint;

	uint typeOfShape;
	TypeShader typeShader;
	uint tamVerts;

	Shape::Shape() : Entity2D() { }
	Shape::Shape(Renderer* rend, Material* mat) : Entity2D(rend, mat) {	}
	Shape::~Shape() {
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
	}
	void Shape::InitShape(uint type, TypeShader t) {
		typeOfShape = type;
		typeShader = t;
		if (type == GL_TRIANGLES) {
			_vb = triangleVerticesCol;
			tamVerts = sizeof(triangleVerticesCol);

			return;
		}

		_vb = quadVerticesCol;
		tamVerts = sizeof(quadVerticesCol);
	}
	void Shape::CreateShape() {
		_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
		if (typeOfShape == GL_QUADS)
			_renderer->SetQuadThings(GetVerticesTam(), GetIndexs());
		_renderer->SetAttribs(model, TypeShader::Colour);
	}
	void Shape::DrawShape() {
		_renderer->UpdateModel(model);
		if (typeOfShape == GL_TRIANGLES) {
			_renderer->Draw(typeOfShape, 3, _vao,_vbo,triangleVerticesCol, tamVerts, TypeShader::Colour);
			return;
		}

		_renderer->Draw(typeOfShape, 6, _vao,_vbo,quadVerticesCol, tamVerts, TypeShader::Colour);
	}
	void Shape::SetColor(float c1[3], float c2[3], float c3[3]) {
		if (typeOfShape == GL_TRIANGLES) {
			triangleVerticesCol[3] = c1[0];
			triangleVerticesCol[4] = c1[1];
			triangleVerticesCol[5] = c1[2];

			triangleVerticesCol[11] = c2[0];
			triangleVerticesCol[12] = c2[1];
			triangleVerticesCol[13] = c2[2];

			triangleVerticesCol[19] = c3[0];
			triangleVerticesCol[20] = c3[1];
			triangleVerticesCol[21] = c3[2];

			_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
			_renderer->SetAttribs(model, TypeShader::Colour);
			return;
		}

		quadVerticesCol[3] = c1[0];
		quadVerticesCol[4] = c1[1];
		quadVerticesCol[5] = c1[2];

		quadVerticesCol[11] = c2[0];
		quadVerticesCol[12] = c2[1];
		quadVerticesCol[13] = c2[2];

		quadVerticesCol[19] = c3[0];
		quadVerticesCol[20] = c3[1];
		quadVerticesCol[21] = c3[2];

		quadVerticesCol[27] = 0.0f;
		quadVerticesCol[28] = 0.0f;
		quadVerticesCol[29] = 0.0f;

		_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
		_renderer->SetQuadThings(GetVerticesTam(), GetIndexs());
		_renderer->SetAttribs(model, TypeShader::Colour);
	}
	int Shape::GetVerticesArrLenght() {
		return tamVerts / sizeof(float);
	}
	int Shape::GetVerticesTam() {
		return tamVerts;
	}
	float* Shape::GetVertices() {
		return _vb;
	}
	float Shape::GetVertexIndex(int ind) {
		return _vb[ind];
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