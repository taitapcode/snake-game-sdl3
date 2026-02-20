#pragma once

class Vector2
{
public:
  Vector2();
  Vector2(int x, int y);
  ~Vector2();

  static const Vector2 UP;
  static const Vector2 DOWN;
  static const Vector2 LEFT;
  static const Vector2 RIGHT;
  int x, y;

  bool operator == (const Vector2& other) const;
  bool operator != (const Vector2& other) const;
  Vector2 operator + (const Vector2& other) const;
};
