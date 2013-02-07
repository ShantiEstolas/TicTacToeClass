#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;

    game.initialize();
    game.run();

    return 0;
}
