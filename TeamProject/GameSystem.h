// GameSystem.h

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "BattleSystem.h"
#include "Structs.h"

class GameSystem
{
public:
	Player player;

	void GameStart();
	void RunBattle();
	void RunRest();

	int RandomMonsterSpawn();
};

