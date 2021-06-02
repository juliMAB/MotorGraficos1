#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include "../src/Exports/Exports.h"
#include <string>

namespace Coco {
	typedef unsigned int uint;

	class GraficosEngine_API TextureImporter {
		static bool NameContainsOnlyASCII(std::string textureName);
	public:
		static bool LoadTexture(const std::string& path, const std::string& textureName, unsigned char* data, uint& texture, int width, int height, int channels);
	};
		

}

#endif