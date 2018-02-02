// "Game.cpp"

#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
// Starts the game and creates a game loop. The loop continues until either
//    1) The player reaches his or her target round. OR
//    2) The player's hp reaches 0 (Game over).
void Game::start(int target_round)
{
    while (this->round != target_round)
    {
        this->processRound();
        if (this->player.getHp() <= 0)
        {
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
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0,3);
    //int single_round = rand()%3;
    round++;
    if (floor(dist(mt))== FIGHT)
    {
        processFight();
    }
    else if (floor(dist(mt))== SHOP)
    {
        processShop();
    }
    else if (floor(dist(mt)) == EVENT)
    {
        processEvent();
    }
}

// Processes a fight encounter.
void Game::processFight()
{

    Player temp = Player(get_round()*2, round/4, round*5);
    cout << "Player Stats: " << this->player << endl;
    cout << endl;
    cout << "Enemy Stats: " << temp << endl;
    cout << endl;
    while (temp.getHp() != 0)
    {
        string option;
        cout << "Choose an option: Fight or Flee" << endl;
        cout << endl;
        cin >> option;
        cout << endl;
        if (option == "Fight")
        {
            this->player.changeStat(-temp.getAtk(), HP);
            temp.changeStat(-this->player.getAtk(), HP);
            cout << "Player Stats: " << this->player << endl;
            cout << endl;
        }
        else if (option == "Flee")
        {
            random_device rd;
            mt19937 mt(rd());
            uniform_real_distribution<double> dist(0,1);
            double fled = dist(mt);
            double probability = min(1.00, double(this->player.getAtk()/temp.getHp()));
            if (fled <= probability)
            {
                cout << "You have fled!" << endl;
                cout << endl;
                cout << "Player Stats: " << this->player << endl;
                cout << endl;
                break;
            }
            else
            {
                this->player.changeStat(-temp.getAtk(), HP);
                cout << "Could not flee!" << endl;
                cout << endl;
                cout << this->player << endl;
            }
        }
        if (this->player.getHp()<=0)
        {
            return;
        }
        if (temp.getHp() <= 0)
        {
            cout << "You won the battle." << endl;
            cout << endl;
            this->player.changeStat(temp.getGold(),GOLD);
            return;
        }
        cout << "Enemy Stats: " << temp << endl;
        cout << endl;
    }

}

// Processes a shop encounter
void Game::processShop()
{
    int numHP, numATK, maxHP, maxATK, money;
    money = this->player.getGold();
    maxHP = floor(money/10);
    
    cout << "Welcome to the shop! Here are the upgrades offered:\nHP +1 -- 10 gold\nATK +1 -- 10 gold" << endl;
    cout << endl;
    cout << "How many HP +1's would you like to purchase? Currently, you can buy up to " << maxHP << endl;
    cout << endl;
    cin >> numHP;
    cout << endl;
    while (numHP > maxHP) {
        cout << "Insufficient gold! How many HP +1's would you like to purchase? Currently, you can buy up to " << maxHP << endl;
        cout << endl;
        cin >> numHP;
        cout << endl;
    }
    
    this->player.changeStat(numHP,HP);
    this->player.changeStat(-10 * numHP,GOLD);
    
    money = this->player.getGold();
    maxATK = floor(money/10);
    
    cout << "How many ATK +1's would you like to purchase? Currently, you can buy up to " << maxATK << endl;
    cout << endl;
    cin >> numATK;
    cout << endl;
    
    while (numATK > maxATK) {
        cout << "Insufficient gold! How many ATK +1's would you like to purchase? Currently, you can buy up to " << maxATK << endl;
        cout << endl;
        cin >> numATK;
        cout << endl;
    }
    
    this->player.changeStat(numATK,HP);
    this->player.changeStat(-10 * numATK,GOLD);
}


// Processes a event encounter
void Game::processEvent()
{
	string choice;
	double r;
	cout << "Do you want to test your luck? Enter yes to roll a dice or no to end the round." << endl;
    cout << endl;
	cin >> choice;
    cout << endl;
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0,1);
	if (choice == "yes" || choice == "Yes") {
		r = dist(mt);
		if (r > 0.5) {
			this->player.changeStat(1,HP);
			this->player.changeStat(1,ATK);
            cout << "Player Stats: " << this->player << endl;
            cout << endl;
		}
		else {
			this->player.changeStat(-1,HP);
			this->player.changeStat(-1,ATK);
            cout << "Player Stats: " << this->player << endl;
            cout << endl;
		}
	}
}
int Game::get_round()
{
    return round;
}