#include "Grid.hpp"

Grid::Grid(int size, Vector2 range) : Entity(size, Vector2(0, 0), range) {}
Grid::~Grid() {}

void Grid::draw(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  for (int x = 1; x < range.x; x++)
    SDL_RenderLine(renderer, x * size, 0, x * size, range.y * size);
  for (int y = 1; y < range.y; y++)
    SDL_RenderLine(renderer, 0, y * size, range.x * size, y * size);
}
