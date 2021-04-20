#include "Renderer.h"
#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {

	typedef unsigned int uint;

	static uint posLocation;
	static uint colorLocation;
	static uint texLocation;

	static glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1366.0f / 768.0f, 0.1f, 1000.0f);
	static glm::mat4 view = glm::mat4(1.0f);


	static uint uniformNormalLocation;

	Renderer::Renderer() {

	}
	Renderer::~Renderer() {

	}
	int Renderer::InitGlew() {
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK) {
			std::cout << "Error in Glew Init" << std::endl;
			return 0;
		}

		return 1;
	}
	void Renderer::SetBuffers(int tam, float* verts, uint& vbo, uint& vao) {
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glBufferData(GL_ARRAY_BUFFER, tam, verts, GL_STATIC_DRAW);

	}
	void Renderer::SetIndexThings(int tam, uint* indexs, uint& ibo) {
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, tam, indexs, GL_STATIC_DRAW);
	}

	void Renderer::InitShaders() {
		CompileShaders();
	}

	void Renderer::StopShaders() {
		glDeleteProgram(_shader);
	}
	void Renderer::SetAttribs(uint location, int size, int stride, int offset) {
		glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
		glEnableVertexAttribArray(location);
	}
	void Renderer::Draw(TypeShape shape, int verts, uint vao, uint vbo, uint ibo, float* vertexs, float tamVertexs, TypeShader t) {
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ARRAY_BUFFER, tamVertexs, vertexs, GL_STATIC_DRAW);

		uint useTextureLoc = glGetUniformLocation(GetShader(), "useTexture");
		glUseProgram(GetShader());
		if (t == TypeShader::Colour) 
			glUniform1i(useTextureLoc, false);
		else 
			glUniform1i(useTextureLoc, true);
		
		glEnable(GL_DEPTH_TEST);

		if (shape == TypeShape::Triangle)
			glDrawArrays(GL_TRIANGLES, 0, verts);
		else
			glDrawElements(GL_TRIANGLES, verts, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glUseProgram(0);
	}

	void Renderer::UseLight(glm::vec3 colour, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position,
		uint uniformColour, uint uniformAmbient, uint uniformDiffuse, uint uniformSpecular, uint uniformPosition, uint uniformUsingLight) {
		glUseProgram(GetShader());
		glUniform3f(uniformColour, colour.x, colour.y, colour.z);
		glUniform3f(uniformAmbient, ambient.x, ambient.y, ambient.z);
		glUniform3f(uniformDiffuse, diffuse.x, diffuse.y, diffuse.z);
		glUniform3f(uniformSpecular, specular.x, specular.y, specular.z);
		glUniform1i(uniformUsingLight, true);
		glUniform3f(uniformPosition, position.x, position.y, position.z);
		glUseProgram(0);
	}
	void Renderer::StopLight(uint uniformUsingLight) {
		glUseProgram(GetShader());
		glUniform1i(uniformUsingLight, true);
		glUseProgram(0);
	}
	void Renderer::UseMaterial(glm::vec3 amb, glm::vec3 spec, glm::vec3 diff, float shine,
		uint uniformAmbient, uint uniformSpecular, uint uniformDiffuse, uint uniformShininess) {

		glUseProgram(GetShader());
		glUniform3f(uniformAmbient, amb.x, amb.y, amb.z);
		glUniform3f(uniformSpecular, spec.x, spec.y, spec.z);
		glUniform3f(uniformDiffuse, diff.x, diff.y, diff.z);
		glUniform1f(uniformShininess, shine*128.0f);

		glUseProgram(0);
	}
	void Renderer::UseCamera(glm::vec3 cameraPos, uint uniformCameraPos) {
		glUseProgram(GetShader());
		glUniform3f(uniformCameraPos, cameraPos.x, cameraPos.y, cameraPos.z);
		glUseProgram(0);
	}
	void Renderer::UpdateMVP(glm::mat4 model, uint uniformModel, uint uniformView, uint uniformProjection) {
		glUseProgram(GetShader());
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUseProgram(0);
	}

	uint Renderer::GetShader() {
		return _shader;
	}

	void Renderer::AddShader(uint program, const char* shaderCode, uint type) {
		uint theShader = glCreateShader(type);

		const char* code[1];
		code[0] = shaderCode;

		int codeLength[1];
		codeLength[0] = strlen(shaderCode);

		glShaderSource(theShader, 1, code, codeLength);

		glCompileShader(theShader);

		int result = 0;
		char eLog[1024] = { 0 };

		glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);

		if (!result) {
			glGetProgramInfoLog(theShader, sizeof(eLog), NULL, eLog);
			std::cout << "Error compiling the " << type << " program: " << eLog << std::endl;
			return;
		}
		glAttachShader(program, theShader);
	}

	void Renderer::CompileShaders() {
		_shader = glCreateProgram();
		if (!_shader) {
			std::cout << "Error creating the shader program!" << std::endl;
			return;
		}

		AddShader(_shader, vShader, GL_VERTEX_SHADER);
		AddShader(_shader, fShader, GL_FRAGMENT_SHADER);

		int result = 0;
		char eLog[1024] = { 0 };

		glLinkProgram(_shader);

		glGetProgramiv(_shader, GL_LINK_STATUS, &result);

		if (!result) {
			glGetProgramInfoLog(_shader, sizeof(eLog), NULL, eLog);
			std::cout << "Error linking program: " << eLog << std::endl;
			return;
		}

		glValidateProgram(_shader);
		glGetProgramiv(_shader, GL_VALIDATE_STATUS, &result);
		if (!result) {
			glGetProgramInfoLog(_shader, sizeof(eLog), NULL, eLog);
			std::cout << "Error validating program: " << eLog << std::endl;
			return;
		}
	}
	void Renderer::SetProjection(glm::mat4 p) {
		projection = p;
	}
	void Renderer::SetView(glm::mat4 v) {
		view = v;
	}

	glm::mat4 Renderer::GetView() {
		return view;
	}
}