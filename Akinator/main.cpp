#include <iostream>
#include <stdlib.h>
#include "CGame.cpp"

using namespace std;

int main()
{
  Game game = Game();

  game.Create();
  game.Run();
  system("pause");
  return 0;
}