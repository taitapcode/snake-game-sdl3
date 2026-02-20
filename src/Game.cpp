#include "Game.hpp"

Game::Game(const char* title, int size, Vector2 range, int tps) : tps(tps)
{
  isRunning = true;
  window = nullptr;
  renderer = nullptr;

  snake = new Snake(size, range);
  food = new Food(size, range);
  grid = new Grid(size, range);

  if (SDL_Init(SDL_INIT_VIDEO) == false)
  {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    isRunning = false;
    return;
  }

  window = SDL_CreateWindow(title, range.x * size, range.y * size, 0);
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

    Uint64 currentTime = SDL_GetTicks();
    if (currentTime - lastTickTime >= 1000 / tps)
    {
      update();
      lastTickTime = currentTime;
    }

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

  // Draw food, snake, then grid on top
  food->draw(renderer);
  snake->draw(renderer);
  grid->draw(renderer);

  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  delete food;
  delete snake;
  delete grid;

  if (renderer) SDL_DestroyRenderer(renderer);
  if (window) SDL_DestroyWindow(window);
  SDL_Quit();
}

