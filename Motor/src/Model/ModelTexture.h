#ifndef MODELTEXTURE_H
#define MODELTEXTURE_H

#include "../Exports/Exports.h"

#include "../TextureImporter/TextureImporter.h"

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API ModelTexture {
		uint _textureID;
		int _width;
		int _height;
		int _bitDepth;
		int _channels;
		unsigned char* _texData;
		const char* _path;
	public:
		ModelTexture(const char* path);
		~ModelTexture();
		bool LoadTexture();
		bool LoadTexture(const char* path);
		void UseTexture();
		void StopTexture();
		void ClearTexture();

	};

}

#endif