#pragma once
#include <SDL3/SDL.h>
#include "Vector2.hpp"
#include "Grid.hpp"
#include "Snake.hpp"
#include "Food.hpp"

class Game
{
public:
  Game(const char *title, int size, Vector2 range, int tps = 10);
  ~Game();

  void run();

private:
  bool isRunning = true;
  SDL_Window* window;
  SDL_Renderer* renderer;

  int tps;
  Uint64 lastTickTime = 0;

  Grid* grid;
  Snake* snake;
  Food* food;

  void processInput();
  void update();
  void render();
  void clean();
};
