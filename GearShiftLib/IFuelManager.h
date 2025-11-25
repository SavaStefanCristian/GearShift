#pragma once
class IFuelManager
{
public:
    virtual bool isFinished() const = 0;
    virtual float getCurrentTime() const = 0;
    virtual float getMaxTime() const = 0;
};

