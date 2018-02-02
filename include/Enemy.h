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
    void changeStat(int amount, Stat stat);
    void setup(int amount);
};
