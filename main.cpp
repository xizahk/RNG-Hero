// "main.cpp"
// This file is responsible for creating and running Games.

#include <iostream>
#include <Game.h>
#include <Player.h>

int main()
{
    Player player = Player();
    int target_round = 20;
    Game game = Game(player);
    game.start(target_round);
}
