//Monster.h

#pragma once
#include "Rewardinfo.h"
#include <string>

using namespace std;

/*enum class State : uint8_t
{
	alive
	dead
}; */

class Player;

class Monster
{
private:
	string Name;
	int Level; //레벨
	int HP; //현재HP
	int ATK; //공격력
	int MaxHP; //몬스터의 최대 HP를 따로 저장용
	

public:
	// 생성자
	Monster(string name, int playerlevel);
	Monster();

	virtual ~Monster() {} //소멸자 구현
	virtual void Attack() = 0; //클래스마다 하기

	void Firstspeech() const;
	void TakeDamage(int damage);
	bool isDead() const;
	const Rewardinfo& Dropitem() const;

	//Getter 추가
	string GetName() const { return Name; }
	int GetLevel() const { return Level; }
	int GetHP() const { return HP; }
	int GetATK() const { return ATK; }
	int GetMaxHP() const { return MaxHP; }

	Rewardinfo Reward;
	
	//void Dropitem(const Player & player) const; //플레이어 LUK수치가 있을 때
	//void SetDead() const;

};

