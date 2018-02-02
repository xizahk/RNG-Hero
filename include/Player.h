// "Player.h"
//
// This class represents the player in a game, and provides several
// methods for accessing and changing player's stats.

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

enum Stat
{
    HP,
    ATK,
    GOLD
};

class Player
{
    // Combat stats
    int hp;
    int atk;
    // Non-combat stat
    int gold;

    public:
        Player() : hp(100), atk(10), gold(0) {};
        Player(int hp, int atk, int gold) : hp(hp), atk(atk), gold(gold) {};
        void changeStat(int amount, Stat stat);
        int getGold() { return gold;};
        int getHp() { return hp; };
        int getAtk() { return atk; };
        friend std::ostream &operator<<(std::ostream &os, Player &p);
};

#endif // PLAYER_H
