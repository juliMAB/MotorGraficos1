#include "Mesh.h"
#include "glew.h"

#include "ASSIMP_N/include/assimp/scene.h"
#include <iostream>

namespace Coco {

	Mesh::Mesh(Renderer* rend) : Entity(rend) {
		VAO = 0;
		VBO = 0;
		IBO = 0;
		indexCount = 0;

		_node = NULL;

		_uniformModel = glGetUniformLocation(_renderer->GetShader(), "model");
		_uniformProjection = glGetUniformLocation(_renderer->GetShader(), "projection");
		_uniformView = glGetUniformLocation(_renderer->GetShader(), "view");

		_positionLocation = glGetAttribLocation(_renderer->GetShader(), "pos");
		_texLocation = glGetAttribLocation(_renderer->GetShader(), "tex");
		_normalLocation = glGetAttribLocation(_renderer->GetShader(), "norm");
	}

	Mesh::~Mesh() {
		ClearMesh();
	}

	void Mesh::CreateMesh(float* vertices, uint* indices, uint numOfVertices, uint numOfIndices) {
		indexCount = numOfIndices;

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * numOfIndices, indices, GL_STATIC_DRAW);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numOfVertices, vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(_positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
		glEnableVertexAttribArray(_positionLocation);

		glVertexAttribPointer(_texLocation, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 3));
		glEnableVertexAttribArray(_texLocation);

		glVertexAttribPointer(_normalLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 5));
		glEnableVertexAttribArray(_normalLocation);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	void Mesh::RenderMesh() {
		_renderer->UpdateMVP(matrix.model, _uniformModel, _uniformView, _uniformProjection);
		_renderer->DrawMesh(indexCount, VAO, VBO, IBO, _affectedByLight);
	}

	void Mesh::ClearMesh() {
		if (IBO != 0) {
			glDeleteBuffers(1, &IBO);
			IBO = 0;
		}

		if (VBO != 0) {
			glDeleteBuffers(1, &VBO);
			VBO = 0;
		}

		if (VAO != 0) {
			glDeleteVertexArrays(1, &VAO);
			VAO = 0;
		}

		indexCount = 0;
	}

	void Mesh::SetPos(float x, float y, float z) {
		transform.position = { x, y, z };
		matrix.translate = glm::translate(glm::mat4(1.0f), transform.position);

		for (int i = 0; i < _meshSons.size(); i++)
			_meshSons[i]->SetPos(x,y,z);

		UpdateMatrixData();
	}
	void Mesh::SetPos(glm::vec3 pos) {
		SetPos(pos.x, pos.y, pos.z);
	}
	void Mesh::SetRotX(float x) {
		transform.rotation.x = x;
		matrix.rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(x), glm::vec3(1.0f, 0.0f, 0.0f));

		for (int i = 0; i < _meshSons.size(); i++)
			_meshSons[i]->SetRotX(x);

		UpdateMatrixData();
		UpdateTransformsData();
	}
	void Mesh::SetRotY(float y) {
		transform.rotation.y = y;
		matrix.rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(y), glm::vec3(0.0f, 1.0f, 0.0f));

		for (int i = 0; i < _meshSons.size(); i++)
			_meshSons[i]->SetRotY(y);

		UpdateMatrixData();
		UpdateTransformsData();
	}
	void Mesh::SetRotZ(float z) {
		transform.rotation.z = z;
		matrix.rotationZ = glm::rotate(glm::mat4(1.0f), glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));

		for (int i = 0; i < _meshSons.size(); i++)
			_meshSons[i]->SetRotZ(z);

		UpdateMatrixData();
		UpdateTransformsData();
	}
	void Mesh::SetRotations(float x, float y, float z) {
		transform.rotation = glm::vec3(x, y, z);
		matrix.rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(x), glm::vec3(1.0f, 0.0f, 0.0f));
		matrix.rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(y), glm::vec3(0.0f, 1.0f, 0.0f));
		matrix.rotationZ = glm::rotate(glm::mat4(1.0f), glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));

		for (int i = 0; i < _meshSons.size(); i++)
			_meshSons[i]->SetRotations(x, y, z);

		UpdateMatrixData();
		UpdateTransformsData();
	}
	void Mesh::SetRotations(glm::vec3 rotation) {
		SetRotations(rotation.x, rotation.y, rotation.z);
	}
	void Mesh::SetScale(float x, float y, float z) {
		transform.scale = { x, y, z };
		matrix.scale = glm::scale(glm::mat4(1.0f), transform.scale);

		for (int i = 0; i < _meshSons.size(); i++)
			_meshSons[i]->SetScale(x, y, z);

		UpdateMatrixData();
	}

	void Mesh::SetLocalPos(float x, float y, float z) {

	}

	void Mesh::SetLocalPos(glm::vec3 pos) {

	}

	void Mesh::SetLocalRotX(float x) {

	}

	void Mesh::SetLocalRotY(float y) {

	}

	void Mesh::SetLocalRotZ(float z) {

	}

	void Mesh::SetLocalRotations(float x, float y, float z) {

	}

	void Mesh::SetLocalRotations(glm::vec3 rotation) {

	}

	void Mesh::SetLocalScale(float x, float y, float z) {

	}

	void Mesh::SetName(std::string value) {
		_name = value;
	}

	void Mesh::AddMeshSon(Mesh* mesh) {
		_meshSons.push_back(mesh);
	}

	void Mesh::SetNode(aiNode* node) {
		_node = node;
	}

	void Mesh::SetIsParent(bool value) {
		_isParent = value;
	}
	bool Mesh::GetIsParent() {
		return _isParent;
	}
	aiNode* Mesh::GetNode() {
		return _node;
	}
	std::string Mesh::GetName() {
		return _name;
	}
	std::vector<Mesh*> Mesh::GetMeshesSons() {
		return _meshSons;
	}
}