#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Item.h"

class Monster;
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
    bool isDead = false;
    bool isAttackBuffActive;
    std::vector<Monster*> predatedMonsters;
    std::vector<Item*> inventory;

    int MaxEXP = 100;		// 최대 Exp 100으로 고정
    int MaxLevel = 10;
    int MinLevel = 1;

public:
    Player(std::string name);

    Player(); // GameSystem이 사용할 생성자임.

    // Getter
    std::string GetName() const;
    int GetLevel() const;
    int GetHP() const;
    int GetMaxHP() const;
    int GetATK() const;
    int GetEXP() const;
    int GetLUK() const;
    int GetGOLD() const;
    bool GetIsDead() const;
    bool GetIsAttackBuffActive() const;
    std::vector<Item*> GetInventory();
    std::vector<Monster*> GetPredatedMonsters();

    // Setter
    void SetName(std::string newName);
    void SetLevel(int newLevel);
    void SetHP(int newHP);
    void SetMaxHP(int newMaxHP);
    void SetATK(int newATK);
    void SetEXP(int newEXP);
    void SetLUK(int newLUK);
    void SetGOLD(int newGOLD);
    void SetIsAttackBuffActive(bool value);

    void AddEXP(int amount);
    void LevelUp();

    void AddItem(Item* item);

    void Attack();
    void TakeDamage(int damage);
    void SetDead();

    void SkillPredation(Monster* monster);
    void SkillDigestion();
};
