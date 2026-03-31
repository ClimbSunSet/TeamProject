// Monster.h

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

class Monster
{
public:
	Monster(int level, std::string name);
	virtual ~Monster() {};

	virtual void Attack() = 0;
	void TakeDamage(int Damage);
	void SetDead();

	std::string GetName() const;
	int GetHP() const;
	int GetATK() const;
	bool GetisDead() const;
	int GetMaxHP() const;
	int GetMaxATK() const;

	void SetName(std::string NewName);
	void SetHP(int NewHP);
	void SetATK(int NewATK);
	void SetisDead(bool NewisDead);
	void SetMaxHP(int newMaxHP);

	bool isPredated = false;

private:
	std::string Name;
	int HP;
	int MaxHP;
	int ATK;
	int MaxATK = ATK;
	bool isDead = false;
	std::string DropItem;
};

