// "main.cpp"
// This file is responsible for creating and running Games.

#include <iostream>
#include <Game.h>
#include <Player.h>

int main()
{
    Player player = Player();
    Game game = Game(player);
    game.start();
}
