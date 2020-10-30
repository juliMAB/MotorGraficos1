#include "TextureImporter.h"

#include <iostream>

#include <glew.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#define STB_IMAGE_IMPLEMENTATION

namespace Graficos1 {

	TextureImporter::TextureImporter() {

	}
	TextureImporter::~TextureImporter() {
	}
	void TextureImporter::LoadTexture(const char* path, unsigned char* data, uint& texture, int width, int height, int channels) {

		data = stbi_load(path, &width, &height, &channels, 0);
		if (!data) {
			std::cout << "Texture not loading bruh" << std::endl;
			return;
		}

		glGenTextures(1, &texture);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
		
		stbi_image_free(data);
	}
}