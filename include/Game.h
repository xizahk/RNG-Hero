// Game.h
//
// This class is responsible for handling rounds. It keeps tracks
//    of the player's progress.

#ifndef GAME_H
#define GAME_H
#include <Player.h>

class Game
{
    Player player;
    int round;
    int target_round;
    public:
        Game(Player player, int target) : player(player), target_round(target_round) {};
        void start();

    private:
        void processRound();
        void processFight();
        void processShop();
        void processEvent();
};

#endif // GAME_H
