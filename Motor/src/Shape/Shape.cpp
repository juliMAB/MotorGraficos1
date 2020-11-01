#include "Shape.h"
#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {

	float triangleVerticesCol[] = {
		 0.0f,  0.5f, 0.0f,	/**/ 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f
	};

	float triangleVerticesTex[] = {
		0.0f, 0.5f, 0.0f,	/**/ 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,	/**/ 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,	/**/ 0.0f, 0.0f
	};

	float quadVerticesCol[] = {
		/* 0 */	-0.5,  0.5, 0.0f, /**/ 1.0f, 0.0f, 0.0f,
		/* 1 */	-0.5, -0.5, 0.0f, /**/ 0.0f, 1.0f, 0.0f,
		/* 2 */	 0.5, -0.5, 0.0f, /**/ 0.0f, 0.0f, 1.0f,
		/* 3 */	 0.5,  0.5, 0.0f, /**/ 0.0f, 0.0f, 0.0f
	};

	float quadVerticesTex[] = {
		 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,   // top right
		 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,   // bottom right
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,   // bottom left
		-1.0f,  1.0f, 0.0f, 0.0f, 1.0f    // top left 
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
			if (t == TypeShader::Colour) {
				_vb = triangleVerticesCol;
				tamVerts = sizeof(triangleVerticesCol);
			}
			else {
				_vb = triangleVerticesTex;
				tamVerts = sizeof(triangleVerticesTex);
			}
			return;
		}

		if (t == TypeShader::Colour) {
			_vb = quadVerticesCol;
			tamVerts = sizeof(quadVerticesCol);
		}
		else {
			_vb = quadVerticesTex;
			tamVerts = sizeof(quadVerticesTex);
		}
	}
	void Shape::CreateShape() {
		_renderer->SetTypeOfShader(typeShader);
		_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
		if (typeOfShape == GL_QUADS)
			_renderer->SetQuadThings(GetVerticesTam(), GetIndexs());
		_renderer->SetAttribs(model);
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
			triangleVerticesCol[3] = c1[0];
			triangleVerticesCol[4] = c1[1];
			triangleVerticesCol[5] = c1[2];

			triangleVerticesCol[9] = c2[0];
			triangleVerticesCol[10] = c2[1];
			triangleVerticesCol[11] = c2[2];

			triangleVerticesCol[15] = c3[0];
			triangleVerticesCol[16] = c3[1];
			triangleVerticesCol[17] = c3[2];

			_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
			if (typeOfShape == GL_QUADS)
				_renderer->SetQuadThings(GetVerticesTam(), GetIndexs());
			_renderer->SetAttribs(model);
			return;
		}

		quadVerticesCol[3] = c1[0];
		quadVerticesCol[4] = c1[1];
		quadVerticesCol[5] = c1[2];

		quadVerticesCol[9] = c2[0];
		quadVerticesCol[10] = c2[1];
		quadVerticesCol[11] = c2[2];
					
		quadVerticesCol[15] = c3[0];
		quadVerticesCol[16] = c3[1];
		quadVerticesCol[17] = c3[2];
					
		quadVerticesCol[21] = 0.0f;
		quadVerticesCol[22] = 0.0f;
		quadVerticesCol[23] = 0.0f;

		_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
		if (typeOfShape == GL_QUADS)
			_renderer->SetQuadThings(GetVerticesTam(), GetIndexs());
		_renderer->SetAttribs(model);
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