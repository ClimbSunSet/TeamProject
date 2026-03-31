 // BattleSystem.h

#pragma once

#include "Player.h"
#include "Monster.h"
#include "Structs.h"
#include "UISystem.h" // UI 시스템 헤더 추가 (김준태)

#include <iostream>
#include <vector>

class GameSystem;

class BattleSystem
{
public:

	bool Battle(Player& player, Structs::MonsterRewardInfo reward, GameSystem& random, UISystem& UI); // , UISystem& UI 추가(김준태)

    Structs::MonsterRewardInfo BattleReward(Player& player, Structs::MonsterRewardInfo reward, UISystem& UI, int& logLine);

	void UsePotion(Player& player, UISystem& UI); // UISystem& UI 추가 (김준태)


    // private 추가 (김준태)
private:
    int logLine = 0;
};
