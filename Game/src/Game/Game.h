#ifndef GAME_H
#define GAME_H
#include "GameBase/GameBase.h"

namespace Graficos1 {
	
	class Game : GameBase {
		Shape* _shape;
		Sprite* _shapeSprite;
	public:
		Game();
		~Game();
		void Play();
		void Start() override;
		void Update() override;
		void End() override;
	};

}
#endif