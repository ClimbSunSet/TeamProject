//Monster.h

#pragma once
#include <string>

using namespace std;

/*enum class State : uint8_t
{
	alive
	dead
}; */

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
	bool isDead() const;
	//void SetDead() const;

};

