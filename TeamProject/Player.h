#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Inventory.h"
#include "Item.h"

class Monster; // 몬스터 전방선언
class Item;

class Player
{
private:
    std::string Name;
    int Level;
    int HP;
    int MaxHP;
    int ATK;
    int EXP;
    int LUK;
    int GOLD = 0;
    const int MaxEXP = 100;
    bool isDead = 0;

    Inventory myInventory;

    void SetDead(); // 사망여부 확인

public:
    Player(std::string name = "가오나시");	// Player 초기 이름인 가오나시로 생성

    ~Player();                  // 소멸

    // Getter
    std::string GetName() const;
    int GetLevel() const;
    int GetHP() const;
    int GetMaxHP() const;
    int GetATK() const;
    int GetLuk() const;
    bool GetisDead() const;
    Inventory& GetInventory() { return myInventory; }

    // Setter
    void SetName(const std::string& newName);
    void SetLevel(unsigned int newLevel);
    void SetHP(int newHP);
    void SetMaxHP(int newMaxHP);
    void SetATK(int newAtk);
    void SetLuk(int newLuk);
    void SetisDead(bool dead);


    // 주요 기능들

    // 상태 확인
    void ShowStatus() const;

    // 포식 스킬 함수 정의
    void SkillPredation(Monster* target);

    // 소화 스킬 함수 정의
    void SkillDigestion(Item* targetItem);

    // 자동 회복 체크 함수
    void CheckAutoHeal();

    void Attack(Monster* target);
    void TakeDamage(int damage);
    void HealHP(int Hpamount);
    void AddAtk(int Atkamount) { ATK += Atkamount; }
};
