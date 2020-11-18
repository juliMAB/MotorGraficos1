#ifndef ANIMATION_H
#define ANIMATION_H

#include "../src/Exports/Exports.h"

namespace Graficos1 {
	struct UV {
		float U1[32];
		float U2[32];
		float U3[32];
		float U4[32];

		float V1[32];
		float V2[32];
		float V3[32];
		float V4[32];
	};
	struct Anim {
		UV uv;
		int cantFrames;
	};
	class GraficosEngine_API Animation {
		Anim _animations[16];
		int _actualFrame;
		int _cantFrames;
		int _cantAnims;
		int _actualAnim;

		float _timeBetweenFrames;
		float _timer;

		int _spriteSheetWidth;
		float _spriteWidth;
		int _spriteSheetHeight;
		float _spriteHeight;

		float* _spriteVerts;
		int _rows;
		int _columns;
	public:
		Animation();
		~Animation();
		void SetAnimationValues(int columns, int rows, float framesPerSecond, int width, int height, float* verts);
		void AddFrame(int frameX, int frameY, int animation, int frame);
		void UpdateAnimation();
		void ChangeFrame();
		void ChangeAnimation(int a);
	};

}

#endif