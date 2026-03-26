// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

class Character
{
public:
	int Level = 1;
	int HP = 200;
	int ATK = 30;
	int EXP = 0;
	int GOLD = 0;
	bool isDead = 0;

	void attack() // 공격함수 출력만 함.
	{
		std::cout << "캐릭터가 공격했습니다" << std::endl;
		std::cout << ATK << "만큼의 피해를 입힙니다!" << std::endl;
	}

	void takedamage(int Damage) // 맞은 놈이 HP 연산 처리함.
	{
		HP -= Damage;

		if (HP <= 0)
		{
			HP = 0;
		}

		std::cout << "캐릭터가 " << Damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << std::endl;

		SetDead();
	}

	void SetDead() // 지가 맞고 죽었는지 아닌지 판단함.
	{
		if (HP <= 0)
		{
			isDead = 1;
		}

		if (isDead == 1)
		{
			std::cout << "캐릭터가 사망했습니다!" << std::endl;
		}
	}
};

class  Monster
{
public:

	int HP = 20;
	int ATK = 3;
	bool isDead = 0;

	void attack() // 공격함수 출력만 함.
	{
		std::cout << "슬라임이 공격했습니다" << std::endl;
		std::cout << ATK << "만큼의 피해를 입힙니다!" << std::endl;
	}

	void takedamage(int Damage) // 맞은 놈이 HP 연산 처리함.
	{
		HP -= Damage;

		if (HP <= 0)
		{
			HP = 0;
		}

		std::cout << "슬라임이 " << Damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << std::endl;

		SetDead();
	}

	void SetDead()
	{
		if (HP <= 0)
		{
			isDead = 1;
		}

		if (isDead == 1)
		{
			std::cout << "슬라임이 죽었습니다!" << std::endl;
		}
	}
};

void BattleReward(Character& player);

int main(void)
{
	srand(time(0)); // rand는 seed값을 기준으로 동작한다. seed값이 같으면 항상 같은 값만 반환함.
	// 그래서, time(0)을 넣어서 현재 시간으로 설정하여, seed값을 유동적인 값으로 바꿔줌.
	Character player1;
	Monster Slime;
	std::cout << "캐릭터와 슬라임이 생성 되었습니다!" << std::endl;
	std::cout << "슬라임과 전투에 돌입합니다." << std::endl;

	while (player1.HP > 0 && Slime.HP > 0)
	{
		player1.attack(); // 플레이어 먼저 행동.
		Slime.takedamage(player1.ATK);

		if (!Slime.isDead) // 슬라임이 살아있다면 계속 전투 
		{
			Slime.attack();
			player1.takedamage(Slime.ATK);
		}

		else // 슬라임이 죽었다면 반복문 탈출.
		{
			break;
		}
	}

	std::cout << "전투가 종료되었습니다!" << std::endl;

	if (player1.isDead == 1)
	{
		// 게임 종료 함수 호출
	}

	if (Slime.isDead == 1)
	{
		BattleReward(player1);
	}

	return 0;
}

void BattleReward(Character& player)
{
	player.EXP += 50;
	std::cout << "플레이어의 경험치가 50 증가했습니다!" << std::endl;

	int RewardGOLD = rand() % 11 + 10;
	player.GOLD += RewardGOLD;
	std::cout << "플레이어의 소지 GOLD가 " << RewardGOLD << "만큼 추가되었습니다!" << std::endl;

	int chance = rand() % 100;
	if (chance < 30)
	{
		//해당 몬스터의 드랍테이블 내에 아이템중 30%의 확률로 무작위 드랍.
		std::cout << "아이템이 드랍하여 인벤토리에 추가되었습니다!" << std::endl;
	}
}