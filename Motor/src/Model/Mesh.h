#ifndef MESH_H
#define MESH_H

#include "../Exports/Exports.h"
#include "../Entity/Entity.h"

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Mesh : public Entity {
		uint VAO, VBO, IBO;
		int indexCount;
	public:
		Mesh(Renderer* rend);
		~Mesh();

		void CreateMesh(float* vertices, uint* indices, uint numOfVertices, uint numOfIndices);
		void RenderMesh();
		void ClearMesh();
	};

}

#endif