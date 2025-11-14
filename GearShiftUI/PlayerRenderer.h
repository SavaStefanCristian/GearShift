#pragma once
#include <SDL2/SDL.h>
#include "IPlayer.h"
#include <memory>

class PlayerRenderer {
private:
    SDL_Color color;
    SDL_Texture* playerTexture = nullptr; 

public:
    PlayerRenderer(SDL_Renderer* renderer);
    ~PlayerRenderer();

    void render(SDL_Renderer* rend, const std::shared_ptr<IPlayer> player);

    void setColor(Uint8 r, Uint8 g, Uint8 b);

private:
    void drawTextureOverRect(SDL_Renderer* renderer, SDL_Rect rect);
};
