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
	static uint VAO;
	static uint VBO;
	static uint uniformModel;

	uint typeOfShape;

	Shape::Shape() : Entity2D() { }
	Shape::Shape(Renderer* rend, Material* mat) : Entity2D(rend, mat) {	}
	Shape::~Shape() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
	void Shape::InitShape(uint type) {
		typeOfShape = type;
	}
	void Shape::CreateShape() {
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, GetVerticesTam(), GetVertices(), GL_STATIC_DRAW);

		if (typeOfShape == GL_QUADS) {
			unsigned int ibo;
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexTam(), GetIndexs(), GL_STATIC_DRAW);
		}

		unsigned int posLocation = glGetAttribLocation(_renderer->GetShader(), "pos");
		glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
		glEnableVertexAttribArray(posLocation);

		unsigned int colorLocation = glGetAttribLocation(_renderer->GetShader(), "colorrrr");
		glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(colorLocation);

		unsigned int uniformModel = glGetUniformLocation(_renderer->GetShader(), "model");
		glUseProgram(_renderer->GetShader());
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	void Shape::DrawShape() {
		unsigned int uniformModel = glGetUniformLocation(_renderer->GetShader(), "model");
		glUseProgram(_renderer->GetShader());
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

		if (typeOfShape == GL_TRIANGLES) {
			_renderer->Draw(typeOfShape, 3, VAO);
			return;
		}

		_renderer->Draw(typeOfShape, 6, VAO);
	}
	void Shape::SetColor(float c1[3], float c2[3], float c3[3]){
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

			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);

			glBufferData(GL_ARRAY_BUFFER, GetVerticesTam(), GetVertices(), GL_STATIC_DRAW);

			unsigned int posLocation = glGetAttribLocation(_renderer->GetShader(), "pos");
			glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
			glEnableVertexAttribArray(posLocation);

			unsigned int colorLocation = glGetAttribLocation(_renderer->GetShader(), "colorrrr");
			glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(colorLocation);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

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

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, GetVerticesTam(), GetVertices(), GL_STATIC_DRAW);

			unsigned int ibo;
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexTam(), GetIndexs(), GL_STATIC_DRAW);
		
		unsigned int posLocation = glGetAttribLocation(_renderer->GetShader(), "pos");
		glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
		glEnableVertexAttribArray(posLocation);

		unsigned int colorLocation = glGetAttribLocation(_renderer->GetShader(), "colorrrr");
		glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(colorLocation);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
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