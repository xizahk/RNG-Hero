// Game.h
//
// This class is responsible for handling rounds. It keeps tracks
//    of the player's progress.

#ifndef GAME_H
#define GAME_H
#include <cstdlib>
#include "Player.h"

enum Events
{
    FIGHT = 0, SHOP = 1, EVENT = 2

};
class Game
{
    Player player;
    int round;

public:
    Game(Player player) : player(player), round(0) {};
    void start(int target_round);
    int get_round();

private:
    void processRound();
    void processFight();
    void processShop();
    void processEvent();
};

#endif // GAME_H
