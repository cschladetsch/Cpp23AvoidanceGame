# SDL2 Simple Avoidance Game

This is a simple 2D avoidance game built using SDL2 and C++. The player controls a character that must avoid enemies while navigating a procedurally generated Perlin noise background.

## Features

* **Procedural Background:** The game uses Perlin noise to generate a dynamic background.
* **Enemy Avoidance:** Players must avoid enemies that spawn and move across the screen.
* **Energy/Health System:** The player's energy/health is affected by both the background color and enemy collisions.
* **Game Over and Score:** The game ends when the player's energy reaches zero, and a score is displayed.
* **Restart Functionality:** Players can restart the game by pressing the 'R' key.
* **Frame Rate Control:** The game uses `SDL_Delay` to maintain a consistent frame rate.
* **Direct Keyboard Input:** The player movement is driven by the `SDL_GetKeyboardState` for a more responsive feel.

## Prerequisites

* SDL2 library (including development headers)
* A C++ compiler (e.g., g++, Clang)
* CMake (for building the project)

## Building the Game

```bash
$ rm -rf build && mkdir build && cmake .. && make && ./SDL2Game
```

## Game Controls

* **Arrow Keys:** Move the player.
* **R Key:** Restart the game (when the game is over).

## Game Mechanics

* **Background Interaction:**
    * The player's energy/health is affected by the background color. Darker regions drain energy, while lighter regions restore it.
    * Energy drain and gain rates are set in `constants.h`.
* **Enemy Collisions:**
    * Colliding with enemies causes significant energy loss.
    * Enemies spawn at increasing rates and speeds.
* **Game Over:**
    * The game ends when the player's energy reaches zero.
    * The score is calculated based on the maximum energy and the play time.

## File Structure

* `main.cpp`: Contains the main game loop and SDL initialization.
* `game.h` / `game.cpp`: Manages the game logic, including enemy spawning, player updates, and rendering.
* `player.h` / `player.cpp`: Handles player movement, energy, and collision detection.
* `enemy.h` / `enemy.cpp`: Defines the enemy behavior.
* `render.h` / `render.cpp`: Manages rendering using SDL2.
* `perlin.h` / `perlin.cpp`: Implements Perlin noise generation.
* `constants.h`: Defines game constants.
* `CMakeLists.txt`: CMake build configuration file.

## Troubleshooting

* **Segmentation Faults:**
    * If you encounter segmentation faults, try running the game with a debugger (e.g., gdb) to pinpoint the error.
    * Ensure your SDL2 installation is correct.
    * If running under WSL, try software rendering.
* **Input Lag:**
    * Ensure your graphics drivers are up-to-date.
    * try compiling in release mode.
    * Try with and without VSync.

## Future Improvements

* Add sound effects and music.
* Implement different enemy types.
* Add a visual trail effect for the enemies.
* Implement a pause menu.
* Improve the game's visual appearance.
* Add a start screen.

