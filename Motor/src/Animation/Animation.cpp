#include "Animation.h"
#include <time.h>
#include <iostream>
#include "../src/Timer/Timer.h"

namespace Graficos1 {
	static int animsCreated = 0;
	Animation::Animation() {
		_actualFrame = 0;
		_cantFrames = 0;
		_cantAnims = 0;
		_actualAnim = 3;
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

	void Animation::SetAnimationValues(int columns, int rows, float framesPerSecond, int width, int height, float* verts) {
		if (_cantAnims < 16) {
			_timeBetweenFrames = 1.0f / framesPerSecond;
			_rows = rows;
			_columns = columns;

			_spriteSheetWidth = width;
			_spriteSheetHeight = height;
			_spriteVerts = verts;

			_spriteWidth = _spriteSheetWidth / columns;
			_spriteHeight = _spriteSheetHeight / rows;
			_animations[_cantAnims].cantFrames = 0;
			_cantAnims++;
		}
		else {
			std::cout << "Max Animations Reached" << std::endl;
		}
	}

	void Animation::AddFrame(int frameX, int frameY, int animation, int frame) {
		if (animation < 0 || animation > 16) {
			std::cout << "Animation Value is out of range" << std::endl;
			return;
		}

		if (_cantFrames<32) {
			_animations[animation].uv.U1[frame] = (_spriteWidth * (frameX + 1)) / _spriteSheetWidth;
			_animations[animation].uv.U2[frame] = (_spriteWidth * (frameX + 1)) / _spriteSheetWidth;
			_animations[animation].uv.U3[frame] = (_spriteWidth * frameX) / _spriteSheetWidth;
			_animations[animation].uv.U4[frame] = (_spriteWidth * frameX) / _spriteSheetWidth;


			_animations[animation].uv.V1[frame] = (_spriteHeight / _spriteSheetHeight) *   frameY;
			_animations[animation].uv.V2[frame] = (_spriteHeight / _spriteSheetHeight) * (frameY - 1);
			_animations[animation].uv.V3[frame] = (_spriteHeight / _spriteSheetHeight) * (frameY - 1);
			_animations[animation].uv.V4[frame] = (_spriteHeight / _spriteSheetHeight) *  frameY;
			_animations[animation].cantFrames++;
		}
		else {
			std::cout << "Max Frames in Animation Reached" << std::endl;
		}
	}

	void Animation::UpdateAnimation() {
		float t = 0;
		Timer::DeltaTime(t);
		_timer += t;

		if (_timer >= _timeBetweenFrames) {
			while (_timer > _timeBetweenFrames) {
				_timer -= _timeBetweenFrames;
				_actualFrame++;
				if (_actualFrame >= _animations[_actualAnim].cantFrames)
					_actualFrame = 0;
			}
			ChangeFrame();
			_timer = t;
		}
	}

	void Animation::ChangeFrame() {
		_spriteVerts[6] = _animations[_actualAnim].uv.U1[_actualFrame];
		_spriteVerts[14] = _animations[_actualAnim].uv.U2[_actualFrame];
		_spriteVerts[22] = _animations[_actualAnim].uv.U3[_actualFrame];
		_spriteVerts[30] = _animations[_actualAnim].uv.U4[_actualFrame];

		_spriteVerts[7] = _animations[_actualAnim].uv.V1[_actualFrame];
		_spriteVerts[15] = _animations[_actualAnim].uv.V2[_actualFrame];
		_spriteVerts[23] = _animations[_actualAnim].uv.V3[_actualFrame];
		_spriteVerts[31] = _animations[_actualAnim].uv.V4[_actualFrame];
	}

	void Animation::ChangeAnimation(int a) {
		_actualAnim = a;
		ChangeFrame();
	}

}