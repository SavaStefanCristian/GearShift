#include "ScoreManager.h"
#include <string>

ScoreManager::ScoreManager()
    : score(0), accumulator(0.0f)
{
}

void ScoreManager::update(float dt) {
    accumulator += dt;
    while (accumulator >= 1.0f) {
        score += 10;
        accumulator -= 1.0f;
    }
}

void ScoreManager::reset() {
    score = 0;
    accumulator = 0;
}

int ScoreManager::getScore() { return score; }
