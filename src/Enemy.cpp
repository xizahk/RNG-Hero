#include "Enemy.h"
#include "Game.h"
#include <math.h>
Enemy::Enemy(int hp1, int atk1, int gold1)
{
    hp = hp1;
    atk = atk1;
    gold = gold1;
};
void Enemy:: setHp(int new_hp)
{
    hp = new_hp;
}
void Enemy::setatk(int new_atk) {
    atk = new_atk;
}
void Enemy::setGold(int new_gold)
{
    gold = new_gold;
}

void Enemy::changeStat(int amount, Stat stat, Game game)
{
    amount = game.get_round();
    setHp(amount * 2);
    setatk(amount/4);
    setGold(amount* 5);
}