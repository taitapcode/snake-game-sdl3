#include "Game.hpp"

int main(int argc, char* argv[])
{
  Game* game = new Game("Snake SDL3", 50, {15, 15});
  game->run();

  delete game;
  return 0;
}
