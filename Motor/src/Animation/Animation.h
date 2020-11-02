#ifndef ANIMATION_H
#define ANIMATION_H

namespace Graficos1 {

	class Animation {
		int _cantFrames;
		int _actualFrame;
		float _timeBetweenFrames;
		float _timer;
		int _spriteSheetWidth;
		float _spriteWidth;
		int _spriteSheetHeight;
		float _spriteHeight;
		float* _spriteVerts;
	public:
		Animation();
		~Animation();
		void SetAnimationValues(int cantFrames, float timeBetweenFrames, int width, int height, float* verts);
		void UpdateAnimation();
		void ChangeAnimation();
	};

}

#endif