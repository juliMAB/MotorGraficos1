#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include "../Exports/Exports.h"
#include "../Renderer/Renderer.h"

#include "Light.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

namespace Coco {

	class GraficosEngine_API LightManager {
		int _lightCreateds;
		static const int _maxLights = 6;
		Light* _lights[_maxLights];

		Renderer* _renderer;
	public:
		LightManager(Renderer* rend);
		~LightManager();

		void AddLight(TypeOfLight typeOfLight);
		Light* GetLightByIndex(int index);

		void UseLights();
	};

}

#endif