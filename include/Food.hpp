#pragma once
#include <SDL3/SDL.h>

class Food
{
public:
  Food(int size, int col, int row);
  ~Food();

  void draw(SDL_Renderer* renderer);
  void randomizePosition();

private:
  int size;
  int colRange, rowRange;
  int col, row;
};
