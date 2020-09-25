#include "pch.h"
#include "Shape.h"
#include <iostream>

namespace Graficos1 {
	float triangleVertices[] = {
		 0.0f,  1.0f, 0.0f,	/**/ 1.0f, 0.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,	/**/ 1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,	/**/ 1.0f, 0.0f, 1.0f
	};

	float quadVertices[] = {
		/* 0 */	-0.5, 0.5, 0.0f, /**/ 1.0f, 0.0f, 0.0f,
		/* 1 */	-0.5,-0.5, 0.0f, /**/ 0.0f, 1.0f, 0.0f,
		/* 2 */	 0.5,-0.5, 0.0f, /**/ 0.0f, 0.0f, 1.0f,
		/* 3 */	 0.5, 0.5, 0.0f, /**/ 0.0f, 0.0f, 0.0f
	};

	unsigned int posIndexs[] = {
		0, 1, 2,
		2, 3, 0
	};

	typedef unsigned int uint;
	static uint VAO;
	static uint VBO;

	GLenum typeOfShape;

	Shape::Shape() : Entity2D() { }
	Shape::Shape(Renderer* rend, Material* mat) : Entity2D(rend, mat) {	}
	Shape::~Shape() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
	void Shape::InitShape(GLenum type) {
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

		std::cout << (typeOfShape == GL_TRIANGLES) << std::endl;
		if (typeOfShape == GL_QUADS) {
			unsigned int ibo;
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexTam(), GetIndexs(), GL_STATIC_DRAW);
		}

		//glGetAttribLocation busca la location del vertex shader
		//par: el shader - el nombre a buscar

		std::cout << _renderer->GetShader() << std::endl;
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

		//Aca bindeamos un array vacio
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}


	void Shape::DrawShape() {
		if (typeOfShape == GL_TRIANGLES) {
			_renderer->Draw(typeOfShape, 3, VAO);
			return;
		}

		_renderer->Draw(typeOfShape, 6, VAO);
	}

	void Shape::SetColor(float r, float g, float b) {
		if (typeOfShape == GL_TRIANGLES) {
			triangleVertices[3] = r;
			triangleVertices[4] = g;
			triangleVertices[5] = b;

			triangleVertices[9] = r;
			triangleVertices[10] = g;
			triangleVertices[11] = b;

			triangleVertices[15] = r;
			triangleVertices[16] = g;
			triangleVertices[17] = b;

			return;
		}

		quadVertices[3] = r;
		quadVertices[4] = g;
		quadVertices[5] = b;

		quadVertices[9] = r;
		quadVertices[10] = g;
		quadVertices[11] = b;

		quadVertices[15] = r;
		quadVertices[16] = g;
		quadVertices[17] = b;

		quadVertices[21] = r;
		quadVertices[22] = g;
		quadVertices[23] = b;
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