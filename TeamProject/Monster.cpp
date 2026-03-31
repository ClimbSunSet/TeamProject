// Monster.cpp

#include "Monster.h"

Monster::Monster(int level, std::string name)
	: Name(name)
{
	int MonMaxHP = (level * 30);
	int MonMinHP = (level * 20);
	int totalMonHP = rand() % (MonMaxHP - MonMinHP + 1) + MonMinHP;
	MaxHP = totalMonHP;

	SetHP(totalMonHP);

	int MonMaxATK = (level * 10);
	int MonMinATK = (level * 5);
	int totalMonATK = rand() % (MonMaxATK - MonMinATK + 1) + MonMinATK;

	MaxATK = totalMonATK;

	SetATK(totalMonATK);
}

void Monster::TakeDamage(int Damage) // 맞은 놈이 HP 연산 처리함.
{
	HP -= Damage;

	if (HP <= 0)
	{
		HP = 0;
	}

	std::cout << GetName() << "이(가) " << Damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << std::endl;

	SetDead();
}

void Monster::SetDead() // 지가 맞고 죽었는지 아닌지 판단함.
{
	if (HP <= 0)
	{
		isDead = 1;
	}

	if (isDead == 1)
	{
		std::cout << GetName() << "이(가) 사망했습니다!" << std::endl;
	}
}

// Getter
std::string Monster::GetName() const
{
	return Name;
}

int Monster::GetHP() const
{
	return HP;
}

int Monster::GetATK() const
{
	return ATK;
}

bool Monster::GetisDead() const
{
	return isDead;
}

int Monster::GetMaxHP() const
{
	return MaxHP;
}

int Monster::GetMaxATK() const
{
	return MaxATK;
}

// Setter
void Monster::SetName(std::string NewName)
{
	Name = NewName;
}

void Monster::SetHP(int NewHP)
{
	HP = NewHP;
}

void Monster::SetATK(int NewATK)
{
	ATK = NewATK;
}

void Monster::SetisDead(bool NewisDead)
{
	isDead = NewisDead;
}

void Monster::SetMaxHP(int newMaxHP)
{
	MaxHP = newMaxHP;
}