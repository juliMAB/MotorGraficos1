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