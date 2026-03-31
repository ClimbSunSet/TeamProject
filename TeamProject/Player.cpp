#include "Player.h"
#include "Monster.h"
#include "UISystem.h" // 헤더 추가 (김준태)
#include <iostream>

//생성자.
Player::Player(std::string name)
    : Name(name), Level(1), HP(200), MaxHP(200), ATK(30), EXP(0), LUK(10), GOLD(0)
{

}

Player::Player()
    : Name(), Level(1), HP(200), MaxHP(200), ATK(30), EXP(0), LUK(10), GOLD(0)
{

}

// 오른쪽 하단 박스 비우기 (김준태)
void ClearRightBox(UISystem& UI)
{
    for (int i = 0; i < 6; ++i)
    {
        UI.SetCursor(35, 23 + i);
        std::cout << "                                          "; // 박스 폭만큼 공백
    }
}

//getter
std::string Player::GetName() const
{
	return Name;
}

int Player::GetLevel() const
{
	return Level;
}

int Player::GetHP() const
{
	return HP;
}

int Player::GetMaxHP() const
{
	return MaxHP;
}

int Player::GetEXP() const
{
	return EXP;
}

int Player::GetATK() const
{
	return ATK;
}

int Player::GetLUK() const
{
	return LUK;
}

int Player::GetGOLD() const
{
	return GOLD;
}

bool Player::GetIsDead() const
{
	return isDead;
}

bool Player::GetIsAttackBuffActive() const
{
	return isAttackBuffActive;
}

std::vector<Item*> Player::GetInventory()
{
	return inventory;
}

std::vector<Monster*> Player::GetPredatedMonsters()
{
	return predatedMonsters;
}
//setter	
void Player::SetName(std::string newName)
{
	Name = newName;
}

void Player::SetLevel(int newLevel)
{
	Level = newLevel;
}

void Player::SetHP(int newHP)
{
	HP = newHP;
}

void Player::SetMaxHP(int newMaxHP)
{
	MaxHP = newMaxHP;
}

void Player::SetATK(int newATK)
{
	ATK = newATK;
}

void Player::SetEXP(int newEXP)
{
	EXP = newEXP;
}

void Player::SetLUK(int newLUK)
{
	LUK = newLUK;
}

void Player::SetGOLD(int newGOLD)
{
	GOLD = newGOLD;
}

void Player::SetIsAttackBuffActive(bool value)
{
	isAttackBuffActive = value;
}

void Player::AddItem(Item* item)
{
	inventory.push_back(item);
}


// ----------------------------- [공통] 함수 괄호에 (UISystem& UI)추가했음 (김준태) -----------------------------
// 오류시 헤더랑 구현부에있는 함수 UISystem& UI 괄호안에 삭제

// 플레이어가 가질 행동.
void Player::Attack(UISystem& UI) // 공격함수 출력만 함.
{
	/*std::cout << "캐릭터가 공격했습니다" << std::endl;
	std::cout << ATK << "만큼의 피해를 입힙니다!" << std::endl;*/
    ClearRightBox(UI);
    UI.SetCursor(35, 22); std::cout << " [ 전투 행동 ]";
    UI.SetCursor(35, 23); std::cout << " >> " << Name << "의 공격!";
    UI.SetCursor(35, 24); std::cout << " >> " << ATK << "의 데미지 부여!";
    Sleep(1000);
}

void Player::TakeDamage(int damage, UISystem& UI) // 맞은 놈이 HP 연산 처리함.
{
    ClearRightBox(UI);
	HP -= damage;

	if (HP <= 0)
	{
		HP = 0;
	}

	/*std::cout << "캐릭터가 " << damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << std::endl;*/
    UI.SetCursor(35, 24); std::cout << "- " << damage << " HP 피해 발생!          ";
    UI.SetCursor(35, 25); std::cout << ">> 남은 HP: " << HP << "             ";

	SetDead(UI); // 괄호에 UI 추가 (김준태)
    Sleep(1000); // Sleep(1000); 추가 (김준태)
}

void Player::SetDead(UISystem& UI) // 지가 맞고 죽었는지 아닌지 판단함.
{
	if (HP <= 0)
	{
		isDead = true;
	}

	if (isDead == 1)
	{
		/*std::cout << "캐릭터가 사망했습니다!" << std::endl;*/
        UI.SetCursor(35, 26); std::cout << "캐릭터가 사망했습니다!        ";
        Sleep(1000); // Sleep(1000); 추가 (김준태)
	}
}

