#include "Mesh.h"
#include "glew.h"

namespace Coco {

	Mesh::Mesh(Renderer* rend) : Entity(rend) {
		VAO = 0;
		VBO = 0;
		IBO = 0;
		indexCount = 0;

		_uniformModel = glGetUniformLocation(_renderer->GetShader(), "model");
		_uniformProjection = glGetUniformLocation(_renderer->GetShader(), "projection");
		_uniformView = glGetUniformLocation(_renderer->GetShader(), "view");
		_positionLocation = glGetAttribLocation(_renderer->GetShader(), "pos");
		_texLocation = glGetAttribLocation(_renderer->GetShader(), "tex");
		_normalLocation = glGetAttribLocation(_renderer->GetShader(), "norm");
		_renderer->SetAttribs(_positionLocation, 3, 8, 0);
		_renderer->SetAttribs(_normalLocation, 3, 8, 3);
		_renderer->SetAttribs(_texLocation, 2, 8, 6);
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
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numOfIndices, indices, GL_STATIC_DRAW);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, 0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 3));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 5));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	void Mesh::RenderMesh() {
		_renderer->UpdateMVP(model, _uniformModel, _uniformView, _uniformProjection);
		_renderer->DrawMesh(indexCount, VAO, VBO, IBO);
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
}