#include "pch.h"
#include "Renderer.h"
#include <iostream>

namespace Graficos1 {

	typedef unsigned int uint;
	static uint VAO;
	static uint VBO;
	static uint shader;
	
	// Vertex Shader
	static const char* vShader = "						\n\
#version 330										\n\
layout(location = 0) in vec3 pos;					\n\
layout(location = 1) in vec3 colorrrr;				\n\
out vec4 vColor;									\n\
void main(){										\n\
	gl_Position = vec4(0.9f * pos, 1.0f);			\n\
	vColor = vec4(colorrrr, 1.0f);					\n\
}";
	//Fragment Shader
	static const char* fShader = "						\n\
#version 330										\n\
in vec4 vColor;										\n\
out vec4 colour;									\n\
void main(){										\n\
	colour = vColor;								\n\
}";

	static void CreateTriangle() {
		float vertices[] = {
			-1.0f, -1.0f, 0.0f,	  1.0f,0.0f,0.0f,
			1.0f, -1.0f, 0.0f,	  0.0f,0.0f,0.0f,
			0.0f, 1.0f, 0.0f,	  0.0f,0.0f,1.0f
		};

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

		//Crea e inicializa un lugar para almacenar la data del buffer object
		//par: target (GL_ARRAY_BUFFER) - tamaño en total (9*sizeof(float) - la data en si (vertices) - el uso (GL_STATIC_DRAW PARA DIBUJAR)
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//glGetAttribLocation busca la location del vertex shader
		//par: el shader - el nombre a buscar
		unsigned int posLocation = glGetAttribLocation(shader, "pos");
		//Define un array de data de los Vertex Attribute
		//par: indice - cantidad de vertices por punto - tipo de dato (float) - normalizar el coso (NULL) - Especificar si tenes datos de posiciones y colores en la data - offset desde el primer componente (normalmente 0) 
		glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
		//Esto habilita o deshabilita el array de vertex attributes
		//par: El indice del array del vertex attribute para habilitar o deshabilitar
		glEnableVertexAttribArray(posLocation);

		unsigned int colorLocation = glGetAttribLocation(shader, "colorrrr");
		glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(colorLocation);

		//Aca bindeamos un array vacio
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	static void AddShader(uint program, const char* shaderCode, GLenum type) {
		//Crea un shader object
		//par: el tipo de shader a crear (frag o vert)
		uint theShader = glCreateShader(type);

		const char* code[1];
		code[0] = shaderCode;

		int codeLength[1];
		codeLength[0] = strlen(shaderCode);

		//Reemplaza el codigo fuente en el objeto shader
		//par: el shader - la cantidad de elementos a modificar (1) - el codigo - el tamaño del codigo 
		glShaderSource(theShader, 1, code, codeLength);

		//Compila el shader
		//par: el shader
		glCompileShader(theShader);

		int result = 0;
		char eLog[1024] = { 0 };
		//Retorna un paremtro desde un objeto program
		//par: el program - el parametro a retornar -  donde retornar el parametro
		glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);

		if (!result) {
			//Si no podes compilar el shader
			//Esta funcion retorna el info log del programa
			//par: el programa - el tamaño maximo para guardarlo - el tamaño del string retornado (NULL) - donde guardar la info retornada 
			glGetProgramInfoLog(theShader, sizeof(eLog), NULL, eLog);
			std::cout << "Error compiling the " << type << " program: " << eLog << std::endl;
			return;
		}

		//Une el shader object con el program object
		//par: El program - el shader
		glAttachShader(program, theShader);

	}
	static void CompileShaders() {
		//Crea un object program
		//retorna un uint, 
		shader = glCreateProgram();
		if (!shader) {
			std::cout << "Error creating the shader program!" << std::endl;
			return;
		}

		//añadimos el fragment y vertex shader al programa
		AddShader(shader, vShader, GL_VERTEX_SHADER);
		AddShader(shader, fShader, GL_FRAGMENT_SHADER);

		int result = 0;
		char eLog[1024] = { 0 };

		//Linkeamos el objecto program
		//par: el objeto program
		glLinkProgram(shader);

		//Retorna un paremtro desde un objeto program
		//par: el program - el parametro a retornar -  donde retornar el parametro
		glGetProgramiv(shader, GL_LINK_STATUS, &result);

		if (!result) {
			//Si no podes linkear el programa
			//Esta funcion retorna el info log del programa
			//par: el programa - el tamaño maximo para guardarlo - el tamaño del string retornado (NULL) - donde guardar la info retornada 
			glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
			std::cout << "Error linking program: " << eLog << std::endl;
			return;
		}

		//Valida el programa:
		//par: el prog
		glValidateProgram(shader);
		glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
		if (!result) {
			//Si no podes validar el programa
			glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
			std::cout << "Error validating program: " << eLog << std::endl;
			return;
		}
	}

	Renderer::Renderer() {
	
	}
	Renderer::~Renderer() {

	}
	int Renderer::InitGlew() {
		//Permitir extensiones modernas;
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK) {
			std::cout << "Error in Glew Init" << std::endl;
			return 0;
		}

		return 1;
	}

	void Renderer::InitShaders() {
		CompileShaders();
		CreateTriangle();
	}

	void Renderer::StopShaders() {
		glDeleteProgram(shader);
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}

	void Renderer::Draw(){
		//Mete el program object como parte del renderizado
		//par: el program
		glUseProgram(shader);

		//Bindea un VAO
		//par: el VAO
		glBindVertexArray(VAO);

		//Renderiza una primitiva de cualquier array de datos
		//par: el tipo de primitiva a renderizar - el primer indice habilitado para usar - la cantidad de indices a renderizar

		glDrawArrays(GL_TRIANGLES, 0, 3);

		//Esto desbindea el anterior VAO
		//par: 0 o NULL
		glBindVertexArray(0);

		//Esto desasigna el shader
		//par: 0 o NULL
		glUseProgram(0);
	}
}