void Player::SkillPredation(Monster* monster, UISystem& UI, int& line)
{
	int chance = rand() % 100;
	if (chance < (50 + LUK))
	{
		/*std::cout << "대상을 포식합니다!" << std::endl;*/
        UI.PrintMessage(">> 대상을 포식합니다!", line++);
        Sleep(1000); // Sleep(1000); 추가 (김준태)
		predatedMonsters.push_back(monster);
	}

	else
	{
        /*std::cout << "포식에 실패했습니다!" << std::endl;*/
        UI.PrintMessage(">> 포식에 실패했습니다!", line++);
        Sleep(1000); // Sleep(1000); 추가 (김준태)
	}
}

void Player::SkillDigestion(UISystem& UI)
{
	int addHP = 0;
	int addATK = 0;
	int TotalHP = 0;
	int TotalATK = 0;


	int chance = rand() % 100;
	if (chance < (50 + LUK))
	{
		/*std::cout << "소화에 성공했습니다!" << std::endl;*/
        UI.SetCursor(35, 23); std::cout << "소화에 성공했습니다!          ";
        Sleep(1000); // Sleep(1000); 추가 (김준태)

		for (int i = 0; i < predatedMonsters.size(); ++i)
		{
			addHP += predatedMonsters[i]->GetMaxHP();
			addATK += predatedMonsters[i]->GetMaxATK();
		}

		int chance = rand() % 31 +20;

		TotalHP += (addHP * (chance/100.0));
		TotalATK += (addATK * (chance / 100.0));

        SetMaxHP(GetMaxHP() + TotalHP);
		SetHP(GetHP() + TotalHP);
		SetATK(GetATK() + TotalATK);

		//std::cout << "흡수한 스탯 " << std::endl;
		//std::cout << "HP : " << TotalHP << std::endl;
		//std::cout << "ATK : " << TotalATK << std::endl;
        UI.SetCursor(35, 24); std::cout << "[ 흡수한 스탯 ]               ";
        Sleep(1000); // Sleep(1000); 추가 (김준태)
        UI.SetCursor(35, 25); std::cout << "HP : " << TotalHP << " / ATK : " << TotalATK << "      ";
        Sleep(1000); // Sleep(1000); 추가 (김준태)

		for (int i = 0; i < predatedMonsters.size(); ++i)
		{
			delete predatedMonsters[i];
		}

		predatedMonsters.clear();
	}
	
	else
	{
		/*std::cout << "소화에 실패했습니다!" << std::endl;*/
        UI.SetCursor(35, 23); std::cout << "소화에 실패했습니다!          ";
        Sleep(1000); // Sleep(1000); 추가 (김준태)
	}
}

// 레벨관련
void Player::AddEXP(int amount, UISystem& UI)
{
	if (amount <= 0)
	{
		return;
	}

	if (Level < MinLevel)
	{
		Level = MinLevel;
	}

	if (Level >= MaxLevel)
	{
		return;
	}

	EXP += amount;
	/*std::cout << Name << " Get " << amount << " EXP\n" << std::endl;*/
    UI.SetCursor(35, 26); std::cout << Name << " Get " << amount << " EXP          ";
    Sleep(1000); // Sleep(1000); 추가 (김준태)

	while (EXP >= MaxEXP && Level < MaxLevel)
	{
		LevelUp(UI); // UI추가 (김준태)
	}
}

void Player::LevelUp(UISystem& UI)
{
	EXP -= MaxEXP;
	Level++;

	if (Level < MinLevel)
	{
		Level = MinLevel;
	}

	if (Level > MaxLevel)
	{
		Level = MaxLevel;
	}


	MaxHP += Level * 20;
	ATK += Level * 5;
	LUK += 2;
	HP = MaxHP;
	MaxEXP += 50;

	//std::cout << "Level UP! -> Lv." << Level << std::endl;
	//std::cout << "MaxHP : " << MaxHP << " / ATK : " << ATK << std::endl;
    UI.SetCursor(35, 27); std::cout << "Level UP! -> Lv." << Level << "         ";
    Sleep(1000); // Sleep(1000); 추가 (김준태)
    UI.SetCursor(35, 28); std::cout << "MaxHP : " << MaxHP << " / ATK : " << ATK << "    ";
    Sleep(1000); // Sleep(1000); 추가 (김준태)

	if (Level >= MaxLevel)
	{
		Level = MaxLevel;
		EXP = 0;
		/*std::cout << "Max Level!" << std::endl;*/
        UI.SetCursor(35, 29); std::cout << "Max Level!                    ";
        Sleep(1000); // Sleep(1000); 추가 (김준태)
	}
}
