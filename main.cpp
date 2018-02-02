// "main.cpp"
// This file is responsible for creating and running Games.

#include <iostream>
#include <Game.h>
#include <Player.h>

using namespace std;

int main()
{
    cout << "Welcome to RNG Hero!" << endl;
    bool play_game = true;
    while (play_game == true) {
        Player player = Player();
        Game game = Game(player);
        int target_round = 200;
        game.start(target_round);
        break;
    }
}
