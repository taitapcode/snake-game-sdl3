#pragma once
#include <SDL3/SDL.h>
#include "Grid.hpp"
#include "Snake.hpp"
#include "Food.hpp"

class Game
{
public:
  Game(const char *title, int gridSize, int columns, int rows);
  ~Game();

  void run();

private:
  bool isRunning;
  SDL_Window* window;
  SDL_Renderer* renderer;

  Grid* grid;
  Snake* snake;
  Food* food;

  void processInput();
  void update();
  void render();
  void clean();
};
