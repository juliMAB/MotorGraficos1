#ifndef MODEL_H
#define MODEL_H

#include "../Exports/Exports.h"
#include "../Entity/Entity.h"

#include "ModelImporter.h"
#include "Mesh.h"
#include "ModelTexture.h"
#include "../Material/Material.h"

namespace Coco {
	typedef unsigned int uint;

	class GraficosEngine_API Model : public Entity {
		uint textureID;
		int width, height, bitDepth;

		const char* fileLocation;

		std::vector<Mesh*> _meshList;
		std::vector<uint> _meshesToTex;
		std::vector<ModelTexture*> _texturesList;

		void LoadNode(aiNode* node, const aiScene* scene);
		void LoadMesh(aiMesh* mesh, const aiScene* scene);
		void LoadMaterials(const aiScene* scene, std::string texturesLocation);
		void LoadMaterials(const aiScene* scene, std::string textureLocation, std::string nameTexture);

		bool _usingOriginalMaterial;
		Material* _material;
	public:
		Model(Renderer* rend);
		~Model();

		void LoadModel(std::string fileName, std::string texturesLocation);
		void LoadModel(std::string fileName, std::string textureLocation, std::string nameTexture);
		void DrawModel();
		void ClearModel();

		void SetMaterial(Material* mat);

		void SetPos(float x, float y, float z)			override;
		void SetPos(glm::vec3 pos)						override;
		void SetRotX(float x)							override;
		void SetRotY(float y)							override;
		void SetRotZ(float z)							override;
		void SetRotations(float x, float y, float z)	override;
		void SetRotations(glm::vec3 rotation)			override;
		void SetScale(float x, float y, float z)		override;

	};

}

#endif