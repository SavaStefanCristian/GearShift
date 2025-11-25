#pragma once
#include "IScoreManager.h"

class ScoreManager : public IScoreManager{
public:
	ScoreManager();
	~ScoreManager() = default;
    void update(float dt);
    void reset();
	int getScore() override;

private:
    int score;
    float accumulator;
};