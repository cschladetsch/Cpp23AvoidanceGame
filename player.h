#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <vector>
#include <chrono> // Include chrono for time points
#include "enemy.h"

struct Player {
    Player(float x, float y);
    void handleInput(SDL_Event& e);
    void update(const std::vector<Uint8>& perlinPixels, int screenWidth);
    bool checkCollision(const Enemy& enemy) const;
    void takeDamage();
    int getEnergy() const;
    int getMaxEnergy() const;
    SDL_Rect getRect() const;
    void reset(float x, float y);

private:
    Vec2 position;
    int energy;
    int maxEnergy;
    SDL_Rect rect;
    std::chrono::high_resolution_clock::time_point lastEnergyUpdate; // Declare lastEnergyUpdate
};

#endif
