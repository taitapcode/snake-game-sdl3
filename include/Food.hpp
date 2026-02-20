#pragma once
#include "Entity.hpp"

class Food : public Entity
{
public:
  Food(int size, Vector2 range);
  ~Food();

  Vector2 getPos() const;
  void random();
  void draw(SDL_Renderer* renderer) override;
};
