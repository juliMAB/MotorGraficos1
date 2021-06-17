#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"

namespace Coco {

    class GraficosEngine_API PointLight : public Light {

    protected:
        float _constant;
        float _linear;
        float _quadratic;

        uint _uniformConstant;
        uint _uniformLinear;
        uint _uniformQuadratic;
        void SetUniforms() override;
    public:

        PointLight(Renderer* rend, int index);
        PointLight(Renderer* rend, float constant, float linear, float quadratic, int index);
        ~PointLight();
        void UseLight() override;

        void SetConstantLinearQuadratic(float c, float l, float q);
        void SetConstant(float c);
        void SetLinear(float l);
        void SetQuadratic(float q);
        float GetConstant();
        float GetLinear();
        float GetQuadratic();
    };

}

#endif