// "Game.cpp"

#include <Game.h>
#include <iostream>

using namespace std;

// Starts the game and creates a game loop. The loop continues until either
//    1) The player reaches his or her target round. OR
//    2) The player's hp reaches 0 (Game over).
void Game::start(int target_round)
{
    while (this->round != target_round)
    {
        this->processRound();
    }

    if (this->round == target_round) {
        cout << "Congratulations! ";
    } else {
        cout << "Gameover. ";
    }
    cout << "You have reached round: " << this->round << endl;
    return;
}

// Processes a single round in the game and increments round count by 1
//    Determines whether the player faces a Fight, Shop, or Event encounter and
//    processes the encounter.
void Game::processRound()
{

}

// Processes a fight encounter.
void Game::processFight()
{

}

// Processes a shop encounter
void Game::processShop()
{

}

// Processes a event encounter
void Game::processEvent()
{

}
