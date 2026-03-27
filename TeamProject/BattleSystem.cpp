// BattleSystem.cpp

#include "BattleSystem.h"

void BattleSystem::Battle(Player& player, Monster& monster, Rewardinfo reward)
{
	while (player.GetHP() > 0 && monster.GetHP() > 0)
	{
		player.Attack();
		monster.TakeDamage(player.GetATK());

		if (monster.GetHP() <= 0)
		{
			player.SkillPredation();
		}

		if (monster.GetisDead() == 0)
		{
			monster.Attack();
			player.TakeDamage(monster.GetATK());
		}

		else
		{
			break;
		}
	}

	std::cout << "전투가 종료되었습니다!" << std::endl;

	if (player.GetisDead() == 1)
	{
		// 전투 중 사망 판정을 받을 시 태초마을로 돌아감.
		std::cout << "캐릭터가 사망하여 처음으로 돌아갑니다!" << std::endl;
	}

	else
	{
		BattleReward(player, reward);
	}
}

Rewardinfo BattleSystem::BattleReward(Player& player, Rewardinfo reward)
{
	reward.EXP += 50;
	std::cout << "플레이어의 경험치가 50 증가했습니다!" << std::endl;

	int RewardGOLD = rand() % 11 + 10;
	reward.GOLD = RewardGOLD;
	std::cout << "플레이어의 소지 GOLD가 " << RewardGOLD << "만큼 추가되었습니다!" << std::endl;

	int chance = rand() % 100;
	if (chance < 30)
	{
		//해당 몬스터의 드랍테이블 내에 아이템중 30%의 확률로 무작위 드랍.
		std::cout << "아이템이 드랍하여 인벤토리에 추가되었습니다!" << std::endl;
	}

	return reward;
}