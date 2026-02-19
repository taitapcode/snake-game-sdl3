#include <random>
#include "Food.hpp"

Food::Food(int size, int colRange, int rowRange) : size(size), colRange(colRange), rowRange(rowRange), col(0), row(0)
{
  randomizePosition();
}

Food::~Food()
{
}

void Food::randomizePosition()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> colDist(0, colRange - 1);
  std::uniform_int_distribution<> rowDist(0, rowRange - 1);

  col = colDist(gen);
  row = rowDist(gen);
}

void Food::draw(SDL_Renderer* renderer)
{
  SDL_FRect rect = { col * size * 1.0f, row * size * 1.0f, size * 1.0f, size * 1.0f };
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);
}
