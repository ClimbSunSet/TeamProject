 // BattleSystem.h

#pragma once

#include "Player.h"
#include "Monster.h"
#include "Structs.h"

#include <iostream>
#include <vector>

class GameSystem;

class BattleSystem
{
public:

	bool Battle(Player& player, Structs::MonsterRewardInfo reward, GameSystem& random);

	Structs::MonsterRewardInfo BattleReward(Player& player, Structs::MonsterRewardInfo reward);

	void UsePotion(Player& player);
};