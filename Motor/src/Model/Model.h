#ifndef MODEL_H
#define MODEL_H

#include "../Exports/Exports.h"
#include "../Entity/Entity.h"

#include "ModelImporter.h"
#include "Mesh.h"
#include "ModelTexture.h"


namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Model : public Entity {

		uint textureID;
		int width, height, bitDepth;

		const char* fileLocation;

		std::vector<Mesh*> _meshList;
		std::vector<ModelTexture*> _texturesList;
		std::vector<uint> _meshesToTex;

		void LoadNode(aiNode* node, const aiScene* scene);
		void LoadMesh(aiMesh* mesh, const aiScene* scene);
		void LoadMaterials(const aiScene* scene, const std::string& texturesLocation);


	public:
		Model(Renderer* rend);
		~Model();

		void LoadModel(const std::string& fileName, const std::string& texturesLocation);
		void DrawModel();
		void ClearModel();

		void	 SetScaleModel(float x, float y, float z);
		void SetRotationXModel(float x);
		void SetRotationYModel(float y);
		void SetRotationZModel(float z);
		void  SetRotationModel(float x, float y, float z);
		void     SetPositionModel(float x, float y, float z);

	};

}

#endif