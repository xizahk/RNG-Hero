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
    public:
        Game(Player player) : player(player), round(0) {};
        void start(int target_round);

    private:
        void processRound();
        void processFight();
        void processShop();
        void processEvent();
};

#endif // GAME_H
