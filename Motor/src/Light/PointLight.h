#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"

namespace Graficos1 {

    class GraficosEngine_API PointLight : public Light {

        uint _uniformConstant;
        uint _uniformLinear;
        uint _uniformQuadratic;

        float _constant;
        float _linear;
        float _quadratic;

    protected:
        void SetUniforms() override;
    public:

        PointLight(Renderer* rend);
        PointLight(Renderer* rend, float constant, float linear, float quadratic);
        ~PointLight();
        virtual void UseLight();

        void SetConstant(float c);
        void SetLinear(float l);
        void SetQuadratic(float q);
        float GetConstant();
        float GetLinear();
        float GetQuadratic();
    };

}

#endif