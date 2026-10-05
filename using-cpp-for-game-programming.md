# C++ Game Development — Project Setup & Roadmap

This document describes the development environment, dependencies, project structure, build system, and learning roadmap for developing games with **C++ on Linux Mint using CLion, CMake, GCC/G++, and raylib**.

---

## 1. Technology Stack

| Component  | Purpose                              |
| ---------- | ------------------------------------ |
| C++        | Main programming language            |
| GCC / G++  | C++ compiler                         |
| CMake      | Build system / project configuration |
| CLion      | C++ IDE                              |
| raylib     | Game programming library             |
| Git        | Version control                      |
| Linux Mint | Development OS                       |

### Development Pipeline

```text
C++ Source Code
      ↓
    G++ / GCC
      ↓
    CMake
      ↓
   raylib
      ↓
Game Executable
```

CLion is the development environment/IDE. It is **not** the game engine.

raylib provides the game-related functionality such as:

* Window creation
* Keyboard input
* Mouse input
* Gamepad input
* 2D graphics
* Basic 3D graphics
* Text rendering
* Textures
* Audio
* Music
* Basic collision helpers
* Timing / FPS control

---

# 2. Why C++ for Game Development?

C++ is widely used in game development because it provides:

* High performance
* Direct memory control
* Low-level system access
* Strong object-oriented programming support
* Templates and generic programming
* Excellent ecosystem
* Native compilation
* Good support for game engines

Major engines such as **Unreal Engine** use C++ extensively.

C++ is particularly useful when learning how games actually work internally because it does not hide as much of the underlying system as higher-level game development environments.

---

# 3. Linux Mint Environment

For Linux Mint, **MinGW is not required**.

MinGW is primarily used to provide a GCC-based Windows development environment.

On Linux, use:

```text
GCC / G++
```

The basic toolchain is:

```text
Linux Mint
    ↓
GCC / G++
    ↓
CMake
    ↓
CLion
```

---

# 4. Required Packages

Install the basic C++ development tools:

```bash
sudo apt update
sudo apt install build-essential cmake git
```

This provides the core compiler/build environment.

Check the installations:

```bash
g++ --version
cmake --version
git --version
```

Expected tools:

```text
g++
cmake
git
```

---

# 5. CLion

CLion is the IDE used for the project.

CLion provides:

* C++ code completion
* Refactoring
* Debugging
* CMake integration
* Git integration
* Project navigation
* Compiler/toolchain configuration
* Code analysis
* Run configurations

The important distinction is:

```text
CLion = IDE

G++ = Compiler

CMake = Build System

raylib = Game Library

C++ = Programming Language
```

---

# 6. CLion Toolchain

On Linux, CLion should normally use the system compiler.

Typical configuration:

```text
Settings
    ↓
Build, Execution, Deployment
    ↓
Toolchains
```

Configure:

```text
C Compiler   → /usr/bin/gcc
C++ Compiler → /usr/bin/g++
Build Tool   → CMake
Debugger     → GDB
```

Usually CLion can detect these automatically.

Verify from terminal:

```bash
which gcc
which g++
which cmake
which gdb
```

Typical paths:

```text
/usr/bin/gcc
/usr/bin/g++
/usr/bin/cmake
/usr/bin/gdb
```

---

# 7. raylib

raylib is a lightweight game programming library written in C.

It is useful for learning game programming without immediately dealing with a large game engine.

raylib provides APIs for:

```text
Window
Input
Graphics
Textures
Sprites
Text
Audio
Music
Gamepad
Timing
2D
3D
```

It is particularly suitable for:

* Learning game programming
* 2D games
* Small/medium projects
* Prototypes
* Graphics programming fundamentals
* Understanding game loops

---

# 8. Installing raylib

One option is to build raylib from source.

Clone the repository:

```bash
git clone https://github.com/raysan5/raylib.git
```

Enter the directory:

```bash
cd raylib
```

Configure the build:

```bash
cmake -B build
```

Build it:

