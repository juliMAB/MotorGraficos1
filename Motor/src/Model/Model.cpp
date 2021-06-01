#include "Model.h"
#include <iostream>
#include "glew.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

namespace Coco {

	Model::Model(Renderer* rend) : Entity(rend) {
		_material = NULL;
		_material = new Material(rend);
		_material->SetAmbient(glm::vec3( 1,1,1));
		_material->SetDiffuse(glm::vec3( 0.5,0.5,0.5));
		_material->SetSpecular(glm::vec3(0.5f,0.5f,0.5f));
		_material->SetShininess(0.25f);
		_usingOriginalMaterial = true;
	}
	Model::~Model() {
		if (_usingOriginalMaterial && _material != NULL) {
			delete _material;
			_material = NULL;
		}
		ClearModel();
	}

	void Model::LoadModel(const std::string& fileName, const std::string& texturesLocation, TextureLoadType tlt) {
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(fileName, aiProcess_Triangulate);

		if (!scene) {
			std::cout << "Model: " << fileName << " cant be loaded pa: " << importer.GetErrorString() << std::endl;
			return;
		}
		LoadNode(scene->mRootNode, scene);
		LoadMaterials(scene, texturesLocation, tlt);
	}
	void Model::DrawModel() {
		for (int i = 0; i < _meshList.size(); i++) {
			uint materialIndex = _meshesToTex[i];

			if (materialIndex < _texturesList.size() && _texturesList[materialIndex]) {
				_texturesList[materialIndex]->UseTexture();
			}
			if (_material != NULL) 
				_renderer->UseMaterial(_material->GetAmbient(), _material->GetSpecular(), _material->GetDiffuse(), _material->GetShininess(),
					_material->GetUniformAmbient(), _material->GetUniformSpecular(), _material->GetUniformDiffuse(), _material->GetUniformShininess());

			
			_meshList[i]->RenderMesh();

			if (materialIndex < _texturesList.size() && _texturesList[materialIndex])
				_texturesList[materialIndex]->StopTexture();
		}
	}
	void Model::SetMaterial(Material* mat) 	{
		if (_material != NULL) {
			delete _material;
			_material = NULL;
			_usingOriginalMaterial = false;
		}
		_material = mat;
	}
	void Model::ClearModel() {

		for (int i = 0; i < _meshList.size(); i++)
			if (_meshList[i]) {
				delete _meshList[i];
				_meshList[i] = NULL;
			}

		for (int i = 0; i < _texturesList.size(); i++)
			if (_texturesList[i]) {
				delete _texturesList[i];
				_texturesList[i] = NULL;
			}

	}
	void Model::LoadNode(aiNode* node, const aiScene* scene) {
		for (size_t i = 0; i < node->mNumMeshes; i++) {
			LoadMesh(scene->mMeshes[node->mMeshes[i]], scene);
		}

		for (size_t i = 0; i < node->mNumChildren; i++) {
			LoadNode(node->mChildren[i], scene);
		}
	}

	void Model::LoadMesh(aiMesh* mesh, const aiScene* scene) {
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
	void Model::LoadMaterials(const aiScene* scene, const std::string& texturesLocation, TextureLoadType tlt) {
		_texturesList.resize(scene->mNumMaterials);

		for (int i = 0; i < scene->mNumMaterials; i++) {
			aiMaterial* material = scene->mMaterials[i];
			_texturesList[i] = NULL;

			if (tlt == TextureLoadType::Automatic) {

				if (material->GetTextureCount(aiTextureType_DIFFUSE)) {
					aiString path;
					if (material->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS) {
						int idx = std::string(path.data).rfind("\\");
						std::string fileName = std::string(path.data).substr(idx + 1);
						std::string texPath = texturesLocation + fileName;
						_texturesList[i] = new ModelTexture(texPath.c_str());

						if (!_texturesList[i]->LoadTexture()) {
							std::cout << "Failed to load texture at: " << texPath << std::endl;
							delete _texturesList[i];
							_texturesList[i] = NULL;
						}
						else
							std::cout << "Texture loaded: " << fileName << std::endl;
					}
				}
				
			}
			else {
				std::cout << "Loading texture at: " << texturesLocation << std::endl;
				_texturesList[i] = new ModelTexture(texturesLocation.c_str());
				if (!_texturesList[i]->LoadTexture()) {
					std::cout << "Failed to load texture at: " << texturesLocation << std::endl;
					delete _texturesList[i];
					_texturesList[i] = NULL;
				}
				else
					std::cout << "Texture loaded: " << texturesLocation << std::endl;

			}

			if (!_texturesList[i]) {
				_texturesList[i] = new ModelTexture("res/textures/plain.png");
				_texturesList[i]->LoadTexture();
			}

		}
	}

	void Model::SetScaleModel(float x, float y, float z) {
		SetScale(x, y, z);
		for (int i = 0; i < _meshList.size(); i++)
			_meshList[i]->SetScale(x, y, z);
	}
	void Model::SetRotationXModel(float x) {
		SetRotX(x);
		for (int i = 0; i < _meshList.size(); i++)
			_meshList[i]->SetRotX(x);
	}
	void Model::SetRotationYModel(float y) {
		SetRotY(y);
		for (int i = 0; i < _meshList.size(); i++)
			_meshList[i]->SetRotY(y);
	}
	void Model::SetRotationZModel(float z) {
		SetRotZ(z);
		for (int i = 0; i < _meshList.size(); i++)
			_meshList[i]->SetRotZ(z);
	}
	void Model::SetRotationModel(float x, float y, float z) {
		SetRotX(x);
		SetRotY(y);
		SetRotZ(z);
		for (int i = 0; i < _meshList.size(); i++) {
			_meshList[i]->SetRotX(x);
			_meshList[i]->SetRotY(y);
			_meshList[i]->SetRotZ(z);
		}
	}
	void Model::SetPositionModel(float x, float y, float z) {
		SetPos(x, y, z);
		for (int i = 0; i < _meshList.size(); i++)
			_meshList[i]->SetPos(x, y, z);
	}

}