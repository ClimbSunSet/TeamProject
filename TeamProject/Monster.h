//Monster.h

#pragma once
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
	int MaxHP; //최대HP
	int ATK; //공격력

public:
	// 생성자
	Monster(string name, int playerlevel);

	void Firstspeech() const;
	void TakeDamage(int damage);
	void Attack() const;
	void Dropitem() const;
	bool isDead() const;
	//void Dropitem(const Player & player) const; //플레이어 LUK수치가 있을 때
	//void SetDead() const;

};

