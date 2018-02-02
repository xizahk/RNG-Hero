// "main.cpp"
// This file is responsible for creating and running Games.

#include <iostream>
#include <string>
#include "Game.h"
#include "Player.h"
#include <math.h>


using namespace std;

int main()
{
    cout << "Welcome to RNG Hero!" << endl;
    bool play_game = true;
    while (play_game == true) {
        Player player = Player();
        Game game = Game(player);
        int target_round;
        int difficulty;
        double temp;
        
        cout << "Please select a difficulty from 1 (easiest) to 20 (hardest): ";
        cin >> temp;
        difficulty = floor(temp);
        
        while (!cin || abs(temp - (double)difficulty) > 0.01 || difficulty < 1 || difficulty > 20)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter an integer from 1 to 20: ";
            cin >> temp;
            difficulty = floor(temp);
        }
        
        target_round = difficulty * 25;
        game.start(target_round);
        
        string choice;
        cout << "Would you like to play again? (Enter 'yes' to play again)" << endl;
        cin >> choice;
        if (!(choice == "yes" || choice == "Yes")) {
            play_game = false;
        }
    }
    
    cout << "Thank you for playing!" << endl;
}

