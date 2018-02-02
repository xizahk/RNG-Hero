// "Player.cpp"

#include <Player.h>

// Change the player's stat given type of Stat and amount to change.
void Player::changeStat(int amount, Stat stat)
{
	switch (stat) {
		case HP:
			this->hp = this->hp + amount;
			break;
		case ATK:
			this->atk = this->atk + amount;
			break;
		case GOLD:
			this->gold = this->gold + amount;
			break;
	}
}