```bash
cmake --build build
```

Install it:

```bash
sudo cmake --install build
```

After installation, raylib should be available to CMake projects.

---

# 9. Verify raylib Installation

Create a small test project.

Example:

```cpp
#include "raylib.h"

int main() {
    InitWindow(800, 600, "Raylib Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("raylib is working!", 250, 280, 30, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
```

If the project builds and opens a window, the raylib installation is working.

---

# 10. CMake

CMake is responsible for describing how the C++ project should be built.

Instead of manually compiling every `.cpp` file, CMake handles:

* Source files
* Include directories
* Libraries
* Compiler settings
* Build configuration
* Executable creation
* Dependencies

The main configuration file is:

```text
CMakeLists.txt
```

---

# 11. Basic CMake Configuration

Example:

```cmake
cmake_minimum_required(VERSION 3.20)

project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(MyGame
    src/main.cpp
)

target_link_libraries(MyGame PRIVATE raylib)
```

The important sections are:

```cmake
project(MyGame)
```

Defines the project.

```cmake
set(CMAKE_CXX_STANDARD 17)
```

Uses C++17.

```cmake
find_package(raylib REQUIRED)
```

Finds raylib.

```cmake
add_executable(MyGame src/main.cpp)
```

Creates the game executable.

```cmake
target_link_libraries(MyGame PRIVATE raylib)
```

Links raylib to the game.

---

# 12. Recommended Project Structure

Start with:

```text
MyGame/
├── CMakeLists.txt
├── README.md
├── info.md
├── .gitignore
├── src/
│   └── main.cpp
├── include/
├── assets/
│   ├── textures/
│   ├── sounds/
│   ├── music/
│   └── fonts/
└── build/
```

As the project grows:

```text
MyGame/
├── CMakeLists.txt
├── README.md
├── info.md
├── .gitignore
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Player.cpp
│   ├── Enemy.cpp
│   ├── World.cpp
│   ├── Input.cpp
│   └── Audio.cpp
├── include/
│   ├── Game.hpp
│   ├── Player.hpp
│   ├── Enemy.hpp
│   ├── World.hpp
│   ├── Input.hpp
│   └── Audio.hpp
├── assets/
│   ├── textures/
│   ├── sprites/
│   ├── sounds/
│   ├── music/
│   └── fonts/
└── build/
```

---

# 13. Build Directory

The `build/` directory contains generated build files and compiled binaries.

It normally should **not** be committed to Git.

Add this to `.gitignore`:

```gitignore
build/
cmake-build-*/
.idea/
*.o
*.obj
*.exe
```

CLion normally uses:

```text
cmake-build-debug/
```

or a similar directory.

---

# 14. Basic Game Loop

Almost every real-time game has a game loop.

Conceptually:

```text
Initialize
    ↓
Input
    ↓
Update
    ↓
Render
    ↓
Repeat
    ↓
Exit
```

A simple raylib implementation:

```cpp
while (!WindowShouldClose()) {
    // Input
    // Update

    BeginDrawing();

    // Render

    EndDrawing();
}
```

The loop runs many times per second.

For example:

```text
60 FPS = approximately 60 frames per second
```

---

# 15. Input

raylib provides keyboard functions such as:

```cpp
IsKeyDown(KEY_W)
IsKeyPressed(KEY_SPACE)
IsKeyReleased(KEY_E)
```

Example:

```cpp
if (IsKeyDown(KEY_W)) {
    player.y -= 5;
}
```

Movement:

```cpp
if (IsKeyDown(KEY_W)) player.y -= 5;
if (IsKeyDown(KEY_S)) player.y += 5;
if (IsKeyDown(KEY_A)) player.x -= 5;
if (IsKeyDown(KEY_D)) player.x += 5;
```

---

# 16. Player

A player should eventually be represented by its own class.

Example:

```cpp
class Player {
public:
    Vector2 position;
    float speed;

    void update();
    void draw();
};
```

Implementation:

