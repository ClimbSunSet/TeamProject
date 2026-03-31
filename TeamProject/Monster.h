// Monster.h

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "UISystem.h" // UISystem 사용을 위해 추가 (김준태)

class Monster
{
public:
    Monster(int level, std::string name);
    virtual ~Monster() {};

    virtual void Attack() = 0;
    void TakeDamage(int Damage, UISystem& UI, int& line); // UI 인자 추가 (김준태)
    void SetDead(UISystem& UI, int& line); // UI 인자 추가 (김준태)

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
