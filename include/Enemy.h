//
// Created by Firec on 2/2/2018.
//
#include "Game.h"
#include "Player.h"
#ifndef RNGHERO_ENEMY_H
#define RNGHERO_ENEMY_H
using namespace std;
#endif //RNGHERO_ENEMY_H
class Enemy: public Player
{
    private:
    int hp;
    int atk;
    int gold;
    public:
    Enemy(): hp(2), atk(1), gold(1){};
    Enemy(int hp, int atk, int gold): hp(hp), atk(atk), gold(gold){};
    void changeStat(int amount, Stat stat, Game game);
    void setHp(int new_hp);
    void setatk(int new_atk);
    void setGold(int new_gold);
};

