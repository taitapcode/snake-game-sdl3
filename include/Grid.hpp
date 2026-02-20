#pragma once
#include "Entity.hpp"

class Grid : public Entity
{
public:
  Grid(int size, Vector2 range);
  ~Grid();

  void draw(SDL_Renderer* renderer) override;
};
