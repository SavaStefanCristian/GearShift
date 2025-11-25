#pragma once
#include <string>
#include <unordered_map>
#include "SpriteType.h"

class SpriteMapper {
public:
	static const std::string getSpritePath(SpriteType sprite);
private:
	SpriteMapper();
	static const std::unordered_map<SpriteType, std::string> spritePathMap;
};