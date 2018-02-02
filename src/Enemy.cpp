#include "Enemy.h"
#include "Game.h"
#include <math.h>
Enemy::Enemy(int hp1, int atk1, int gold1)
{
    hp = hp1;
    atk = atk1;
    gold = gold1;
};

void Enemy::changeStat(int amount, Stat HP)
{
    hp = hp + amount;
}
void Enemy:: setup(int amount)
{
    hp = amount * 2;
    atk = amount/4;
    gold = amount*5;
}
