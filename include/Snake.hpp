#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "Entity.hpp"

enum class Direction : unsigned char
{
  UP = 0,
  DOWN = 1,
  LEFT = 2,
  RIGHT = 3
};

class Snake : public Entity
{
public:
  Snake(int size, Vector2 range);
  ~Snake();

  void move(bool grow);
  void changeDirection(Direction newDir);
  Vector2 getHead() const;
  bool checkBodyCollision(const Vector2& pos) const;
  int getScore() const;
  void draw(SDL_Renderer* renderer) override;

private:
  static const std::vector<Vector2> directions;
  std::vector<Vector2> body;
  Direction direction;
};
