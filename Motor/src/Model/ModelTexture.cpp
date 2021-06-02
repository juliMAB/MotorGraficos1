#include "ModelTexture.h"
#include "glew.h"
#include <iostream>
namespace Coco {

	ModelTexture::ModelTexture(const std::string path, const std::string name) {
		_textureID = 0;
		_width = 0;
		_height = 0;
		_bitDepth = 0;
		_channels = 0;
		_path = path;
		_name = name;
	}
	ModelTexture::~ModelTexture() {
		ClearTexture();
	}
	bool ModelTexture::LoadTexture() {
		return TextureImporter::LoadTexture(_path, _name,_texData, _textureID, _width, _height, _channels);
	}
	bool ModelTexture::LoadTexture(const std::string path, const std::string name) {
		_path = path;
		_name = name;
		return TextureImporter::LoadTexture(_path, _name,_texData, _textureID, _width, _height, _channels);
	}
	void ModelTexture::UseTexture() {
		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _textureID);
	}

	void ModelTexture::StopTexture() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}

	void ModelTexture::ClearTexture() {
		glDeleteTextures(1, &_textureID);
		_textureID = 0;
		_width = 0;
		_height = 0;
		_bitDepth = 0;
		_path = " ";
	}

}