#pragma once
#include <iostream>
#include <string>
#include <algorithm>
//#include "Inventory.h"
//#include "Item.h"

class Monster; // 몬스터 전방선언

class Player
{
private:
    std::string Name;
    int Level;
    int HP;
    int MaxHp;
    int ATK;
    int EXP;
    int LUCK;
    int GOLD = 0;
    const int MaxExp = 100;
    bool isDead = 0;

    // Inventory<Item*> myInventory; // 인벤토리 (인벤토리 헤더 필요)

    void CheckDeath(); // 사망여부 확인

public:
    Player(std::string name = "가오나시");	// Player 초기 이름인 가오나시로 생성

    ~Player();                  // 소멸

    // Getter
    std::string GetName() const;
    int GetLevel() const;
    int GetHP() const;
    int GetMaxHp() const;
    int GetAtk() const;
    int GetLuck() const;
    bool GetisDead() const;
    // Inventory<Item*>& GetInventory() { return myInventory; } (인벤토리 헤더 필요)

// Setter
    void SetName(const std::string& newName);
    void SetLevel(unsigned int newLevel);
    void SetHP(int newHP);
    void SetMaxHp(int newMaxHp);
    void SetAtk(int newAtk);
    void SetLuck(int newLuck);
    void SetisDead(bool dead);


    // 주요 기능들

    //상태 확인
    void ShowStatus() const;
    //포식 함수 정의
    void SkillPredation(Monster* target);

    // 자동 회복 체크 함수 (인벤토리 헤더 필요)
    // void CheckAutoHeal();

    void Attack(Monster* target);
    void TakeDamage(int damage);
    void HealHp(int Hpamount);
    void AddAtk(int Atkamount) { ATK += Atkamount; }
};