```cpp
void Player::update() {
    if (IsKeyDown(KEY_W)) position.y -= speed;
    if (IsKeyDown(KEY_S)) position.y += speed;
    if (IsKeyDown(KEY_A)) position.x -= speed;
    if (IsKeyDown(KEY_D)) position.x += speed;
}
```

The main game then becomes:

```text
Game
 ├── Player
 ├── Enemies
 ├── World
 ├── Audio
 └── UI
```

---

# 17. Game Architecture

As the project becomes larger, avoid putting everything inside `main.cpp`.

A better architecture:

```text
Game
├── Game Loop
├── Input System
├── Player
├── Enemy System
├── World
├── Collision System
├── Animation System
├── Audio System
├── UI
└── Scene Management
```

Possible classes:

```text
Game
Player
Enemy
EnemyManager
World
Collision
InputManager
AudioManager
TextureManager
Scene
Menu
Level
GameState
```

---

# 18. Game States

Most games need multiple states.

Example:

```text
MENU
  ↓
PLAYING
  ↓
PAUSED
  ↓
GAME_OVER
```

A simple enum:

```cpp
enum class GameState {
    Menu,
    Playing,
    Paused,
    GameOver
};
```

This allows different logic and rendering depending on the current state.

---

# 19. Assets

Game assets should be separated from source code.

Recommended structure:

```text
assets/
├── textures/
│   ├── player.png
│   ├── enemy.png
│   └── world.png
├── sounds/
│   ├── jump.wav
│   └── hit.wav
├── music/
│   └── background.ogg
└── fonts/
    └── game.ttf
```

Do not hard-code large binary assets directly into `.cpp` files.

---

# 20. Collision

Collision detection determines whether game objects interact.

Examples:

```text
Player ↔ Wall
Player ↔ Enemy
Bullet ↔ Enemy
Player ↔ Item
Player ↔ Door
```

For 2D games, common collision techniques include:

```text
Rectangle collision
Circle collision
Point collision
Bounding box collision
```

raylib provides helper functions such as rectangle collision functions.

---

# 21. Delta Time

Movement should eventually use delta time instead of assuming every frame takes exactly the same amount of time.

Bad approach:

```cpp
player.x += 5;
```

This makes movement dependent on FPS.

Better concept:

```cpp
player.x += speed * deltaTime;
```

This makes movement more consistent across different frame rates.

The general model is:

```text
Position += Velocity × DeltaTime
```

---

# 22. FPS

Set a target FPS:

```cpp
SetTargetFPS(60);
```

For a simple game:

```text
60 FPS
```

is a reasonable starting point.

Later, learn the difference between:

```text
FPS
Delta Time
Fixed Update
Variable Update
VSync
Frame Pacing
```

---

# 23. Debugging

CLion can use GDB to debug the game.

Typical workflow:

```text
Set breakpoint
    ↓
Run Debug
    ↓
Game stops at breakpoint
    ↓
Inspect variables
    ↓
Step through code
```

Useful things to inspect:

```text
Player position
Velocity
Health
Enemy state
Game state
Collision values
Input state
```

Debugging is important for game development because many bugs are state/timing related.

---

# 24. Git

Initialize the repository:

```bash
git init
```

Add files:

```bash
git add .
```

Commit:

```bash
git commit -m "Initial game project"
```

Recommended branches:

```text
main
develop
feature/player
feature/enemies
feature/audio
feature/menu
```

Do not commit generated build directories.

---

# 25. Recommended `.gitignore`

```gitignore
build/
cmake-build-*/
.idea/
.vscode/
*.o
*.obj
*.exe
*.dll
*.so
```

Do not ignore your source code or game assets unless there is a specific reason.

---

# 26. Development Roadmap

## Phase 1 — C++ Fundamentals

Learn:

```text
Variables
Functions
Classes
Objects
Pointers
References
Structs
Enums
Templates
STL
Vectors
Strings
Smart Pointers
RAII
Header Files
Source Files
Namespaces
```

Focus especially on:

