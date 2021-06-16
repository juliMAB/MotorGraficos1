#ifndef GAME_H
#define GAME_H
#include "GameBase/GameBase.h"
namespace Coco {
	
	class Game : GameBase {
		Shape* _shape;
		Shape* _shape2;
		Camera* _camera;
		Material* _goldMaterial;
		Material* _obsidianMaterial;
		Model* _model1;
		Model* _model2;
		Model* _model3;
		Model* _model4;
		Model* _model5;
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