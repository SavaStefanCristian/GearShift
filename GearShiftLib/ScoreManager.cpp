#include "ScoreManager.h"
#include <SDL2/SDL_ttf.h>
#include <string>

ScoreManager::ScoreManager(SDL_Renderer* rend)
    : renderer(rend), score(0), accumulator(0.0f), texture(nullptr)
{
    color = { 255, 255, 255, 255 };

    if (TTF_WasInit() == 0) {
        if (TTF_Init() == -1) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_Init failed: %s", TTF_GetError());
        }
    }
    font = TTF_OpenFont("assets/fonts/VipnagorgiallaBd.otf", 24);
    if (!font) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font: %s", TTF_GetError());
    }

    updateTexture();
}

ScoreManager::~ScoreManager() {
    if (texture) SDL_DestroyTexture(texture);
    if (font) TTF_CloseFont(font);
}

void ScoreManager::update(float dt) {
    accumulator += dt;
    while (accumulator >= 1.0f) {
        score += 10;
        accumulator -= 1.0f;
        updateTexture();
    }
}

void ScoreManager::updateTexture() {
    if (!font || !renderer) return;

    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    std::string text = "Score: " + std::to_string(score);
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    if (!surface) return;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect.w = surface->w;
    rect.h = surface->h;
    rect.x = 1920 - rect.w - 20;    rect.y = 20;

    SDL_FreeSurface(surface);
}

void ScoreManager::render() {
    if (texture && renderer) {
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }
}

void ScoreManager::reset() {
    score = 0;
    accumulator = 0;
    updateTexture();
}
