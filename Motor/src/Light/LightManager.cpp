#include "LightManager.h"
#include <iostream>
namespace Coco {

	LightManager::LightManager(Renderer* rend) {
		_baseLight = NULL;
		for (int i = 0; i < _maxLightsOfType; i++) {
			_directionalLights[i] = NULL;
			_spotLights[i] = NULL;
			_pointLights[i] = NULL;
		}

		_baseLightCreated = false;
		_pointLightsCreateds = 0;
		_spotLightsCreateds = 0;
		_directionalLightsCreateds = 0;

		_renderer = rend;
	}

	LightManager::~LightManager() {
		if (_baseLight != NULL)
			delete _baseLight;

		for (int i = 0; i < _maxLightsOfType; i++) {
			if (_directionalLights[i] != NULL)
				delete _directionalLights[i];
			if (_spotLights[i] != NULL)
				delete _spotLights[i];
			if (_pointLights[i] != NULL)
				delete _pointLights[i];
		}

	}

	void LightManager::AddLight(TypeOfLight typeOfLight) {

		if (typeOfLight == TypeOfLight::Basic) {
			if (_baseLightCreated) {
				std::cout << "Max basic lights created" << std::endl;
				return;
			}

			_baseLightCreated = true;
			_baseLight = new Light(_renderer, 0);
		}
		else if (typeOfLight == TypeOfLight::Directional) {
			if (_directionalLightsCreateds >= _maxLightsOfType) {
				std::cout << "Max directional lights created" << std::endl;
				return;
			}

			_directionalLights[_directionalLightsCreateds] = new DirectionalLight(_renderer, _directionalLightsCreateds);
			_directionalLightsCreateds++;
		}
		else if (typeOfLight == TypeOfLight::Point) {
			if (_pointLightsCreateds >= _maxLightsOfType) {
				std::cout << "Max point lights created" << std::endl;
				return;
			}

			_pointLights[_pointLightsCreateds] = new PointLight(_renderer, _pointLightsCreateds);
			_pointLightsCreateds++;
		}
		else if (typeOfLight == TypeOfLight::Spot) {
			if (_spotLightsCreateds >= _maxLightsOfType) {
				std::cout << "Max spot lights created" << std::endl;
				return;
			}

			_spotLights[_spotLightsCreateds] = new SpotLight(_renderer, _spotLightsCreateds);
			_spotLightsCreateds++;
		}
		else
			std::cout << "Error: Unexpected Type of Light" << std::endl;

	}

	Light* LightManager::GetBaseLight() {
		if (_baseLight != NULL)
			return _baseLight;

		return NULL;
	}

	DirectionalLight* LightManager::GetDirectionalLightByIndex(int index) {
		if (_directionalLights[index] != NULL)
			return _directionalLights[index];

		return NULL;
	}

	SpotLight* LightManager::GetSpotLightByIndex(int index) {
		if (_spotLights[index] != NULL)
			return _spotLights[index];

		return NULL;
	}

	PointLight* LightManager::GetPointLightByIndex(int index) {
		if (_pointLights[index] != NULL)
			return _pointLights[index];

		return NULL;
	}

	void LightManager::UseLights() {
		_renderer->SetLights(false);

		if (_baseLight != NULL)
			if (_baseLight->GetUsingLight())
				_baseLight->UseLight();

		for (int i = 0; i < _maxLightsOfType; i++) {

			if (_directionalLights[i] != NULL)
				if (_directionalLights[i]->GetUsingLight())
					_directionalLights[i]->UseLight();

			if (_spotLights[i] != NULL)
				if (_spotLights[i]->GetUsingLight())
					_spotLights[i]->UseLight();

			if (_pointLights[i] != NULL)
				if (_pointLights[i]->GetUsingLight())
					_pointLights[i]->UseLight();

		}
	}
}