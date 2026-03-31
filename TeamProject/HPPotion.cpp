// HPPotion.cpp

#include "HPPotion.h"
#include "Player.h"

void HPPotion::UseItem(Player& player)
{
	int TotalHP = player.GetHP() + 50;
	player.SetHP(TotalHP);

	if (player.GetHP() > player.GetMaxHP())
	{
		player.SetHP(player.GetMaxHP());
	}
}
