#ifndef GAME_H
#define GAME_H
#include "GameBase/GameBase.h"
namespace Coco {
	
	class Game : GameBase {
		Shape* _shape;
		Camera* _camera;
	public:
		Game();
		~Game();
		void Play();
		void Start() override;
		void Update(float deltaTime) override;
		void End() override;
	};

}
#endif