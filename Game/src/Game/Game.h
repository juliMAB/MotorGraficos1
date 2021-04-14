#ifndef GAME_H
#define GAME_H
#include "GameBase/GameBase.h"
namespace Graficos1 {
	
	class Game : GameBase {
		Shape* _shape;
		Shape* _shape2;
		Camera* _camera;
		Light* _light;
		Material* _goldMaterial;
		Material* _obsidianMaterial;
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