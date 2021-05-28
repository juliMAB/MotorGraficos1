#ifndef GAMEBASE_H
#define GAMEBASE_H

#include "../src/Exports/Exports.h"
#include "../src/Window/Window.h"
#include "../src/Renderer/Renderer.h"
#include "../src/Shape/Shape.h"
#include "../src/Sprite/Sprite.h"
#include "../src/Input/Input.h"
#include "../src/CollisionManager/CollisionManager.h"
#include "../src/Camera/Camera.h"
#include "../Light/Light.h"
#include "../Light/DirectionalLight.h"
#include "../Light/PointLight.h"
#include "../Light/SpotLight.h"

struct GLFWmonitor;

namespace Coco {

	class GraficosEngine_API GameBase {
		Window* _window;
		Renderer* _renderer;
		Input* _input;
		CollisionManager* _collisionManager;
	public:
		GameBase();
		~GameBase();

		int StartEngine(int width, int height, const char* windowName);
		void UpdateEngine();
		void EndEngine();

		Window* GetWindow();
		Renderer* GetRenderer();
		Input* GetInput();

		virtual void Start() = 0;
		virtual void Update() = 0;
		void virtual End() = 0;
	};

}

#endif