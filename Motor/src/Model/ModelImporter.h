#ifndef MODELIMPORTER_H
#define MODELIMPORTER_H

#include "../Exports/Exports.h"

#include <vector>
#include <string>

#include "ASSIMP_N/include/assimp/Importer.hpp"
#include "ASSIMP_N/include/assimp/scene.h"
#include "ASSIMP_N/include/assimp/postprocess.h"

#include "../Renderer/Renderer.h"
#include "../TextureImporter/TextureImporter.h"
#include "ModelTexture.h"
#include "Mesh.h"

namespace Coco {

	class GraficosEngine_API ModelImporter {
		std::vector<Mesh*> _meshList;
		std::vector<uint> _meshesToTex;
		std::vector<ModelTexture*> _texturesList;
		Renderer* _renderer;
	public:
		ModelImporter(Renderer* renderer);
		~ModelImporter();
		void LoadModel(std::string fileName, std::string texturesLocation);
		void LoadModel(std::string fileName, std::string texturesLocation, std::string nameTexture);
		void LoadNode(aiNode* node, const aiScene* scene);
		void LoadMesh(aiMesh* mesh, const aiScene* scene);
		void LoadMaterials(const aiScene* scene, std::string texturesLocation);
		void LoadMaterials(const aiScene* scene, std::string textureLocation, std::string nameTexture);
		std::vector<Mesh*> GetMeshList();
		std::vector<uint> GetMeshToTex();
		std::vector<ModelTexture*> GetTexturesList();
	};

}

#endif