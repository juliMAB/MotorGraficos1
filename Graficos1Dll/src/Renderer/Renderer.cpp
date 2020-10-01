#include "pch.h"
#include "Renderer.h"
#include <iostream>

namespace Graficos1 {

	typedef unsigned int uint;
	uint uniformModel;
	

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
		//CreateShape();
	}

	void Renderer::StopShaders() {
		glDeleteProgram(_shader);
	}

	void Renderer::Draw(GLenum shape, int verts, uint vao){
		//Mete el program object como parte del renderizado
		//par: el program
		glUseProgram(_shader);
		
		//Bindea un VAO
		//par: el VAO
		glBindVertexArray(vao);

		//Renderiza una primitiva de cualquier array de datos
		//par: el tipo de primitiva a renderizar - el primer indice habilitado para usar - la cantidad de indices a renderizar
		switch (shape) {
		case GL_QUADS:
			glDrawElements(GL_TRIANGLES, verts, GL_UNSIGNED_INT, nullptr);
			break;
		case GL_TRIANGLES:
			glDrawArrays(GL_TRIANGLES, 0, verts);
			break;
		}
		
		//Esto desbindea el anterior VAO
		//par: 0 o NULL
		glBindVertexArray(0);

		//Esto desasigna el shader
		//par: 0 o NULL
		glUseProgram(0);
	}

	uint Renderer::GetShader() {
		return _shader;
	}
	

	void Renderer::AddShader(uint program, const char* shaderCode, GLenum type) {
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

	void Renderer::CompileShaders() {
		//Crea un object program
		//retorna un uint, 
		_shader = glCreateProgram();
		if (!_shader) {
			std::cout << "Error creating the shader program!" << std::endl;
			return;
		}

		//añadimos el fragment y vertex shader al programa
		AddShader(_shader, vShader, GL_VERTEX_SHADER);
		AddShader(_shader, fShader, GL_FRAGMENT_SHADER);

		int result = 0;
		char eLog[1024] = { 0 };

		//Linkeamos el objecto program
		//par: el objeto program
		glLinkProgram(_shader);

		//Retorna un paremtro desde un objeto program
		//par: el program - el parametro a retornar -  donde retornar el parametro
		glGetProgramiv(_shader, GL_LINK_STATUS, &result);

		if (!result) {
			//Si no podes linkear el programa
			//Esta funcion retorna el info log del programa
			//par: el programa - el tamaño maximo para guardarlo - el tamaño del string retornado (NULL) - donde guardar la info retornada 
			glGetProgramInfoLog(_shader, sizeof(eLog), NULL, eLog);
			std::cout << "Error linking program: " << eLog << std::endl;
			return;
		}

		//Valida el programa:
		//par: el prog
		glValidateProgram(_shader);
		glGetProgramiv(_shader, GL_VALIDATE_STATUS, &result);
		if (!result) {
			//Si no podes validar el programa
			glGetProgramInfoLog(_shader, sizeof(eLog), NULL, eLog);
			std::cout << "Error validating program: " << eLog << std::endl;
			return;
		}
	}

}