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
	void Animation::SetAnimationValues(int cantFrames, float timeBetweenFrames, int width, int height, float* verts) {
		_cantFrames = cantFrames;
		_timeBetweenFrames = timeBetweenFrames;
		_spriteSheetWidth = width;
		_spriteSheetHeight = height;
		_spriteVerts = verts;
		_spriteWidth = _spriteSheetWidth / _cantFrames;
		_spriteHeight = _spriteSheetHeight;

		_spriteVerts[0] = _spriteWidth  /_spriteSheetWidth;
		_spriteVerts[8] = _spriteWidth  /_spriteSheetWidth;
		_spriteVerts[16] = -_spriteWidth/_spriteSheetWidth;
		_spriteVerts[24] = -_spriteWidth/_spriteSheetWidth;
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
		_spriteVerts[6] =  (_spriteWidth * (_actualFrame+1)	)/_spriteSheetWidth;
		_spriteVerts[14] =  (_spriteWidth * (_actualFrame+1)	)/_spriteSheetWidth;
		_spriteVerts[22] = (_spriteWidth * _actualFrame		)/_spriteSheetWidth;
		_spriteVerts[30] = (_spriteWidth * _actualFrame		)/_spriteSheetWidth;
	}
}