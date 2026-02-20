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
  const std::vector<Vector2> directions = {
    {0, -1},  // UP
    {0, 1},   // DOWN
    {-1, 0},  // LEFT
    {1, 0}    // RIGHT
  };

  std::vector<Vector2> body;
  Direction direction;
};
