#ifndef SPRITE_H
#define SPRITE_H

#include "../src/Exports/Exports.h"
#include "../src/Entity2D/Entity2D.h"
#include "../src/TextureImporter/TextureImporter.h"
#include "../src/Animation/Animation.h"

namespace Graficos1 {
	typedef unsigned int uint;
	class GraficosEngine_API Sprite : public Entity2D {
		TextureImporter _textureImp;
		int _width;
		int _height;
		int _channels;
		unsigned char* _data;
		uint _texture;
		Animation* _animation;

		float* _vb;
		uint _vbo;
		uint _vao;
	public:
		Sprite(Renderer* rend);
		Sprite(Renderer* rend, Material* mat);
		~Sprite();
		void LoadTexture(const char* path, bool transparent);
		void DrawTexture();
		int GetWidth();
		int GetHeight();
		int GetChannels();
		void BlendSprite();
	};
		

}

#endif