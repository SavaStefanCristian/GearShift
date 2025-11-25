#pragma once
class IFuelManager
{
public:
    virtual void update(float dt) = 0;
    virtual void reset() = 0;
    virtual bool isFinished() const = 0;
    virtual float getCurrentTime() const = 0;
    virtual float getMaxTime() const = 0;
};

