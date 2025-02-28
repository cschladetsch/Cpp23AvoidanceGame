#ifndef RENDER_H
#define RENDER_H
#include <vector>
#include <SDL2/SDL.h>
#include "player.h"
#include "enemy.h"

class Render {
public:
    Render(SDL_Renderer* renderer, int width, int height);
    ~Render(); // Add destructor declaration
    void clear();
    void renderBackground(const std::vector<Uint8>& pixels);
    void renderPlayer(const Player& player);
    void renderEnemies(const std::vector<Enemy>& enemies);
    void renderHealthBar(int energy);
    void present();
private:
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;
    const int HEALTH_BAR_HEIGHT = 20;
    SDL_Texture* perlinTexture; // Declare perlinTexture as a member variable
};

#endif // RENDER_H
