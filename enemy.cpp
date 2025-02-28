#include "enemy.h"

Enemy::Enemy(float x, float y, float vx, float vy) : position({x, y}), velocity({vx, vy}) {
    rect = {static_cast<int>(x - 7), static_cast<int>(y - 7), 15, 15};
}

void Enemy::update() {
    position.x += velocity.x;
    position.y += velocity.y;
    rect.x = static_cast<int>(position.x - 7);
    rect.y = static_cast<int>(position.y - 7);
}

void Enemy::reset(float x, float y) {
    position = {x, y};
    rect.x = static_cast<int>(x - 7);
    rect.y = static_cast<int>(y - 7);
}

SDL_Rect Enemy::getRect() const {
    return rect;
}
