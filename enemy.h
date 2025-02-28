#ifndef ENEMY_H
#define ENEMY_H
#include <SDL2/SDL.h>

struct Vec2 {
    float x, y;
};

struct Enemy {
    Enemy(float x, float y, float vx, float vy);
    void update();
    void reset(float x, float y);
    SDL_Rect getRect() const;
private:
    Vec2 position;
    Vec2 velocity;
    SDL_Rect rect;
};

#endif // ENEMY_H
