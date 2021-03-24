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

	float pyramidVerticesCol[32]{
		-1.0f, -1.0f, 0.0f, /**/ 1.0f, 0.0f, 0.0f, /**/0.0f, 0.0f,
		0.0f, -1.0f, 1.0f,  /**/ 0.0f, 1.0f, 0.0f, /**/0.0f, 0.0f,
		1.0f, -1.0f, 0.0f,	/**/ 0.0f, 0.0f, 1.0f, /**/0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,   /**/ 0.0f, 0.0f, 0.0f, /**/0.0f, 0.0f
	};

	float cubeVerticesCol[64]{
		-1.0, -1.0, 1.0,/**/  1.0f, 0.0f, 0.0f,/**/0.0f, 0.0f,
		1.0, -1.0, 1.0,	/**/  0.0f, 1.0f, 0.0f,/**/0.0f, 0.0f,
		1.0, 1.0, 1.0,	/**/  0.0f, 0.0f, 1.0f,/**/0.0f, 0.0f,
		-1.0, 1.0, 1.0,	/**/  1.0f, 0.0f, 0.0f,/**/0.0f, 0.0f,
		-1.0, -1.0, -1.0,/**/ 0.0f, 1.0f, 0.0f,/**/0.0f, 0.0f,
		1.0, -1.0, -1.0, /**/ 0.0f, 0.0f, 1.0f,/**/0.0f, 0.0f,
		1.0, 1.0, -1.0,	 /**/ 1.0f, 0.0f, 0.0f,/**/0.0f, 0.0f,
		-1.0, 1.0, -1.0, /**/ 0.0f, 1.0f, 0.0f,/**/0.0f, 0.0f
	};

	uint indexsPyramid[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	uint indexsCube[] = {
		0, 1, 2,
		2, 3, 0,
		1, 5, 6,
		6, 2, 1,
		7, 6, 5,
		5, 4, 7,
		4, 0, 3,
		3, 7, 4,
		4, 5, 1,
		1, 0, 4,
		3, 2, 6,
		6, 7, 3
	};

	unsigned int posIndexs[] = {
		0, 1, 2,
		2, 3, 0
	};

	typedef unsigned int uint;

	TypeShape typeOfShape;
	TypeShader typeShader;
	uint tamVerts;

	Shape::Shape() : Entity2D() { }
	Shape::Shape(Renderer* rend, Material* mat) : Entity2D(rend, mat) {	}
	Shape::~Shape() {
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
	}
	void Shape::InitShape(TypeShape type, TypeShader t) {
		typeOfShape = type;
		typeShader = t;

		switch (type) {
		case TypeShape::Triangle:
			_vb = triangleVerticesCol;
			tamVerts = sizeof(triangleVerticesCol);
			break;
		case TypeShape::Quad:
			_vb = quadVerticesCol;
			tamVerts = sizeof(quadVerticesCol); break;
		case TypeShape::Pyramid:
			_vb = pyramidVerticesCol;
			tamVerts = sizeof(pyramidVerticesCol);
			break;
		case TypeShape::Cube:
			_vb = cubeVerticesCol;
			tamVerts = sizeof(cubeVerticesCol);
			break;
		}
	}
	void Shape::CreateShape() {
		_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
		if (typeOfShape != TypeShape::Triangle) {
			_renderer->SetIndexThings(GetVerticesTam(), GetIndexs(), _ibo);
		}
		_renderer->SetAttribs(model, TypeShader::Colour);

	}
	void Shape::DrawShape() {
		_renderer->UpdateModel(model);

		switch (typeOfShape) {
		case TypeShape::Triangle:
			_renderer->Draw(typeOfShape, 3, _vao, _vbo, _ibo, triangleVerticesCol, tamVerts, TypeShader::Colour);
			break;
		case TypeShape::Quad:
			_renderer->Draw(typeOfShape, 6, _vao, _vbo, _ibo, quadVerticesCol, tamVerts, TypeShader::Colour);
			break;
		case TypeShape::Pyramid:
			_renderer->Draw(typeOfShape, 12, _vao, _vbo, _ibo, pyramidVerticesCol, tamVerts, TypeShader::Colour);
			break;
		case TypeShape::Cube:
			_renderer->Draw(typeOfShape, 36, _vao, _vbo, _ibo, cubeVerticesCol, tamVerts, TypeShader::Colour);
			break;
		}
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
		_renderer->SetIndexThings(GetVerticesTam(), GetIndexs(), _ibo);
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
		switch (typeOfShape) {
		case TypeShape::Pyramid:
			return sizeof(indexsPyramid);
			break;
		case TypeShape::Cube:
			return sizeof(indexsCube);
			break;
		default:
			return sizeof(posIndexs);
			break;
		}
	}
	unsigned int* Shape::GetIndexs() {
		switch (typeOfShape) {
		case TypeShape::Pyramid:
			return indexsPyramid;
			break;
		case TypeShape::Cube:
			return indexsCube;
			break;
		default:
			return posIndexs;
			break;
		}
	}
}