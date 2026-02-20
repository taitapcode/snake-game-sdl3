#include <random>
#include "Food.hpp"

Food::Food(int size, Vector2 range) : Entity(size, Vector2(0, 0), range)
{
  random();
}

Food::~Food()
{
}

void Food::random()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> colDist(0, range.x - 1), rowDist(0, range.y - 1);

  pos = Vector2(colDist(gen), rowDist(gen));
}

void Food::draw(SDL_Renderer* renderer)
{
  SDL_FRect rect = {
    pos.x * size * 1.0f,
    pos.y * size * 1.0f,
    size * 1.0f,
    size * 1.0f
  };

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);
}
