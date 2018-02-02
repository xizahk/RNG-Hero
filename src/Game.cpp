// "Game.cpp"

#include "Game.h"
#include <cstdlib>
#include <iostream>
#include "Enemy.h"

using namespace std;

// Starts the game and creates a game loop. The loop continues until either
//    1) The player reaches his or her target round. OR
//    2) The player's hp reaches 0 (Game over).
void Game::start(int target_round)
{
    cout << "Your target round is: " << target_round <<". Good luck!" << endl;
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
    Enemy temp = Enemy();
    temp.setup(get_round());
    cout << temp;
    while (temp.getHp() != 0)
    {
        string option;
        cout << "Choose an option: Fight or Flee" << endl;
        cin >> option;
        if (option == "Fight")
        {
            this->player.changeStat(-temp.getAtk(), HP);
            temp.changeStat(-this->player.getAtk(), HP);
        }
        else if (option == "Flee")
        {
            int fled = rand();
            double probability = min(1,this->player.getAtk());
            if (fled >= probability)
            {
                cout << "You have fled!" << endl;
                break;
            }
            else
            {
                this->player.changeStat(-temp.getAtk(), HP);
            }
        }
        cout << temp;
        if (this->player.getHp()<=0)
        {
            return;
        }
    }

}

// Processes a shop encounter
void Game::processShop()
{
    int numHP, numATK, maxHP, maxATK, money;
    money = this->player.getGold();
    maxHP = floor(money/10);
    
    cout << "Welcome to the shop! Here are the upgrades offered:\nHP +1 -- 10 gold\nATK +1 -- 10 gold" << endl;
    cout << "How many HP +1's would you like to purchase? Currently, you can buy up to " << maxHP << endl;
    cin >> numHP;
    while (numHP > maxHP) {
        cout << "Insufficient gold! How many HP +1's would you like to purchase? Currently, you can buy up to " << maxHP << endl;
        cin >> numHP;
    }
    
    this->player.changeStat(numHP,HP);
    this->player.changeStat(10 * numHP,GOLD);
    
    money = this->player.getGold();
    maxATK = floor(money/10);
    
    cout << "How many ATK +1's would you like to purchase? Currently, you can buy up to " << maxATK << endl;
    cin >> numATK;
    
    while (numATK > maxATK) {
        cout << "Insufficient gold! How many ATK +1's would you like to purchase? Currently, you can buy up to " << maxATK << endl;
        cin >> numATK;
    }
    
    this->player.changeStat(numATK,HP);
    this->player.changeStat(10 * numATK,GOLD);
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

// Returns the current number of rounds in the game.
int Game::get_round()
{
    return round;
}
