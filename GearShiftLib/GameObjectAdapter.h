#pragma once
#include "IGameObject.h"
#include <memory>


class GameObjectAdapter : public IGameObject {
public:
	float getX() const override;
	float getY() const override;
	int getWidth() const override;
	int getHeight() const override;
	bool isActive() const override;
	GameObjectAdapter(std::shared_ptr<class GameObject> obj);


private:
	std::shared_ptr<class GameObject> object;



};