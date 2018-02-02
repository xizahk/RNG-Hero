// "Game.cpp"

#include "Game.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Starts the game and creates a game loop. The loop continues until either
//    1) The player reaches his or her target round. OR
//    2) The player's hp reaches 0 (Game over).
void Game::start(int target_round)
{
    cout << "Your target round is: " << target_round <<". Good luck!" << endl;
    while (this->round != target_round)
    {
        cout << "The current round is: " << this->round
            << "\nYour stats: " << this->player << endl;
        this->processRound();
        if (this->player.getHp() <= 0) {
            break;
        }
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
	string choice;
	double r;
	cout << "Do you want to test your luck? Enter yes to roll a dice or no to end the round." << endl;
	cin >> choice;
	if (choice == "yes" || choice == "Yes") {
		r = ((double) rand() / (RAND_MAX));
		if (r > 0.5) {
			this->player.changeStat(1,HP);
			this->player.changeStat(1,ATK);
		}
		else {
			this->player.changeStat(-1,HP);
			this->player.changeStat(-1,ATK);
		}
	}
}
int Game::get_round()
{
    return round;
}
