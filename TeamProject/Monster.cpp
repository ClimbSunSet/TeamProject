// Monster.cpp

#include "Monster.h"

Monster::Monster(int level, std::string name)
    : Name(name)
{
    int MonMaxHP = (level * 30);
    int MonMinHP = (level * 20);
    int totalMonHP = rand() % (MonMaxHP - MonMinHP + 1) + MonMinHP;
    MaxHP = totalMonHP;

    SetHP(totalMonHP);

    int MonMaxATK = (level * 10);
    int MonMinATK = (level * 5);
    int totalMonATK = rand() % (MonMaxATK - MonMinATK + 1) + MonMinATK;

    MaxATK = totalMonATK;

    SetATK(totalMonATK);
}

void Monster::TakeDamage(int Damage, UISystem& UI, int& line) // UISystem& UI 추가 (김준태)
{
    HP -= Damage;

    if (HP <= 0)
    {
        HP = 0;
    }

    /*std::cout << GetName() << "이(가) " << Damage << "만큼 피해를 입어 HP가 " << HP << "만큼 남았습니다" << std::endl;*/
    // UI 메시지로 변경 (김준태)
    std::string damageMsg = GetName() + "이(가) " + std::to_string(Damage) + "의 피해! (남은 HP: " + std::to_string(HP) + ")";
    UI.PrintMessage(damageMsg, line++); // 5번 라인 근처에 출력 (김준태)

    SetDead(UI, line); // UI 전달 (김준태)
}

void Monster::SetDead(UISystem& UI, int& line) // UISystem& UI, int& line 추가 (김준태)
{
    if (HP <= 0)
    {
        isDead = 1;
    }

    if (isDead == 1)
    {
        /*std::cout << GetName() << "이(가) 사망했습니다!" << std::endl;*/
        UI.PrintMessage(GetName() + "이(가) 사망했습니다!", line++); // UI 메시지로 변경 (김준태)
    }
}

// Getter
std::string Monster::GetName() const
{
    return Name;
}

int Monster::GetHP() const
{
    return HP;
}

int Monster::GetATK() const
{
    return ATK;
}

bool Monster::GetisDead() const
{
    return isDead;
}

int Monster::GetMaxHP() const
{
    return MaxHP;
}

int Monster::GetMaxATK() const
{
    return MaxATK;
}

// Setter
void Monster::SetName(std::string NewName)
{
    Name = NewName;
}

void Monster::SetHP(int NewHP)
{
    HP = NewHP;
}

void Monster::SetATK(int NewATK)
{
    ATK = NewATK;
}

void Monster::SetisDead(bool NewisDead)
{
    isDead = NewisDead;
}

void Monster::SetMaxHP(int newMaxHP)
{
    MaxHP = newMaxHP;
}
