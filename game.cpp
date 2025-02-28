#include "game.h"
#include <random>
#include <chrono>
#include <algorithm>
#include <iostream>
#include "constants.h"

Game::Game(int width, int height, SDL_Renderer* renderer)
    : screenWidth(width), screenHeight(height), renderer(renderer), player(width / 2.0f, height / 2.0f), perlinPixels(width * height), renderObj(renderer, width, height), gen(rd()), gameOver(false), score(0) {
    disX = std::uniform_real_distribution<float>(0, width);
    disY = std::uniform_real_distribution<float>(0, height);
    disSpeed = std::uniform_real_distribution<float>(-ENEMY_SPEED, ENEMY_SPEED);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float perlinValue = perlin2d(x / 50.0f, y / 50.0f);
            int grayValue = static_cast<int>((perlinValue + 1.0f) * 127.5f);
            perlinPixels[y * width + x] = grayValue;
        }
    }
    startTime = std::chrono::high_resolution_clock::now();
}

void Game::handleInput(SDL_Event& e) {
    player.handleInput(e);
}

void Game::update() {
    if (gameOver) return;

    auto current_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - lastEnemySpawn).count();

    if (elapsed_time > ENEMY_SPAWN_INTERVAL) {
        enemies.emplace_back(disX(gen), disY(gen), disSpeed(gen) * enemySpeedMultiplier, disSpeed(gen) * enemySpeedMultiplier);
        lastEnemySpawn = current_time;
        enemySpeedMultiplier += ENEMY_SPEED_INCREMENT;
    }

    player.update(perlinPixels, screenWidth);
    for (auto& enemy : enemies) {
        enemy.update();
        if (player.checkCollision(enemy)) {
            player.takeDamage();
            enemy.reset(disX(gen), disY(gen));
        }
    }

    if (player.getEnergy() <= 0) {
        gameOver = true;
        auto endTime = std::chrono::high_resolution_clock::now();
        auto playTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
        score = player.getMaxEnergy() + static_cast<int>(playTime);
        std::cout << "Game Over! Score: " << score << std::endl;
        std::cout << "Press 'R' to restart." << std::endl;
    }
}

void Game::render() {
    renderObj.clear();
    renderObj.renderBackground(perlinPixels);
    renderObj.renderPlayer(player);
    renderObj.renderEnemies(enemies);
    renderObj.renderHealthBar(player.getEnergy());
    renderObj.present();
}

bool Game::isGameOver() const {
    return gameOver;
}

int Game::getScore() const {
    return score;
}

void Game::resetGame() {
    gameOver = false;
    score = 0;
    player.reset(screenWidth / 2.0f, screenHeight / 2.0f);
    enemies.clear();
    enemySpeedMultiplier = 1.0f;
    startTime = std::chrono::high_resolution_clock::now();
}
