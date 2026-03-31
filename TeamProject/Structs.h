// Sturcts.h

#pragma once

#include <iostream>
#include <string>

class Structs
{
public:
	struct MonsterRewardInfo
	{
		int EXP;
		int GOLD;
		// Item table
	};

	struct BattleReward
	{
		int RewardEXP;
		int RewardGOLD;
		bool isDropItem;
	};

	struct BattleRewardMsg // 호출해서 값을 채워서 출력하기로 함.
	{
		std::string BattleOverMsg;
		std::string BackToFirstStageMsg;
		std::string BattleRewardEXPMsg;
		std::string BattleRewardGOLDMsg;
		std::string BattleRewardDropItemMsg;
	};
};

