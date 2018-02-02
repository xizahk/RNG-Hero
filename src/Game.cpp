// "Game.cpp"

#include "Game.h"
using namespace std;
#include <cstdlib>
// Starts the game creates a game loop until either
//    1) The player reaches his or her target round. OR
//    2) The player's hp reaches 0 (Game over).
void Game::start()
{
    // Start the game
}

// Processes the a single round in the game and increments round count by 1
//    Determines whether the player faces a Fight, Shop, or Event encounter and
//    processes the encounter.
void Game::processRound()
{
    int single_round = rand()%3;
    round++;
    if (single_round == FIGHT)
    {
        processFight();
    }
    else if (single_round == SHOP)
    {
        processShop();
    }
    else if (single_round == EVENT)
    {
        processEvent();
    }
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
int Game::get_round()
{
    return round;
}
//
// Created by Firec on 2/2/2018.
//

