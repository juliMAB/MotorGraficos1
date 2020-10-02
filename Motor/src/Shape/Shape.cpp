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
		//Genera los VAO
		//par: cantidad de VAO a generar - & la posicion en memoria donde guardarlos
		glGenVertexArrays(1, &VAO);
		//Bindea un VAO
		//par: el VAO
		glBindVertexArray(VAO);

		//Genera los VBO
		//par: cantidad de VBO - &La posicion en memoria para guardarlo
		glGenBuffers(1, &VBO);
		//Bindea el VBO
		//par: a donde queres bindear el VBO - el VBO
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		//SetColor(0.0f, 0.0f, 1.0f);

		//Crea e inicializa un lugar para almacenar la data del buffer object
		//par: target (GL_ARRAY_BUFFER) - tamaño en total (9*sizeof(float) - la data en si (vertices) - el uso (GL_STATIC_DRAW PARA DIBUJAR)
		glBufferData(GL_ARRAY_BUFFER, GetVerticesTam(), GetVertices(), GL_STATIC_DRAW);

		if (typeOfShape == GL_QUADS) {
			unsigned int ibo;
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexTam(), GetIndexs(), GL_STATIC_DRAW);
		}

		//glGetAttribLocation busca la location del vertex shader
		//par: el shader - el nombre a buscar
		unsigned int posLocation = glGetAttribLocation(_renderer->GetShader(), "pos");
		//Define un array de data de los Vertex Attribute
		//par: indice - cantidad de vertices por punto - tipo de dato (float) - normalizar el coso (NULL) - Especificar si tenes datos de posiciones y colores en la data - offset desde el primer componente (normalmente 0) 
		glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
		//Esto habilita o deshabilita el array de vertex attributes
		//par: El indice del array del vertex attribute para habilitar o deshabilitar
		glEnableVertexAttribArray(posLocation);

		unsigned int colorLocation = glGetAttribLocation(_renderer->GetShader(), "colorrrr");
		glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(colorLocation);

		unsigned int uniformModel = glGetUniformLocation(_renderer->GetShader(), "model");
		glUseProgram(_renderer->GetShader());
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

		//Aca bindeamos un array vacio
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
		
		//quadVertices[3] = color1.r;
		//quadVertices[4] = color1.g;
		//quadVertices[5] = color1.b;
		//
		//quadVertices[9] = color1.r;
		//quadVertices[10] = color1.g;
		//quadVertices[11] = color1.b;
		//
		//quadVertices[15] = color1.r;
		//quadVertices[16] = color1.g;
		//quadVertices[17] = color1.b;
		//
		//quadVertices[21] = color1.r;
		//quadVertices[22] = color1.g;
		//quadVertices[23] = color1.b;
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