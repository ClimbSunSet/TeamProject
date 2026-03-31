// GameSystem.h

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "BattleSystem.h"
#include "Structs.h"
#include "UISystem.h" // 1. UISystem 헤더 추가 (김준태)

class GameSystem
{
public:
	Player player;
    UISystem UI; // 2. UI 객체 멤버 변수 추가 (김준태)

	void GameStart();
	void RunBattle();
	void RunRest();

	int RandomMonsterSpawn();
};

