#include "Snake.hpp"

Snake::Snake(int size, Vector2 range) : Entity(size, Vector2(range.x / 2, range.y / 2), range)
{
  body.push_back(Vector2(range.x / 2, range.y / 2));
  direction = Vector2::RIGHT;
}

Snake::~Snake()
{
  body.clear();
}

void Snake::draw(SDL_Renderer* renderer)
{
  for (const Vector2 &segment : body) {
    SDL_FRect rect = {
      segment.x * size * 1.0f,
      segment.y * size * 1.0f,
      size * 1.0f,
      size * 1.0f
    };

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
  }
}
