#include "Shape.h"
#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {

	static float triangleVerticesCol[24] = {
		0.0f, 1.0f, 0.0f,	/**/ 1.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f
	};

	static float quadVerticesCol[32] = {
		-1.0, 1.0, 1.0f, /**/ 1.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f,
		-1.0, -1.0, 1.0f, /**/ 0.0f, 1.0f, 0.0f,/**/ 0.0f, 0.0f,
		1.0, -1.0, 1.0f, /**/ 0.0f, 0.0f, 1.0f,/**/ 0.0f, 0.0f,
		1.0, 1.0, 1.0f, /**/ 0.0f, 0.0f, 0.0f,/**/ 0.0f, 0.0f
	};

	static float pyramidVerticesCol[44]{
		-1.0f, -1.0f, 0.0f, /**/ 0.0f, 0.0f, 0.0f, /**/0.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 1.0f,  /**/ 0.0f, 0.0f, 0.0f, /**/0.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f, /**/0.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,   /**/ 0.0f, 0.0f, 0.0f, /**/0.0f, 0.0f,	/**/ 0.0f, 0.0f, 0.0f
	};

	//static float cubeVerticesCol[88]{
	//	-1.0, -1.0, 1.0,/**/  1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/ 0.0f, 0.0f, 0.0f,
	//	1.0, -1.0, 1.0,	/**/  1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
	//	1.0, 1.0, 1.0,	/**/  1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
	//	-1.0, 1.0, 1.0,	/**/  1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
	//	-1.0, -1.0, -1.0,/**/ 1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
	//	1.0, -1.0, -1.0, /**/ 1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
	//	1.0, 1.0, -1.0,	 /**/ 1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f,
	//	-1.0, 1.0, -1.0, /**/ 1.0f, 1.0f, 1.0f,/**/0.0f, 0.0f, /**/	0.0f, 0.0f, 0.0f
	//};

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

	Shape::Shape(Renderer* rend) : Entity(rend) {}
	Shape::~Shape() {
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
	}
	void Shape::InitShape(TypeShape type, TypeShader t) {
		typeOfShape = type;
		typeShader = t;

		_material = NULL;
		_uniformModel = glGetUniformLocation(_renderer->GetShader(), "model");
		_uniformProjection = glGetUniformLocation(_renderer->GetShader(), "projection");
		_uniformView = glGetUniformLocation(_renderer->GetShader(), "view");

		switch (type) {
		case TypeShape::Triangle:
			_vb = triangleVerticesCol;
			tamVerts = sizeof(triangleVerticesCol);
			break;
		case TypeShape::Quad:
			_vb = quadVerticesCol;
			tamVerts = sizeof(quadVerticesCol);
			break;
		case TypeShape::Pyramid:
			_vb = pyramidVerticesCol;
			tamVerts = sizeof(pyramidVerticesCol);
			break;
		case TypeShape::Cube:
			_vb = cubeVerticesCol;
			tamVerts = sizeof(cubeVerticesCol);
			break;
		}
		CalcAverageNormals(GetIndexs(), 36, _vb, 64, 8, 5);
	}
	void Shape::CreateShape() {
		_renderer->SetBuffers(GetVerticesTam(), _vb, _vbo, _vao);
		if (typeOfShape != TypeShape::Triangle) {
			_renderer->SetIndexThings(GetVerticesTam(), GetIndexs(), _ibo);
		}
		_renderer->SetAttribs(model, TypeShader::Colour);

	}
	void Shape::DrawShape() {
		_renderer->UpdateMVP(model, _uniformModel, _uniformView, _uniformProjection);

		if (_material != NULL) 
			_renderer->UseMaterial(_material->GetAmbient(),_material->GetSpecular(), _material->GetDiffuse(), _material->GetShininess(),
				_material->GetUniformAmbient(), _material->GetUniformSpecular(), _material->GetUniformDiffuse(), _material->GetUniformShininess());
		_renderer->Draw(typeOfShape, GetIndexTam(), _vao, _vbo, _ibo, _vb, tamVerts, TypeShader::Colour);
	}
	void Shape::SetMaterial(Material* m) {
		_material = m;
	}
	Material* Shape::GetMaterial() {
		return _material;
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
			return sizeof(indexsPyramid) / sizeof(float);
			break;
		case TypeShape::Cube:
			return sizeof(indexsCube) / sizeof(float);
			break;
		default:
			return sizeof(posIndexs) / sizeof(float);
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
	void Shape::CalcAverageNormals(uint * indices, uint indiceCount, float * vertices, uint verticeCount, uint vLength, uint normalOffset) {
		for (int i = 0; i < indiceCount; i += 3) {
			unsigned int in0 = indices[i] * vLength;
			unsigned int in1 = indices[i + 1] * vLength;
			unsigned int in2 = indices[i + 2] * vLength;
			glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
			glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
			glm::vec3 normal = glm::cross(v1, v2);
			normal = glm::normalize(normal);

			in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
			vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
			vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
			vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
		}

		for (int i = 0; i < verticeCount / vLength; i++) {
			unsigned int nOffset = i * vLength + normalOffset;
			glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
			vec = glm::normalize(vec);
			vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
		}
	}
}