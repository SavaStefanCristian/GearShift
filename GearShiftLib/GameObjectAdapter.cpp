#include "GameObjectAdapter.h"
#include "GameObject.h"

float GameObjectAdapter::getX() const
{
    return this->object->getTransform().getX();
}

float GameObjectAdapter::getY() const
{
    return this->object->getTransform().getY();
}

int GameObjectAdapter::getWidth() const
{
    return this->object->getWidth();
}

int GameObjectAdapter::getHeight() const
{
    return this->object->getHeight();
}

bool GameObjectAdapter::isActive() const
{
    return this->object->isActive();
}

GameObjectAdapter::GameObjectAdapter(std::shared_ptr<class GameObject> obj) : object(obj)
{

}
