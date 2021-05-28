#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "Light.h"

namespace Coco {

    class GraficosEngine_API DirectionalLight : public Light {
    protected:
        void SetUniforms() override;
    public:
        DirectionalLight(Renderer* rend, int index);
        ~DirectionalLight();
        void UseLight() override;
    };

}

#endif