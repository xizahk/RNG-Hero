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
    cout << "Your target round is: " << target_round <<". Good luck!" << endl;
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
//    Player will keep fighting the same enemy until:
//       1. Player dies (i.e. Player's HP <= 0)
//       2. Enemy dies (i.e. Enemy's HP <= 0)
//    Player has a higher chance of fleeing from battle when:
//       1. Player's ATK is high
//       2. Enemy's HP is low
//    Player and enemy's stats are displayed after fighting or fleeing
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
        if (option == "Fight" || option == "fight")
        {
            this->player.changeStat(-temp.getAtk(), HP);
            temp.changeStat(-this->player.getAtk(), HP);
            cout << "Player Stats: " << this->player << endl;
            cout << endl;
        }
        else if (option == "Flee" || option == "flee")
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
                round--;
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
//    Shop sells stats upgrades, each worth 10 GOLD:
//       1. HP +1
//       2. ATK +1
//    Player is prompted to enter the number of upgrades to purchase for each item, respectively
//    Once the player has inputted a valid number, the player cannot return to purchase more of the same item
//       until the next shop encounter
//    The number of upgrades are limited by the count of player's current GOLD
//    The shop will notify the player of the maximum number of each item that can be purchased at this time
//    Player's stats will be updated immediately upon purchase
void Game::processShop()
{
    int numHP, numATK, maxHP, maxATK, money;
    double temp;
    money = this->player.getGold();
    maxHP = floor(money/10);
    
    cout << "Welcome to the shop! Here are the upgrades offered:\nHP +1 -- 10 gold\nATK +1 -- 10 gold" << endl;
    cout << endl;
    cout << "How many HP +1's would you like to purchase? Currently, you can buy up to " << maxHP << endl;
    cout << endl;
    cin >> temp;
    numHP = floor(temp);
    cout << endl;
    
    while (!cin || numHP < 0 || abs(temp - (double)numHP) > 0.000000001) 
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! How many HP +1's would you like to purchase? Currently, you can buy up to " << maxHP << endl;
        cout << endl;
        cin >> temp;
        numHP = floor(temp);
        cout << endl;
    }
    
    while (numHP > maxHP) 
    {
        cout << "Insufficient gold! How many HP +1's would you like to purchase? Currently, you can buy up to " << maxHP << endl;
        cout << endl;
        cin >> temp;
        numHP = floor(temp);
        cout << endl;
    }
    
    this->player.changeStat(numHP,HP);
    this->player.changeStat(-10 * numHP,GOLD);
    
    money = this->player.getGold();
    maxATK = floor(money/10);
    
    cout << "How many ATK +1's would you like to purchase? Currently, you can buy up to " << maxATK << endl;
    cout << endl;
    cin >> temp;
    numATK = floor(temp);
    cout << endl;
    
    while (!cin || numATK < 0 || abs(temp - (double)numATK) > 0.000000001) 
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! How many ATK +1's would you like to purchase? Currently, you can buy up to " << maxATK << endl;
        cout << endl;
        cin >> temp;
        numATK = floor(temp);
        cout << endl;
    }
    
    while (numATK > maxATK) 
    {
        cout << "Insufficient gold! How many ATK +1's would you like to purchase? Currently, you can buy up to " << maxATK << endl;
        cout << endl;
        cin >> temp;
        numATK = floor(temp);
        cout << endl;
    }
    
    this->player.changeStat(numATK,ATK);
    this->player.changeStat(-10 * numATK,GOLD);
}

// Processes a event encounter
//    Player can choose roll or not to roll
//       Rolling will generate a random number that will affect the player's stats:
//          1. Random number is greater than 0.5 --> HP +1, ATK +1
//          2. Random number is less than or equal to 0.5 --> HP -1, ATK -1
//    If the player does not roll, that signifies the end of the encounter
//    At the end of the encounter, player will be notified of any changes to stats or the lack thereof
//    Player's current stats will be displayed
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
    if (choice == "yes" || choice == "Yes") 
    {
        r = dist(mt);
        if (r > 0.5) 
        {
            this->player.changeStat(1,HP);
            this->player.changeStat(1,ATK);
            cout << "Congratulations! Your stats have increased. " << endl;
            cout << "Player Stats: " << this->player << endl;
            cout << endl;
        }
        else 
        {
            this->player.changeStat(-1,HP);
            this->player.changeStat(-1,ATK);
            cout << "Oh no! Your stats have decreased. " << endl;
            cout << "Player Stats: " << this->player << endl;
            cout << endl;
        }
    }
    else 
    {
        cout << "Your stats have not changed. " << endl;
        cout << "Player Stats: " << this->player << endl;
        cout << endl;
    }
}

// Returns the current number of rounds in the game.
int Game::get_round()
{
    return round;
}