```text
std::vector
std::string
std::unique_ptr
std::shared_ptr
```

and modern C++ practices.

---

# 27. Phase 2 — CMake

Learn:

```text
CMakeLists.txt
Targets
Executables
Libraries
include directories
Linking
Debug/Release builds
Dependencies
```

Basic concept:

```text
CMakeLists.txt
      ↓
CMake
      ↓
Build System
      ↓
G++
      ↓
Executable
```

---

# 28. Phase 3 — raylib Fundamentals

Learn:

```text
Window
Game Loop
Drawing
Input
Textures
Sprites
Text
Audio
Music
Collision
Camera
2D Coordinates
```

First projects should be small.

Recommended order:

```text
1. Hello Window
2. Moving Square
3. Pong
4. Snake
5. Breakout
6. Top-Down Shooter
7. Platformer
```

---

# 29. Phase 4 — Game Architecture

After basic games, learn:

```text
Game Loop
Game State
Scene Management
Entity Management
Collision System
Input System
Audio System
Resource Management
Animation
UI
Save/Load
```

At this stage, stop putting everything into `main.cpp`.

---

# 30. Phase 5 — Mathematics

Game development requires basic mathematics.

Learn:

```text
Vectors
Coordinates
Distance
Direction
Velocity
Acceleration
Angles
Trigonometry
Matrices
Transforms
```

For 2D:

```text
Vector2
```

For 3D:

```text
Vector3
```

Important concepts:

```text
Position
Direction
Velocity
Rotation
Scale
Transform
```

---

# 31. Phase 6 — 3D Game Development

Once comfortable with 2D, learn:

```text
3D coordinates
Camera
Perspective
Meshes
Materials
Textures
Lighting
Shaders
Depth
Transforms
```

At this point, OpenGL concepts can become useful.

The learning path can be:

```text
C++
  ↓
raylib 2D
  ↓
raylib 3D
  ↓
Graphics fundamentals
  ↓
OpenGL concepts
```

---

# 32. Unreal Engine Path

If the eventual goal is professional/AAA-style 3D development, move toward Unreal Engine.

Architecture:

```text
C++
   +
Unreal Engine
   +
3D Assets
   +
Blueprints
```

Unreal provides many systems that would otherwise need to be implemented manually:

```text
Rendering
Physics
Animation
Networking
Audio
UI
Particles
Lighting
World Management
Asset Management
```

C++ is used for gameplay and engine-level functionality.

---

# 33. raylib vs Unreal Engine

| Feature            | raylib         | Unreal       |
| ------------------ | -------------- | ------------ |
| Learning C++       | Excellent      | Moderate     |
| Learning game loop | Excellent      | Less visible |
| 2D                 | Excellent      | Good         |
| 3D                 | Basic/Moderate | Excellent    |
| AAA development    | No             | Yes          |
| Complexity         | Low            | Very High    |
| Editor             | Minimal        | Full editor  |
| Physics            | Basic          | Advanced     |
| Rendering          | Basic          | Advanced     |
| Networking         | Limited        | Advanced     |
| Beginner friendly  | Yes            | No           |
| Lightweight        | Yes            | No           |

Recommended learning order:

```text
C++
 ↓
raylib
 ↓
Game Architecture
 ↓
3D Fundamentals
 ↓
Unreal Engine
```

---

# 34. What Is NOT Required Initially?

For the first 2D game, do not install everything.

You do **not** initially need:

```text
MinGW
Visual Studio
Unreal Engine
OpenGL SDK
Vulkan SDK
DirectX
SDL
Multiple game engines
```

Start with:

```text
G++
CMake
Git
CLion
raylib
```

That is enough for the initial development environment.

---

# 35. Recommended Initial Installation

Linux Mint:

```bash
sudo apt update
sudo apt install build-essential cmake git
```

Verify:

```bash
g++ --version
cmake --version
git --version
```

Install raylib:

```bash
git clone https://github.com/raysan5/raylib.git
cd raylib
cmake -B build
cmake --build build
sudo cmake --install build
```

