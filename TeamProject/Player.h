#pragma once
#include <string>

class Player
{
private:
	std::string Name;
	int Level;
	int Hp;
	int MaxHp;
	int ATK;
	int EXP;
	const int MaxExp = 100;


public:
	Player(std::string name);	// Player 생성: 이름 설정 및 초기화

	~Player(); // 소멸

	void ShowStatus() const;	// 상태 확인

	std::string GetName() const { return Name; }
	int GetLevel() const { return Level; }
	int GetHP() const { return Hp; }
	int GetAtk() const { return ATK; }
	void TakeDamage(int damage) { Hp -= damage; }
};