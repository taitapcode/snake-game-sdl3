#pragma once

#include <SDL3/SDL.h>

class Game
{
public:
  Game(const char *title, int width, int height);
  ~Game();

  void run();

private:
  bool isRunning;
  SDL_Window* window;
  SDL_Renderer* renderer;

  void processInput();
  void update();
  void render();
  void clean();
};