Then create the game project in CLion.

---

# 36. First Game Target

The first meaningful project should not be a huge game.

Target:

```text
Top-Down 2D Game
```

Example:

```text
Player
  ↓
Move with WASD
  ↓
Enemies
  ↓
Collision
  ↓
Health
  ↓
Shooting
  ↓
Score
  ↓
Game Over
  ↓
Restart
```

This single project can teach a large portion of fundamental game programming.

---

# 37. Suggested First Project Architecture

```text
MyGame/
├── CMakeLists.txt
├── README.md
├── info.md
├── .gitignore
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Player.cpp
│   ├── Enemy.cpp
│   ├── World.cpp
│   ├── Input.cpp
│   └── Audio.cpp
├── include/
│   ├── Game.hpp
│   ├── Player.hpp
│   ├── Enemy.hpp
│   ├── World.hpp
│   ├── Input.hpp
│   └── Audio.hpp
└── assets/
    ├── textures/
    ├── sounds/
    ├── music/
    └── fonts/
```

---

# 38. Core Game Flow

The final architecture should conceptually look like:

```text
main()
  ↓
Game::initialize()
  ↓
while (!Game::shouldClose())
  ├── Input
  ├── Update
  │    ├── Player
  │    ├── Enemies
  │    ├── Physics
  │    └── Collision
  │
  └── Render
       ├── World
       ├── Player
       ├── Enemies
       └── UI
  ↓
Game::shutdown()
```

---

# 39. Performance Principles

Do not optimize everything prematurely.

First make the game correct.

Then measure.

Important concepts later:

```text
CPU usage
GPU usage
FPS
Frame time
Memory usage
Allocations
Asset loading
Draw calls
Cache behavior
```

Basic rule:

```text
Correctness → Profiling → Optimization
```

Do not assume that a particular implementation is slow without measuring it.

---

# 40. Long-Term Learning Path

The complete roadmap:

```text
C++ Fundamentals
        ↓
Modern C++
        ↓
CMake
        ↓
Git
        ↓
raylib
        ↓
Game Loop
        ↓
Input
        ↓
Graphics
        ↓
Collision
        ↓
Physics
        ↓
Animation
        ↓
Audio
        ↓
Game Architecture
        ↓
2D Games
        ↓
3D Mathematics
        ↓
3D Graphics
        ↓
OpenGL Concepts
        ↓
Unreal Engine
        ↓
Advanced C++ Game Development
```

---

# 41. Initial Toolchain Summary

The initial development environment should be:

```text
OS:
Linux Mint

IDE:
CLion

Language:
C++

Compiler:
G++

Build System:
CMake

Debugger:
GDB

Game Library:
raylib

Version Control:
Git
```

No MinGW is required for this Linux setup.

---

# 42. Final Goal

The purpose of this setup is not simply to learn how to make a window or move a sprite.

The long-term objective is to understand:

```text
How a game works
How the game loop works
How input is processed
How objects are represented
How physics works
How collision works
How rendering works
How assets are managed
How game state works
How large C++ projects are structured
How performance is measured
How a game engine works internally
```

After understanding these fundamentals, moving to a larger engine such as Unreal Engine becomes significantly easier because the underlying concepts are already familiar.

---

## Quick Reference

### Compile manually

```bash
g++ src/main.cpp -o MyGame -lraylib
```

For normal projects, prefer CMake instead of manually compiling every file.

### Configure CMake

```bash
cmake -B build
```

### Build

```bash
cmake --build build
```

### Run

```bash
./build/MyGame
```

The exact executable location may differ depending on the CMake generator/configuration.

### Git

```bash
git status
git add .
git commit -m "Initial game setup"
```

---

## Recommended Starting Stack

```text
Linux Mint
    +
CLion
    +
C++
    +
G++
    +
CMake
    +
raylib
    +
Git
```

Start with a small 2D game, build the architecture properly, and then progressively move toward 3D and Unreal Engine.
