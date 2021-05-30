#include "ModelTexture.h"
#include "glew.h"
#include <iostream>
namespace Coco {

	ModelTexture::ModelTexture(const char* path) {
		_textureID = 0;
		_width = 0;
		_height = 0;
		_bitDepth = 0;
		_channels = 0;
		_path = path;
	}

	ModelTexture::~ModelTexture() {
		ClearTexture();
	}
	bool ModelTexture::LoadTexture() {
		return TextureImporter::LoadTexture(_path, _texData, _textureID, _width, _height, _channels, false);
	}
	bool ModelTexture::LoadTexture(const char* path) {
		_path = path;
		return TextureImporter::LoadTexture(_path, _texData, _textureID, _width, _height, _channels, false);
	}

	void ModelTexture::UseTexture() {
		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _textureID);
	}

	void ModelTexture::StopTexture() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
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