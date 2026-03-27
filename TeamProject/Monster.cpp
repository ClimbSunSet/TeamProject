//Monster.cpp

#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//공격 이벤트 Event.target 사용
struct AttackEvent {
	string target;
	int damage;
};

Monster::Monster(string name, int playerlevel) : Monster()
{
	this->name = name;
	Level = playerlevel;
	//체력
		int minHP = Level * 20;
		int maxHPRange = Level * 30;
	HP = rand() % (maxHPRange - minHP + 1) + minHP;
	MaxHP = HP; //가오나시 흡수스킬을 위해 Monster.h에 int MaxHP; 를 추가

	if (HP <= 0)
	{
		HP = 0;
	}

	//공격력
		int minATK = Level * 5;
		int maxATK = Level * 10;
	ATK = rand() % (maxATK - minATK + 1) + minATK;

	if (ATK <= 0)
	{
		ATK = 0;
	}
}

Monster::Monster()
{
	Reward.EXP = 50;
	Reward.GOLD = rand() % 11 + 10;
}

//등장출력
void Monster::Firstspeech() const
{
	std::cout << name << "이(가) 등장했다 ! "<< std::endl;
	
}

//공격출력
void Monster::Attack() const
{
	AttackEvent event;
	event.target = "Player";
	event.damage = ATK;

	std::cout << name << "이(가) " << event.target << "을(를) 공격했다!\n"
		<< event.target << "에게 " << event.damage << "만큼 피해를 입혔다!" << std::endl;
}

//데미지 받음
void Monster::TakeDamage(int damage)
{
	HP = HP - damage;
	if (HP < 0) HP = 0;
}

//사망
bool Monster::isDead() const
{
	return HP <= 0;
}

const Rewardinfo& Monster::Dropitem() const
{
	return Reward;
}


/**void Monster::Dropitem() const
{
	int DropChance = rand() % 100;

	if (DropChance < 40)
	{
		std::cout << name << "이(가) 아이템을 드랍했습니다.\n";
	}
}*/

/*
// 플레이어가 LUK 수치가 존재할 경우
void Monster::Dropitem(const Player& player) const
{
	int p_LUK = player.LUK();

	std::cout << "생성자였던" << name << "이(가) 소멸자가 되어버렸습니다...\n";

	if (p_LUK > 0 && p_LUK <= 3)
	{
		int DropChance = rand() % 100;

		if (DropChance < 40)
		{
			int itemTier = rand() % 100;

			if (itemTier < 100)
			{
				//하얀색 아이템 드랍
			}
		}
	}

	else if (p_LUK > 3 && p_LUK <= 10)
	{
		int DropChance = rand() % 100;

		if (DropChance < 40)
		{
			int itemTier = rand() % 100;
			
			if (itemTier < 90)
			{
				//하얀색 아이템 드랍
			}
			
			else
			{
				//파란색 아이템 드랍
			}
		}

		else
		{
			std::cout << "아쉽게도 아무런 장비를 얻지 못했습니다..." << std::endl;
		}
	}

	if (p_LUK > 10 && p_LUK <= 20)
	{
		int DropChance = rand() % 100;

		if (DropChance < 60)
		{
			int DropChance = rand() % 100;

			if (DropChance < 60)
			{
				int itemTier = rand() % 100;

				if (itemTier < 50)
				{
					//하얀색 아이템 드랍 50%
				}
				else if (itemTier < 95) 
				{
					//파란색 아이템 드랍 45%
				}

				else
				{
					//보라색 아이템 드랍 5%
				}
			}
		}
	}

	if (p_LUK > 20)
	{
		int DropChance = rand() % 100;

		if (DropChance < 80) 
		{
			int itemTier = rand() % 100;

			if (itemTier < 20)
			{
				//하얀색 아이템 드랍 50%
			}

			else if (itemTier < 65)
			{
				//파란색 아이템 드랍 45%
			}
			else
			{
				//보라색 아이템 드랍 5%
			}
		}
	}

}*/