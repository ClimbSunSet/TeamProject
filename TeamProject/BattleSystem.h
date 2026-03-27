 // BattleSystem.h

#pragma once

#include "Player.h"
#include "Monster.h"
#include "Rewardinfo.h"

#include <iostream>

class BattleSystem
{
public:

	void Battle(Player& player, Monster& monster, Rewardinfo reward);

	Rewardinfo BattleReward(Player& player, Rewardinfo reward);
};

