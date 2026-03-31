// BattleSystem.cpp

#include "BattleSystem.h"
#include "GameSystem.h"
#include "Monster.h"
#include "SewerRat.h"
#include "MiniPig.h"
#include "WildBoar.h"
#include "Goblin.h"
#include "HPPotion.h"
#include "ATKPotion.h"

bool BattleSystem::Battle(Player& player, Structs::MonsterRewardInfo reward, GameSystem& random)
{
	bool isPlayerDead; // 메인시스템에 반환할 분기 제어용 부울 변수 선언.

	if (! player.GetInventory().empty())
	{
		UsePotion(player);
	}

	int monsterType = random.RandomMonsterSpawn();
	// 부모 포인터 클래스 만들어서 다형성 활용해보기

	Monster* mons;

	if (monsterType == 0)
	{
		mons = new SewerRat(player.GetLevel());
		std::cout << "시궁쥐가 등장했습니다!" << std::endl;
	}

	else if (monsterType == 1)
	{
		mons = new MiniPig(player.GetLevel());
		std::cout << "미니피그가 등장했습니다!" << std::endl;
	}

	else if (monsterType == 2)
	{
		mons = new WildBoar(player.GetLevel());
		std::cout << "멧돼지가 등장했습니다!" << std::endl;
	}

	else
	{
		mons = new Goblin(player.GetLevel());
		std::cout << "고블린이 등장했습니다!" << std::endl;
	}

	while (player.GetHP() > 0 && mons->GetHP() > 0)
	{
		player.Attack();
		mons->TakeDamage(player.GetATK());

		if (mons->GetHP() <= (mons->GetMaxHP() * 0.15))
		{
			mons->isPredated = true;
			player.SkillPredation(mons);
		}

		if (mons->GetisDead() == 0)
		{
			mons->Attack();
			player.TakeDamage(mons->GetATK());
		}

		else
		{
			break;
		}
	}

	std::cout << "전투가 종료되었습니다!" << std::endl;

	if (player.GetIsDead() == 1)
	{
		// 전투 중 사망 판정을 받을 시 태초마을로 돌아감.
		isPlayerDead = true;
		std::cout << "캐릭터가 사망하여 처음으로 돌아갑니다!" << std::endl;
	}

	else
	{
		isPlayerDead = false;
		BattleReward(player, reward);
	}

	if (player.GetIsAttackBuffActive() == true)
	{
		player.SetIsAttackBuffActive(false);
		int ATK = player.GetATK() - 10;
		player.SetATK(ATK);
	}

	if (!mons->isPredated)
	{
		delete mons;
		mons = nullptr;
	}
	
	return isPlayerDead;
}

Structs::MonsterRewardInfo BattleSystem::BattleReward(Player& player, Structs::MonsterRewardInfo reward)
{
	reward.EXP += 50;
	std::cout << "플레이어의 경험치가 50 증가했습니다!" << std::endl;

	int RewardGOLD = rand() % 11 + 10;
	reward.GOLD = RewardGOLD;
	std::cout << "플레이어의 소지 GOLD가 " << RewardGOLD << "만큼 추가되었습니다!" << std::endl;

	int chance = rand() % 100;
	if (chance < 30)
	{
		int chance = rand() % 2;
		if (chance == 0)
		{
			player.AddItem(new HPPotion());
			std::cout << "HP포션을 드랍하여 인벤토리에 추가되었습니다!" << std::endl;
		}
		else
		{
			player.AddItem(new ATKPotion());
			std::cout << "ATK포션을 드랍하여 인벤토리에 추가되었습니다!" << std::endl;
		}
	}

	return reward;
}

void BattleSystem::UsePotion(Player& player)
{
	while (true)
	{
		int choice;

		std::cout << "포션 사용 메뉴" << std::endl;
		std::cout << "1. HP포션" << std::endl;
		std::cout << "2. ATK포션" << std::endl;
		std::cout << "3. 사용안함" << std::endl;
		std::cout << "입력: ";
		std::cin >> choice;
	
		if (choice == 1)
		{
			player.GetInventory()[choice - 1]->UseItem(player);
			break;
		}

		else if (choice == 2)
		{
			player.GetInventory()[choice - 1]->UseItem(player);
			break;
		}

		else if (choice == 3)
		{
			break;
		}

		else
		{
			std::cout << "다시 입력하세요!" << std::endl;
		}
	
	}
}