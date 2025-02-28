#include "player.h"
#include "perlin.h"
#include <algorithm>
#include "constants.h"
#include <chrono>

Player::Player(float x, float y) : position({x, y}), energy(100), maxEnergy(200), lastEnergyUpdate(std::chrono::high_resolution_clock::now()) {
    rect = {static_cast<int>(x - 10), static_cast<int>(y - 10), 20, 20};
}

void Player::handleInput(SDL_Event& e) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    if (currentKeyStates[SDL_SCANCODE_UP]) position.y -= PLAYER_MOVE_SPEED;
    if (currentKeyStates[SDL_SCANCODE_DOWN]) position.y += PLAYER_MOVE_SPEED;
    if (currentKeyStates[SDL_SCANCODE_LEFT]) position.x -= PLAYER_MOVE_SPEED;
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) position.x += PLAYER_MOVE_SPEED;
    rect.x = static_cast<int>(position.x - 10);
    rect.y = static_cast<int>(position.y - 10);
}

void Player::update(const std::vector<Uint8>& perlinPixels, int screenWidth) {
    int x = static_cast<int>(position.x);
    int y = static_cast<int>(position.y);
    int grayValue = perlinPixels[y * screenWidth + x];

    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastEnergyUpdate).count();

    if (elapsed > ENERGY_UPDATE_INTERVAL) {
        float energyChange = 0.0f;
        float grayValueFloat = static_cast<float>(grayValue); // Convert to float

        if (grayValueFloat < 127.5f) { // Use 127.5 as the midpoint
            energyChange = -ENERGY_DRAIN_RATE * (elapsed / 60000.0f);
        } else {
            energyChange = ENERGY_GAIN_RATE * (elapsed / 60000.0f);
        }

        energy += static_cast<int>(energyChange);

        if (energy < 0) energy = 0;
        if (energy > maxEnergy) energy = maxEnergy;

        lastEnergyUpdate = now;
    }
}

bool Player::checkCollision(const Enemy& enemy) const {
    SDL_Rect enemyRect = enemy.getRect();
    int leftA = rect.x;
    int rightA = rect.x + rect.w;
    int topA = rect.y;
    int bottomA = rect.y + rect.h;

    int leftB = enemyRect.x;
    int rightB = enemyRect.x + enemyRect.w;
    int topB = enemyRect.y;
    int bottomB = enemyRect.y + enemyRect.h;

    if (bottomA <= topB) return false;
    if (topA >= bottomB) return false;
    if (rightA <= leftB) return false;
    if (leftA >= rightB) return false;

    return true;
}

void Player::takeDamage() {
    energy -= ENEMY_DAMAGE;
    if (energy < 0) energy = 0;
}

int Player::getEnergy() const {
    return energy;
}

int Player::getMaxEnergy() const {
    return maxEnergy;
}

SDL_Rect Player::getRect() const {
    return rect;
}

void Player::reset(float x, float y) {
    position = {x, y};
    energy = 100;
    rect.x = static_cast<int>(x - 10);
    rect.y = static_cast<int>(y - 10);
    lastEnergyUpdate = std::chrono::high_resolution_clock::now();
}
