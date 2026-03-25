//Monster.cpp

#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Monster::Monster(string name, int playerlevel)
{
	name = name;
	Level = playerlevel;
	//체력
		int minHP = Level * 20;
		int maxHP = Level * 30;
	HP = rand() % (maxHP - minHP + 1) + minHP;
	MaxHP = HP;


	//공격력
	int minATK = Level * 5;
	int maxATK = Level * 10;
	ATK = rand() % (maxATK - minATK + 1) + minATK;
	
}

//등장출력
void Monster::Firstspeech() const
{
	std::cout << name << "이(가) 등장했다 ! "<< std::endl;
	
}
void Monster::Attack() const
{

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

