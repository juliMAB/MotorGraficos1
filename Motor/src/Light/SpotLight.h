#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "PointLight.h"

namespace Coco {

    class GraficosEngine_API SpotLight : public PointLight {

        float _cutOff;
        uint _uniformCutOff;
    protected:

        void SetUniforms() override;
    public:
        SpotLight(Renderer* rend, int index);
        SpotLight(Renderer* rend, float constant, float linear, float quadratic, float cutOff, int index);
        ~SpotLight();
        void UseLight() override;
        void SetCutOff(float c);
        float GetCutOff();
    };

}

#endif