#pragma once
#include <SDL3/SDL.h>
#include "Vector2.hpp"

class  Entity
{
protected:
  int size;
  Vector2 pos, range;

public:
  Entity(int size, Vector2 pos, Vector2 range);
  virtual ~Entity();

  virtual void draw(SDL_Renderer* renderer) = 0;
};
