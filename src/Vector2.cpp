#include "Vector2.hpp"

const Vector2 Vector2::UP(0, -1);
const Vector2 Vector2::DOWN(0, 1);
const Vector2 Vector2::LEFT(-1, 0);
const Vector2 Vector2::RIGHT(1, 0);

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(int x, int y) : x(x), y(y) {}
Vector2::~Vector2() {}

bool Vector2::operator == (const Vector2& other) const
{
  return x == other.x && y == other.y;
}

bool Vector2::operator != (const Vector2& other) const
{
  return !(*this == other);
}

Vector2 Vector2::operator + (const Vector2& other) const
{
  return Vector2(x + other.x, y + other.y);
}
