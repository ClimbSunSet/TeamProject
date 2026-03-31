#include "Player.h"
#include "Monster.h"
#include <iostream>

//생성자.
Player::Player(std::string name)
    : Name(name), Level(1), HP(200), MaxHP(200), ATK(30), EXP(0), LUK(10), GOLD(0)
{

}

Player::Player()
    : Name(), Level(1), HP(200), MaxHP(200), ATK(30), EXP(0), LUK(10), GOLD(0)
{

}

//getter
std::string Player::GetName() const
{
	return Name;
}

int Player::GetLevel() const
{
	return Level;
}

int Player::GetHP() const
{
	return HP;
}

int Player::GetMaxHP() const
{
	return MaxHP;
}

int Player::GetEXP() const
{
	return EXP;
}

int Player::GetATK() const
{
	return ATK;
}

int Player::GetLUK() const
{
	return LUK;
}

int Player::GetGOLD() const
{
	return GOLD;
}

bool Player::GetIsDead() const
{
	return isDead;
}

bool Player::GetIsAttackBuffActive() const
{
	return isAttackBuffActive;
}

std::vector<Item*> Player::GetInventory()
{
	return inventory;
}

std::vector<Monster*> Player::GetPredatedMonsters()
{
	return predatedMonsters;
}
//setter	
void Player::SetName(std::string newName)
{
	Name = newName;
}

void Player::SetLevel(int newLevel)
{
	Level = newLevel;
}

void Player::SetHP(int newHP)
{
	HP = newHP;
}

void Player::SetMaxHP(int newMaxHP)
{
	MaxHP = newMaxHP;
}

void Player::SetATK(int newATK)
{
	ATK = newATK;
}

void Player::SetEXP(int newEXP)
{
	EXP = newEXP;
}

void Player::SetLUK(int newLUK)
{
	LUK = newLUK;
}

void Player::SetGOLD(int newGOLD)
{
	GOLD = newGOLD;
}

void Player::SetIsAttackBuffActive(bool value)
{
	isAttackBuffActive = value;
}

void Player::AddItem(Item* item)
{
	inventory.push_back(item);
}

// 플레이어가 가질 행동.
void Player::Attack() // 공격함수 출력만 함.
{
	std::cout << "캐릭터가 공격했습니다" << std::endl;
	std::cout << ATK << "만큼의 피해를 입힙니다!" << std::endl;
}

void Player::TakeDamage(int Damage) // 맞은 놈이 HP 연산 처리함.
{
	HP -= Damage;

	if (HP <= 0)
	{
		HP = 0;
	}

	std::cout << "캐릭터가 " << Damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << std::endl;

	SetDead();
}

void Player::SetDead() // 지가 맞고 죽었는지 아닌지 판단함.
{
	if (HP <= 0)
	{
		isDead = true;
	}

	if (isDead == 1)
	{
		std::cout << "캐릭터가 사망했습니다!" << std::endl;
	}
}

void Player::SkillPredation(Monster* monster)
{
	int chance = rand() % 100;
	if (chance < (50 + LUK))
	{
		std::cout << "대상을 포식합니다!" << std::endl;
		predatedMonsters.push_back(monster);
	}

	else
	{
		std::cout << "포식에 실패했습니다!" << std::endl;
	}
}

void Player::SkillDigestion()
{
	int addHP = 0;
	int addATK = 0;
	int TotalHP = 0;
	int TotalATK = 0;


	int chance = rand() % 100;
	if (chance < (50 + LUK))
	{
		std::cout << "소화에 성공했습니다!" << std::endl;

		for (int i = 0; i < predatedMonsters.size(); ++i)
		{
			addHP += predatedMonsters[i]->GetMaxHP();
			addATK += predatedMonsters[i]->GetMaxATK();
		}

		int chance = rand() % 31 +20;

		TotalHP += (addHP * (chance/100.0));
		TotalATK += (addATK * (chance / 100.0));

		SetHP(GetHP() + TotalHP);
		SetATK(GetATK() + TotalATK);

		std::cout << "흡수한 스탯 " << std::endl;
		std::cout << "HP : " << TotalHP << std::endl;
		std::cout << "ATK : " << TotalATK << std::endl;

		for (int i = 0; i < predatedMonsters.size(); ++i)
		{
			delete predatedMonsters[i];
		}

		predatedMonsters.clear();
	}
	
	else
	{
		std::cout << "소화에 실패했습니다!" << std::endl;
	}
}

// 레벨관련
void Player::AddEXP(int amount)
{
	if (amount <= 0)
	{
		return;
	}

	if (Level < MinLevel)
	{
		Level = MinLevel;
	}

	if (Level >= MaxLevel)
	{
		return;
	}

	EXP += amount;
	std::cout << Name << " Get " << amount << " EXP\n" << std::endl;

	while (EXP >= MaxEXP && Level < MaxLevel)
	{
		LevelUp();
	}
}

void Player::LevelUp()
{
	EXP -= MaxEXP;
	Level++;

	if (Level < MinLevel)
	{
		Level = MinLevel;
	}

	if (Level > MaxLevel)
	{
		Level = MaxLevel;
	}


	MaxHP += Level * 20;
	ATK += Level * 5;
	LUK += 2;
	HP = MaxHP;
	MaxEXP += 50;

	std::cout << "Level UP! -> Lv." << Level << std::endl;
	std::cout << "MaxHP : " << MaxHP << " / ATK : " << ATK << std::endl;

	if (Level >= MaxLevel)
	{
		Level = MaxLevel;
		EXP = 0;
		std::cout << "Max Level!" << std::endl;
	}
}
