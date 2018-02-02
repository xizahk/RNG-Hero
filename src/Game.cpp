// "Game.cpp"

#include "Game.h"
using namespace std;

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
		r = ((double) rand() / (RAND_MAX)) + 1;
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
