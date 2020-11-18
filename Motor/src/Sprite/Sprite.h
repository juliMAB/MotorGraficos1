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
		bool _transparent;
		Animation* _animation;
		bool _settedAnimsValues;
		float texVertices[32] = {
			 1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f,	1.0f, 1.0f,   // top right
			 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f,	1.0f, 0.0f,   // bottom right
			-1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f,	0.0f, 0.0f,   // bottom left
			-1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f,	0.0f, 1.0f    // top left 
		};
		float* _vb;
		uint _vbo;
		uint _vao;
	public:
		Sprite(Renderer* rend);
		Sprite(Renderer* rend, Material* mat);
		~Sprite();
		void LoadTexture(const char* path, bool transparent);
		void StartUseAnimation();
		void SetAnimation(int columns, int rows, float framesPerSeconds);
		void AddFrameToAnimation(int frameX, int frameY, int animation, int frame);
		void DrawTexture();
		void UpdateAnimation();
		void ChangeAnimation(int anim);
		float* GetVerts();
		int GetChannels();
		void BlendSprite();
		void UnBlendSprite();
	};
		

}

#endif