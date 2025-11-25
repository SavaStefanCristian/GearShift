#pragma once
#include "SpriteManager.h"
#include "IFuelManager.h"

class FuelManager : public IFuelManager{
public:
    FuelManager(float duration);

    virtual ~FuelManager() = default;

    void update(float dt) override;
    void reset() override;
    bool isFinished() const override;
    float getCurrentTime() const override;
    float getMaxTime() const override;



private:
    float maxTime;
    float currentTime;




};
