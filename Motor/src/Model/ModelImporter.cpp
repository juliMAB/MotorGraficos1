#include "ModelImporter.h"
#include <iostream>
#include "Mesh.h"

namespace Coco {

	ModelImporter::ModelImporter(Renderer* renderer) {
		_renderer = renderer;
	}

	ModelImporter::~ModelImporter() {
	}

	void ModelImporter::LoadModel(std::string fileName, std::string texturesLocation) {
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

		if (!scene) {
			std::cout << "Model: " << fileName << " cant be loaded pa: " << importer.GetErrorString() << std::endl;
			return;
		}
	
		_meshList.clear();
		_meshesToTex.clear();
		_texturesList.clear();

		LoadNode(scene->mRootNode, scene);
		LoadMaterials(scene, texturesLocation);
	}
	void ModelImporter::LoadModel(std::string fileName, std::string texturesLocation, std::string nameTexture) {
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

		if (!scene) {
			std::cout << "Model: " << fileName << " cant be loaded pa: " << importer.GetErrorString() << std::endl;
			return;
		}

		_meshList.clear();
		_meshesToTex.clear();
		_texturesList.clear();

		LoadNode(scene->mRootNode, scene);
		LoadMaterials(scene, texturesLocation, nameTexture);
	}
	void ModelImporter::LoadNode(aiNode* node, const aiScene* scene) {
		for (size_t i = 0; i < node->mNumMeshes; i++) {
			LoadMesh(scene->mMeshes[node->mMeshes[i]], scene);
		}

		for (size_t i = 0; i < node->mNumChildren; i++) {
			LoadNode(node->mChildren[i], scene);
		}
	}

	void ModelImporter::LoadMesh(aiMesh* mesh, const aiScene* scene){
		std::vector<float> vertices;
		std::vector<uint> indices;

		for (size_t i = 0; i < mesh->mNumVertices; i++) {
			vertices.insert(vertices.end(), { mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z });
			if (mesh->mTextureCoords[0]) {
				vertices.insert(vertices.end(), { mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y });
			}
			else {
				vertices.insert(vertices.end(), { 0.0f, 0.0f });
			}
			vertices.insert(vertices.end(), { -mesh->mNormals[i].x, -mesh->mNormals[i].y, -mesh->mNormals[i].z });
		}

		for (size_t i = 0; i < mesh->mNumFaces; i++) {
			aiFace face = mesh->mFaces[i];
			for (size_t j = 0; j < face.mNumIndices; j++) {
				indices.push_back(face.mIndices[j]);
			}
		}

		Mesh* newMesh = new Mesh(_renderer);
		newMesh->CreateMesh(&vertices[0], &indices[0], vertices.size(), indices.size());
		_meshList.push_back(newMesh);
		_meshesToTex.push_back(mesh->mMaterialIndex);
	}
	void ModelImporter::LoadMaterials(const aiScene* scene, std::string texturesLocation) {
		_texturesList.resize(scene->mNumMaterials);

		for (int i = 0; i < scene->mNumMaterials; i++) {
			aiMaterial* material = scene->mMaterials[i];
			_texturesList[i] = NULL;

			if (material->GetTextureCount(aiTextureType_DIFFUSE)) {
				aiString path;
				if (material->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS) {
					int idx = std::string(path.data).rfind("\\");
					std::string fileName = std::string(path.data).substr(idx + 1);
					//std::string texPath = texturesLocation + fileName;
					_texturesList[i] = new ModelTexture(texturesLocation, fileName);

					if (!_texturesList[i]->LoadTexture()) {
						std::cout << "Failed to load texture at: " << texturesLocation << fileName << std::endl;
						delete _texturesList[i];
						_texturesList[i] = NULL;
					}
					else
						std::cout << "Texture loaded: " << fileName << std::endl;
				}
			}


			if (!_texturesList[i]) {
				_texturesList[i] = new ModelTexture("res/textures/", "plain.png");
				_texturesList[i]->LoadTexture();
			}

		}
	}

	void ModelImporter::LoadMaterials(const aiScene* scene, std::string textureLocation, std::string nameTexture) {
		_texturesList.resize(scene->mNumMaterials);

		for (int i = 0; i < scene->mNumMaterials; i++) {
			aiMaterial* material = scene->mMaterials[i];
			_texturesList[i] = NULL;

			std::cout << "Loading texture at: " << textureLocation << nameTexture << std::endl;
			_texturesList[i] = new ModelTexture(textureLocation, nameTexture);
			if (!_texturesList[i]->LoadTexture()) {
				std::cout << "Failed to load texture at: " << textureLocation << nameTexture << std::endl;
				delete _texturesList[i];
				_texturesList[i] = NULL;
			}
			else
				std::cout << "Texture loaded: " << textureLocation << nameTexture << std::endl;

			if (!_texturesList[i]) {
				_texturesList[i] = new ModelTexture("res/textures/", "plain.png");
				_texturesList[i]->LoadTexture();
			}

		}
	}

	std::vector<Mesh*> ModelImporter::GetMeshList() {
		return _meshList;
	}
	std::vector<uint> ModelImporter::GetMeshToTex() {
		return _meshesToTex;
	}
	std::vector<ModelTexture*> ModelImporter::GetTexturesList() {
		return _texturesList;
	}

}