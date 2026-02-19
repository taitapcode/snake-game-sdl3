#pragma once

#include <SDL3/SDL.h>

class Game
{
public:
  Game(const char *title, int gridSize, int columns, int rows);
  ~Game();

  void run();

private:
  bool isRunning;
  int gridSize;
  int columns, rows;
  int windowWidth, windowHeight;
  SDL_Window* window;
  SDL_Renderer* renderer;

  void processInput();
  void update();
  void render();
  void clean();

  void drawGrid();
};
