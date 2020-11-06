#include "Animation.h"
#include <time.h>
#include <iostream>

namespace Graficos1 {
	
	Animation::Animation() {
		_cantFrames = 0;
		_actualFrame = 0;
		_timeBetweenFrames = 0;
		_timer = 0;
		_spriteSheetWidth = 0;
		_spriteWidth = 0;
		_spriteSheetHeight = 0;
		_spriteHeight = 0;
		_spriteVerts = 0;
	}
	Animation::~Animation() {
		
	}
	void Animation::SetAnimationValues(int cantFramesAnim, int cantFramesImg, float timeBetweenFrames, int width, int height, int rows, int actualRow, float* verts) {
		_rows = rows;
		_actualRow = _rows - actualRow;

		_cantFramesImg = cantFramesImg;
		_cantFrames = cantFramesAnim;
		_timeBetweenFrames = timeBetweenFrames;
		_spriteSheetWidth = width;
		_spriteSheetHeight = height;
		_spriteVerts = verts;
		_spriteWidth = _spriteSheetWidth / _cantFramesImg;
		_spriteHeight = _spriteSheetHeight / rows;

		_spriteVerts[0] = _spriteWidth  /_spriteSheetWidth;
		_spriteVerts[8] = _spriteWidth  /_spriteSheetWidth;
		_spriteVerts[16] = -_spriteWidth/_spriteSheetWidth;
		_spriteVerts[24] = -_spriteWidth/_spriteSheetWidth;

		_spriteVerts[1] =   _spriteHeight / _spriteSheetHeight;
		_spriteVerts[9] =   -_spriteHeight / _spriteSheetHeight;
		_spriteVerts[17] = -_spriteHeight / _spriteSheetHeight;
		_spriteVerts[25] = _spriteHeight / _spriteSheetHeight;
		
		_spriteVerts[7] =  (_spriteHeight / _spriteSheetHeight) * _actualRow;
		_spriteVerts[15] = (_spriteHeight / _spriteSheetHeight) * (_actualRow - 1);
		_spriteVerts[23] = (_spriteHeight / _spriteSheetHeight) * (_actualRow - 1);
		_spriteVerts[31] = (_spriteHeight / _spriteSheetHeight) * _actualRow;
	}
	
	double oldT = clock();
	void Animation::UpdateAnimation() {
		double t = clock();
		float dt = (float)((t - oldT) / 1000.0f);
		oldT = t;
		_timer += dt;
		if (_timer >= _timeBetweenFrames) {
			_actualFrame++;
			if (_actualFrame >= _cantFrames)
				_actualFrame = 0;

			ChangeAnimation();
			_timer = dt;
		}
	}
	void Animation::ChangeAnimation() {
		_spriteVerts[6] = (_spriteWidth * (_actualFrame + 1)) / _spriteSheetWidth;
		_spriteVerts[14] = (_spriteWidth * (_actualFrame + 1)) / _spriteSheetWidth;
		_spriteVerts[22] = (_spriteWidth * _actualFrame) / _spriteSheetWidth;
		_spriteVerts[30] = (_spriteWidth * _actualFrame) / _spriteSheetWidth;
	}
}