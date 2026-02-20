# AGENTS.md - Agent Guidelines for Snake-Game-SDL3

This document provides coding standards and build instructions for agentic coding agents working on this C++ SDL3 Snake game project.

## Build, Lint, and Test Commands

### Build
```bash
cmake -S . -B build
cmake --build build
```

### Run
```bash
./build/SnakeSDL3
```

### Clean Build
```bash
rm -rf build
cmake -S . -B build
cmake --build build
```

### Generate Compile Commands
The project is configured to generate `compile_commands.json` for IDE integration:
```bash
cat build/compile_commands.json
```

## Code Style Guidelines

### Language & Version
- **Language**: C++11 or later
- **Standard**: Follow modern C++ best practices
- **Build System**: CMake 4.0+
- **Dependencies**: SDL3

### Includes & Headers
- Use `#pragma once` for header guards (see: `include/Game.hpp`)
- Include order: stdlib → SDL3 → local project headers
  ```cpp
  #include <SDL3/SDL.h>
  #include <vector>
  #include "Game.hpp"
  ```
- Include guards in all `.hpp` files
- Use relative paths for local includes

### Naming Conventions
- **Classes**: PascalCase (e.g., `Game`, `Snake`, `Entity`)
- **Methods**: camelCase (e.g., `processInput()`, `update()`, `render()`)
- **Member variables**: camelCase (e.g., `isRunning`, `window`, `renderer`)
- **Constants**: PascalCase or UPPER_SNAKE_CASE
- **Files**: Match class name exactly (e.g., `Game.hpp`, `Snake.cpp`)

### Formatting & Indentation
- **Indentation**: 2 spaces (consistent throughout codebase)
- **Braces**: Allman style (opening brace on same line for functions)
  ```cpp
  void Game::run()
  {
    // implementation
  }
  ```
- **Line length**: Keep reasonable; SDL3 API calls may exceed limits
- **Spacing**: Space after keywords, around operators

### Classes & Objects
- Use inheritance for shared functionality (see: `Snake` extends `Entity`)
- Declare public interface first, then private implementation
- Use virtual destructors for base classes
- Prefer stack allocation when possible; use `new`/`delete` for dynamic memory
- Initialize member variables in constructor (see: `Game::Game()`)

### Error Handling
- Check for null pointers before dereferencing (see: `Game::Game()` constructor)
- Use SDL_Log() for error reporting
- Return early on initialization failures
- Do not throw exceptions unless necessary
  ```cpp
  if (window == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    isRunning = false;
    return;
  }
  ```

### Memory Management
- Explicitly manage heap memory with `new`/`delete`
- Destructor must clean up all allocated resources
- Consider RAII for resource management in future refactors
- Initialize pointers to `nullptr` before assignment

### Function Design
- Keep functions focused and single-responsibility
- Private methods for implementation details (e.g., `processInput()`, `update()`, `render()`)
- Prefer const references for parameters when possible
- Use `override` keyword for virtual functions in derived classes

### Type System
- Use explicit types (avoid `auto` for clarity)
- Use `nullptr` instead of NULL or 0
- Use `bool` for boolean values (not int)
- Leverage C++ standard library (`<vector>`, etc.)

### Comments & Documentation
- Add comments for complex algorithms or non-obvious logic
- Keep comments up-to-date with code changes
- Use descriptive variable and function names to minimize comment need

## Project Structure

```
Snake-Game-SDL3/
├── CMakeLists.txt         # Build configuration
├── include/               # Header files (.hpp)
│   ├── Game.hpp
│   ├── Snake.hpp
│   ├── Entity.hpp
│   ├── Food.hpp
│   ├── Grid.hpp
│   └── Vector2.hpp
├── src/                   # Implementation files (.cpp)
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Snake.cpp
│   └── ...
└── build/                 # Build output (git-ignored)
```

## Key Classes

- **Game**: Main game loop and SDL initialization/cleanup
- **Snake**: Player-controlled snake entity
- **Food**: Food entity to be consumed
- **Entity**: Base class for drawable game objects
- **Grid**: Game grid/board management
- **Vector2**: 2D vector utility class

## Git Commit Messages

When writing commit messages:
- Use a prefix indicating the change type: `feat:`, `fix:`, `refactor:`, `docs:`, `test:`, `chore:`, etc.
- Do not capitalize words (except proper nouns like class names)
- Use lowercase after the prefix
- Examples:
  - `feat: add collision detection to snake movement`
  - `fix: null pointer check in renderer initialization`
  - `refactor: use vector2 for grid range instead of separate columns/rows`

## Development Tips

1. Always rebuild after modifying headers or CMakeLists.txt
2. Check for memory leaks by reviewing `new`/`delete` pairs
3. Test SDL3 API calls for null return values
4. Run the full build to catch compilation errors early
5. Keep header dependencies minimal to reduce compile time
