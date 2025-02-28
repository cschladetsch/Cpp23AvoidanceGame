#include "render.h"

Render::Render(SDL_Renderer* renderer, int width, int height)
    : renderer(renderer), screenWidth(width), screenHeight(height) {
    perlinTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, screenWidth, screenHeight);
}

Render::~Render() {
    SDL_DestroyTexture(perlinTexture);
}

void Render::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Render::renderBackground(const std::vector<Uint8>& pixels) {
    Uint32* texturePixels;
    int pitch;

    SDL_LockTexture(perlinTexture, nullptr, (void**)&texturePixels, &pitch);

    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            int grayValue = pixels[y * screenWidth + x];
            texturePixels[y * screenWidth + x] = SDL_MapRGBA(SDL_GetWindowSurface(SDL_RenderGetWindow(renderer))->format, grayValue, grayValue, grayValue, 255);
        }
    }

    SDL_UnlockTexture(perlinTexture);
    SDL_RenderCopy(renderer, perlinTexture, nullptr, nullptr);
}

void Render::renderPlayer(const Player& player) {
    SDL_Rect playerRect = player.getRect();
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &playerRect);
}

void Render::renderEnemies(const std::vector<Enemy>& enemies) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (const auto& enemy : enemies) {
        SDL_Rect enemyRect = enemy.getRect();
        SDL_RenderFillRect(renderer, &enemyRect);
    }
}

void Render::renderHealthBar(int energy) {
    SDL_Rect healthBar = {0, 0, static_cast<int>(screenWidth * (energy / 200.0f)), HEALTH_BAR_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &healthBar);
}

void Render::present() {
    SDL_RenderPresent(renderer);
    SDL_Delay(1); // reduced delay
}
