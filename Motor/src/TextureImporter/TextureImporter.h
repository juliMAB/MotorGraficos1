#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include "../src/Exports/Exports.h"

namespace Coco {
	typedef unsigned int uint;

	class GraficosEngine_API TextureImporter {
	public:
		TextureImporter();
		~TextureImporter();
		void LoadTexture(const char* path, unsigned char* data ,uint& texture, int width, int height, int channels, bool transparent);
	};
		

}

#endif