#pragma once
#include "SpriteManager.h"
#include "IFuelManager.h"

class FuelRenderer : public SpriteManager
{
public:
    FuelRenderer(int x, int y, int w, int h, SDL_Renderer* renderer);
    void render(std::shared_ptr<IFuelManager> manager);
    ~FuelRenderer();


private:
    SDL_Renderer* renderer;
    SDL_Rect barRect;

    SDL_Color bgColor;
    SDL_Color fillColor;

    int squareSize;
    int spacing;
    SDL_Rect spriteSquare;

    const char* fuelSpritePath = "assets/images/FuelCanister.png";
    SDL_Texture* fuelTexture = nullptr;
};

