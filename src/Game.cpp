#include <SDL3/SDL.h>
#include <iostream>
#include "Game.hpp"

Game::Game(const char* title, int width, int height) : isRunning(true), window(nullptr), renderer(nullptr)
{
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
    isRunning = false;
    return;
  }

  window = SDL_CreateWindow(title, width, height, 0);
  if (!window)
  {
    std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    isRunning = false;
    return;
  }

  renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer)
  {
    std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
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
    if (event.type == SDL_EVENT_QUIT)
    {
      isRunning = false;
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



  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  if (renderer) SDL_DestroyRenderer(renderer);
  if (window) SDL_DestroyWindow(window);
  SDL_Quit();
}

