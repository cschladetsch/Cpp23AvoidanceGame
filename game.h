#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>
#include "player.h"
#include "enemy.h"
#include "perlin.h"
#include "render.h"
#include <random>
#include <chrono>

class Game {
public:
    Game(int width, int height, SDL_Renderer* renderer);
    void handleInput(SDL_Event& e);
    void update();
    void render();
    bool isGameOver() const;
    int getScore() const;
    void resetGame();

private:
    int screenWidth;
    int screenHeight;
    SDL_Renderer* renderer;
    Player player;
    std::vector<Enemy> enemies;
    std::vector<Uint8> perlinPixels;
    Render renderObj;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> disX;
    std::uniform_real_distribution<float> disY;
    std::uniform_real_distribution<float> disSpeed;
    std::chrono::high_resolution_clock::time_point lastEnemySpawn;
    float enemySpeedMultiplier = 1.0f;
    bool gameOver;
    std::chrono::high_resolution_clock::time_point startTime;
    int score;
};

#endif
