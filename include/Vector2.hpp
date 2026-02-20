#pragma once

class Vector2
{
public:
  Vector2();
  Vector2(int x, int y);
  ~Vector2();

  int x, y;

  bool operator == (const Vector2& other) const;
  bool operator != (const Vector2& other) const;
  Vector2 operator + (const Vector2& other) const;
  Vector2 operator % (const Vector2& other) const;
};
