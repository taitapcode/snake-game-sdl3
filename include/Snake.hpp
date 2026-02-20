#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "Entity.hpp"

class Snake : public Entity
{
public:
  Snake(int size, Vector2 range);
  ~Snake();

  void draw(SDL_Renderer* renderer) override;

private:
  std::vector<Vector2> body;
  Vector2 direction;
};
