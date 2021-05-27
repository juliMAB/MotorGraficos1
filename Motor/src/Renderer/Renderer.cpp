#include "Renderer.h"
#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {

	static glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1366.0f / 768.0f, 0.1f, 1000.0f);
	static glm::mat4 view = glm::mat4(1.0f);

	Renderer::Renderer() {
		_shader = new Shader();
	}
	Renderer::~Renderer() {
		if (_shader != NULL)
			delete _shader;
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
	void Renderer::StopShaders() {
		if (_shader != NULL)
			_shader->ClearShader();
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

	void Renderer::SetLights(bool value) {
		glUseProgram(GetShader());
		glUniform1i(glGetUniformLocation(GetShader(), "useLight"), value);
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
		if (_shader != NULL)
			return _shader->GetShader();
	}

	void Renderer::CreateShader(const char* vertexCode, const char* fragmentCode) {
		if (_shader != NULL) 
			_shader->CreateFromLocation(vertexCode, fragmentCode);
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