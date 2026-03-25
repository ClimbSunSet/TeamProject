// Main.cpp

#include <iostream>
using namespace std;


class Character
{
public:
	int Level = 1;
	int HP = 200;
	int ATK = 30;
	int EXP = 0;
	bool isDead = 1;

	void attack() // 공격함수 출력만 함.
	{
		cout << "캐릭터가 공격했습니다" << endl;
		cout << ATK << "만큼의 피해를 입힙니다!" << endl;
	}

	void takedamage(int Damage) // 맞은 놈이 HP 연산 처리함.
	{
		HP -= Damage;

		if (HP <= 0)
		{
			HP = 0;
		}

		cout << Damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << endl;
	}

	void SetDead() // 지가 맞고 죽었는지 아닌지 판단함.
	{
		if (HP >= 0)
		{
			isDead = 0;
			cout << "캐릭터가 사망했습니다!" << endl;
		}
	}
};

class  Monster
{
public:

	int HP = 20;
	int ATK = 3;
	bool isDead = 1;

	void attack() // 공격함수 출력만 함.
	{
		cout << "슬라임이 공격했습니다" << endl;
		cout << ATK << "만큼의 피해를 입힙니다!" << endl;
	}

	void takedamage(int Damage) // 맞은 놈이 HP 연산 처리함.
	{
		HP -= Damage;

		if (HP <= 0)
		{
			HP = 0;
		}

		cout << Damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << endl;
	}

	void SetDead()
	{
		if (HP >= 0)
		{
			isDead = 0;
			cout << "슬라임이 사망했습니다!" << endl;
		}
	}
};

int main(void)
{
	Character player1;
	Monster Slime;
	cout << "캐릭터와 슬라임이 생성 되었습니다!" << endl;
	cout << "슬라임과 전투에 돌입합니다." << endl;

	while (player1.HP > 0 && Slime.HP > 0)
	{
		player1.attack(); // 플레이어 먼저 행동.
		Slime.takedamage(player1.ATK);
		Slime.SetDead();

		if (Slime.isDead == true) // 슬라임이 살아있다면 계속 전투 
		{
			Slime.attack();
			player1.takedamage(Slime.ATK);
		}

		else // 슬라임이 죽었다면 반복문 탈출.
		{
			break;
		}
	}

	return 0;
}