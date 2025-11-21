#pragma once
#include "IFabric.h"
#include <memory>

class Fabric : public IFabric{
public:
    static std::shared_ptr<IFabric> create(int width, int height, float spacing);
    void update(float dt) override;
    void applyForce(float mx, float my, float radius, float strength) override;
    void reset() override;

    const std::vector<Pt>& getPts() const override { return pts; }
    int getW() const override { return w; }
    int getH() const override { return h; }
    Pt& getPt(int x, int y) override;

private:
    Fabric(int width, int height, float spacing);
    std::vector<Pt> pts;
    int w, h;
    float space;
    float damp;
    float stiff;

};