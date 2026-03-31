// HPPotion.cpp

#include "ATKPotion.h"
#include "Player.h"

void ATKPotion::UseItem(Player& player)
{
	player.SetIsAttackBuffActive(true);
	int TotalATK = player.GetATK() + 10;
	player.SetATK(TotalATK);
}