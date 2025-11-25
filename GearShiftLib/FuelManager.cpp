#include "FuelManager.h"



FuelManager::FuelManager(float duration)
    : maxTime(duration), currentTime(duration)
{
}

void FuelManager::update(float dt) {
    if (currentTime > 0) {
        currentTime -= dt;
        if (currentTime < 0) currentTime = 0;
    }
}

bool FuelManager::isFinished() const {
    return currentTime <= 0;
}

float FuelManager::getCurrentTime() const {
    return currentTime;
}

float FuelManager::getMaxTime() const {
    return maxTime;
}

void FuelManager::reset() {
    currentTime = maxTime;
}


