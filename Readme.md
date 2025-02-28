# SDL2 Simple Avoidance Game

This is a simple 2D avoidance game built using SDL2 and C++. The player controls a character that must avoid enemies while navigating a procedurally generated Perlin noise background.

## Demo

![Demo](/resources/Game-2.png)

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

## More Ideas

## Gameplay Elements

### Pickups

* **Health Orbs:**
    * Randomly spawn health orbs that instantly restore a portion of the player's energy.
    * Varying sizes and energy restoration amounts can add strategic depth.
* **Speed Boosts:**
    * Temporary speed boosts that allow the player to evade enemies more effectively.
    * Could have limited durations and visual indicators.
* **Shields:**
    * Temporary shields that protect the player from enemy collisions.
    * Could have limited durations or charges.

### Mining Mechanics

* **Resource Nodes:**
    * Introduce resource nodes within the Perlin noise background.
    * Different nodes could yield different resources.
* **Mining Tool:**
    * The player could acquire a mining tool to extract resources from nodes.
    * Mining could require holding a key or a mini-game.
* **Resource Usage:**
    * Resources could be used to:
        * Craft health orbs or shields.
        * Upgrade mining tools or other equipment.
        * Build structures.

### Random Massive Encounters

* **Enemy Waves:**
    * Introduce random waves of enemies that spawn in large numbers.
    * Waves could vary in intensity and enemy types.
* **Boss Encounters:**
    * Rare boss encounters with unique behaviors and attack patterns.
    * Defeating bosses could yield rare resources or power-ups.
* **Environmental Events:**
    * Random environmental events, such as meteor showers or energy storms, that affect the player and enemies.

### Buildings

* **Base Building:**
    * Allow the player to construct a base or shelter.
    * The base could provide:
        * A safe haven from enemies.
        * Storage for resources.
        * Crafting stations.
* **Turrets:**
    * Allow the player to build turrets to defend their base.
* **Resource Extractors:**
    * Allow the player to build automated resource extractors.

### Other Ideas

* **Enemy Trails:**
    * Enemies leave behind trails that persist for a short time, adding a visual challenge.
* **Enemy Variations:**
    * Introduce different enemy types with unique behaviors and attack patterns.
    * Some enemies could be faster, stronger, or have ranged attacks.
* **Level Progression:**
    * Implement level progression with increasing difficulty.
    * New enemy types and mechanics could be introduced as the player progresses.
* **Sound Effects and Music:**
    * Add sound effects for collisions, pickups, and other events.
    * Implement background music to enhance the atmosphere.
* **Visual Enhancements:**
    * Improve the game's visual appearance with particle effects, animations, and more detailed backgrounds.
* **Minimap:**
    * Add a minimap to help the player navigate the world.
* **Inventory System:**
    * Add an inventory system to hold collected resources and items.
* **Day/Night Cycle:**
    * Add a day/night cycle that affects enemy behavior and resource availability.
* **Saving/Loading:**
    * Implement saving and loading game progress.
* **More varied Perlin noise:**
    * Add more layers of perlin noise to create more varied terrain.
* **Different biomes:**
    * Add different biomes that have different resources and enemy types.

