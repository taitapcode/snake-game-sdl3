#include "Snake.hpp"

Snake::Snake(int size, Vector2 range) : Entity(size, Vector2(range.x / 2, range.y / 2), range)
{
  body.push_back(Vector2(range.x / 2, range.y / 2));
  direction = Direction::RIGHT;
}

Snake::~Snake()
{
  body.clear();
}

void Snake::move(bool grow)
{
  Vector2 newHead = body.front() + directions[static_cast<unsigned char>(direction)];

  if (newHead.x < 0 || newHead.x >= range.x || newHead.y < 0 || newHead.y >= range.y)
    newHead = (newHead + range) % range;

  body.insert(body.begin(), newHead);
  if (!grow) body.pop_back();
}

void Snake::changeDirection(Direction newDir)
{
  // Ignore if the new direction is the same as the current one
  if (direction == newDir) return;

  // Prevent reversing direction if the snake has more than one segment
  if (body.size() > 1 &&
      ((direction == Direction::UP && newDir == Direction::DOWN) ||
       (direction == Direction::DOWN && newDir == Direction::UP) ||
       (direction == Direction::LEFT && newDir == Direction::RIGHT) ||
       (direction == Direction::RIGHT && newDir == Direction::LEFT)))
    return;

  direction = newDir;
}

Vector2 Snake::getHead() const
{
  return body.front();
}

bool Snake::checkBodyCollision(const Vector2& pos) const
{
  for(int i = 1; i < body.size(); ++i)
    if (body[i] == pos) return true;
  return false;
}

void Snake::draw(SDL_Renderer* renderer)
{
  for(int i = 0; i < body.size(); i++)
  {
    SDL_FRect rect = { body[i].x * size * 1.0f, body[i].y * size * 1.0f, size * 1.0f, size * 1.0f };

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
  }
}

int Snake::getScore() const
{
  return body.size() - 1;
}
