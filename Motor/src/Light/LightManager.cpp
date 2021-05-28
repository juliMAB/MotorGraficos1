#include "LightManager.h"
#include <iostream>
namespace Coco {

	LightManager::LightManager(Renderer* rend) {
		_lightCreateds = 0;
		for (int i = 0; i < _maxLights; i++)
			_lights[i] = NULL;

		_renderer = rend;
	}

	LightManager::~LightManager() {
		for (int i = 0; i < _maxLights; i++)
			if (_lights[i] != NULL) {
				delete _lights[i];
				_lights[i] = NULL;
			}

	}

	void LightManager::AddLight(TypeOfLight typeOfLight) {
		if (_lightCreateds >= _maxLights) {
			std::cout << "You cant create more lights than: " << _maxLights << " lights" << std::endl;
			return;
		}

		if (typeOfLight == TypeOfLight::Basic)
			_lights[_lightCreateds] = new Light(_renderer);
		else if (typeOfLight == TypeOfLight::Directional)
			_lights[_lightCreateds] = new DirectionalLight(_renderer);
		else if (typeOfLight == TypeOfLight::Point)
			_lights[_lightCreateds] = new PointLight(_renderer);
		else if (typeOfLight == TypeOfLight::Spot)
			_lights[_lightCreateds] = new SpotLight(_renderer);
		else {
			std::cout << "Error: Unexpected Type of Light" << std::endl;
			return;
		}

		_lightCreateds++;
	}

	Light* LightManager::GetLightByIndex(int index) {
		if (_lights[index] != NULL)
			return _lights[index];

		return NULL;
	}

	void LightManager::UseLights() {
		for (int i = 0; i < _maxLights; i++)
			if (_lights[i] != NULL)
				_lights[i]->UseLight();
	}
}