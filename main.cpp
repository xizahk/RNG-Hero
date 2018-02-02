// "main.cpp"
// This file is responsible for creating and running Games.

#include <iostream>
#include <string>
#include "Game.h"
#include "Player.h"

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
        
        cout << "Please select a difficulty from 1 (easiest) to 20 (hardest): ";
        cin >> difficulty;
        
        while (difficulty < 1 || difficulty > 20)
        {
            cout << "Please select a difficulty from 1 to 20: ";
            cin >> difficulty;
        }
        
        while (!cin)
        {
            cout << "Please enter an integer from 1 to 20: ";
            cin >> difficulty;
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
