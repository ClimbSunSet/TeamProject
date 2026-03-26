#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class Player
{
private:
	std::string Name;
	int Level;
	int Hp;
	int MaxHp;
	int ATK;
	int EXP;
	// int LUCK; 
	int GOLD = 0;				// 골드 변수명 조율 해야함
	const int MaxExp = 100;		// 최대 Exp 100으로 고정


public:
	Player(std::string name);	// Player 생성: 이름 설정 및 초기화

	~Player(); // 소멸

	void ShowStatus() const;	// 상태 확인

	//GetSet
	//int GetGold() const { return GOLD; }
	//void SetGold(int newGold) { Gold = newGOLD; }

	std::string GetName() const { return Name; }
	int GetLevel() const { return Level; }
	int GetHP() const { return Hp; }
	int GetAtk() const { return ATK; }
	int GetGold() const { return GOLD; }

	// [전투 시스템] 데미지 입음
	void TakeDamage(int damage)
	{
		Hp = std::max(0, Hp - damage);
	}

	// [전투 시스템] 골드 획득 
	// ex) player.AddGold(monster.DropGold(100));
	void AddGold(int Gamount)
	{
		GOLD += Gamount;
		std::cout << Gamount << " 골드를 획득했습니다! (현재: " << GOLD << "G)" << std::endl;
	}

	// [전투 시스템] 경험치 획득
	// ex) player.GainExp(50);
	void GainExp(int exp);

	// [아이템] 체력 회복
	// ex) player.HealHp(50);
	void HealHp(int Hpamount)
	{
		Hp = std::min(MaxHp, Hp + Hpamount);
	}

	// [아이템 및 레벨업] 공격력 증가
	// ex) player.AddAtk(10);
	void AddAtk(int Atkamount) { ATK += Atkamount; }
};