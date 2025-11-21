#pragma once
#include <vector>

struct Pt {
	float x, y;
	float ox, oy;
	float fx, fy;
	bool pinned;

	Pt(float _x, float _y) : x(_x), y(_y), ox(_x), oy(_y),
		fx(0), fy(0), pinned(false) {
	}
};

class IFabric {
public:
	virtual void update(float dt) = 0;
	virtual void applyForce(float mx, float my, float radius, float strength) = 0;
	virtual void reset() = 0;

	virtual const std::vector<Pt>& getPts() const = 0;
	virtual int getW() const = 0;
	virtual int getH() const = 0;
	virtual Pt& getPt(int x, int y) = 0;
};