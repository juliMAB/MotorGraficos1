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
		bool _baseLightCreated;
		int _pointLightsCreateds;
		int  _spotLightsCreateds;
		int _directionalLightsCreateds;

		static const int _maxLightsOfType = 3;
		Light* _baseLight;
		DirectionalLight* _directionalLights[_maxLightsOfType];
		SpotLight* _spotLights[_maxLightsOfType];
		PointLight* _pointLights[_maxLightsOfType];

		Renderer* _renderer;
	public:
		LightManager(Renderer* rend);
		~LightManager();

		void AddLight(TypeOfLight typeOfLight);
		Light* GetBaseLight();
		DirectionalLight* GetDirectionalLightByIndex(int index);
		SpotLight* GetSpotLightByIndex(int index);
		PointLight* GetPointLightByIndex(int index);

		void UseLights();
	};

}

#endif