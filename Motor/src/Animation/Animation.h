#ifndef ANIMATION_H
#define ANIMATION_H

#include "../src/Exports/Exports.h"

namespace Graficos1 {

	class GraficosEngine_API Animation {
		int _cantFrames;
		int _cantFramesImg;
		int _actualFrame;
		float _timeBetweenFrames;
		float _timer;
		int _spriteSheetWidth;
		float _spriteWidth;
		int _spriteSheetHeight;
		float _spriteHeight;
		float* _spriteVerts;
		int _rows;
		int _actualRow;
	public:
		Animation();
		~Animation();
		void SetAnimationValues(int cantFramesAnim, int cantFramesImg, float timeBetweenFrames, int width, int height, int rows, int actualRow, float* verts);
		void UpdateAnimation();
		void ChangeAnimation();
	};

}

#endif