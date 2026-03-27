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
	string name;
	int Level; //레벨
	int HP; //현재HP
	int ATK; //공격력
	int MaxHP; //몬스터의 최대 HP를 따로 저장용
	

public:
	// 생성자
	Monster(string name, int playerlevel);
	Monster();

	void Firstspeech() const;
	void TakeDamage(int damage);
	void Attack() const;
	bool isDead() const;
	const Rewardinfo& Dropitem() const;

	//Getter 추가
	string GetName() const { return name; }
	int GetHP() const { return HP; }
	int GetATK() const { return ATK; }
	int GetMaxHP() const { return MaxHP; }

	Rewardinfo Reward;
	
	//void Dropitem(const Player & player) const; //플레이어 LUK수치가 있을 때
	//void SetDead() const;

};

