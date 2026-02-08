#include "Game.hpp"

int main(int argc, char* argv[])
{
  Game *game = new Game("Snake SDL3", 800, 800);
  game->run();

  delete game;
  return 0;
}
