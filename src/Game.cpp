#include <SDL3/SDL.h>
#include "Game.hpp"

Game::Game(const char* title, int gridSize, int columns, int rows) : gridSize(gridSize), columns(columns), rows(rows)
{
  windowWidth = gridSize * columns;
  windowHeight = gridSize * rows;
  isRunning = true;
  window = nullptr;
  renderer = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) == false)
  {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    isRunning = false;
    return;
  }

  window = SDL_CreateWindow(title, windowWidth, windowHeight, 0);
  if (window == nullptr)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    isRunning = false;
    return;
  }

  renderer = SDL_CreateRenderer(window, NULL);
  if (renderer == nullptr)
  {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    isRunning = false;
    return;
  }
}

Game::~Game()
{
  clean();
}

void Game::run()
{
  while (isRunning)
  {
    processInput();
    update();
    render();
  }
}

void Game::processInput()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_EVENT_QUIT:
        isRunning = false;
        break;

      default:
        break;
    }
  }
}

void Game::update()
{
}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  drawGrid();

  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  if (renderer) SDL_DestroyRenderer(renderer);
  if (window) SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::drawGrid()
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  for (int i = 0; i <= columns; ++i)
  {
    int x = i * gridSize;
    SDL_RenderLine(renderer, x, 0, x, windowHeight);
  }

  for(int i = 0; i <= rows; ++i)
  {
    int y = i * gridSize;
    SDL_RenderLine(renderer, 0, y, windowWidth, y);
  }
}
