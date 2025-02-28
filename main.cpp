#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <SDL2/SDL.h>
#include "perlin.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "render.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS;

    SDL_Window* window = SDL_CreateWindow("SDL2 Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Try with and without SDL_RENDERER_PRESENTVSYNC
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Try Software Rendering.
    //SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    } else {
        std::cout << "Renderer created successfully." << std::endl;
    }

    Game game(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);

    bool quit = false;
    SDL_Event e;
    Uint32 frameStart;
    int frameTime;

    while (!quit) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN && game.isGameOver() && e.key.keysym.sym == SDLK_r) {
                game.resetGame();
            } else {
                game.handleInput(e);
            }
        }
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
