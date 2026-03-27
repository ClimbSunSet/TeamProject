#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class Player
{
private:
    std::string Name;
    unsigned int Level;
    int HP;
    int MaxHp;
    int ATK;
    int EXP;
    int LUCK;
    int GOLD = 0;
    bool isDead = 0;
    const int MaxExp = 100;		// 최대 Exp 100으로 고정

public:
    Player(std::string name);	// Player 생성: 이름 설정 및 초기화

    ~Player();                  // 소멸

    void ShowStatus() const;	// 상태 확인


    // Getter
    std::string GetName() const { return Name; }
    unsigned int GetLevel() const { return Level; }
    int GetHP() const { return HP; }
    int GetMaxHp() const { return MaxHp; }
    int GetAtk() const { return ATK; }
    int GetExp() const { return EXP; }
    int GetLuck() const { return LUCK; }
    int GetGold() const { return GOLD; }

    // Setter
    void SetName(const std::string& newName) { Name = newName; }
    void SetLevel(unsigned int newLevel) { Level = newLevel; }
    void SetHP(int newHP) { HP = newHP; }
    void SetMaxHp(int newMaxHp) { MaxHp = newMaxHp; }
    void SetAtk(int newAtk) { ATK = newAtk; }
    void SetExp(int newExp) { EXP = newExp; }
    void SetLuck(int newLuck) { LUCK = newLuck; }
    void SetGold(int newGold) { GOLD = newGold; }



    // [전투 시스템] 데미지 입음
    void TakeDamage(int damage)
    {
        HP = std::max(0, HP - damage);
    }

    void SetDead() // 지가 맞고 죽었는지 아닌지 판단함.
    {
        if (HP <= 0)
        {
            isDead = 1;
        }

        if (isDead == 1)
        {
            std::cout << "캐릭터가 사망했습니다!" << std::endl;
        }
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
    // void GainExp(int exp); // 경험치 테스트를 위한 함수

    // [아이템] 체력 회복
    // ex) player.HealHp(50);
    void HealHp(int Hpamount)
    {
        HP = std::min(MaxHp, HP + Hpamount);
    }

    // [아이템 및 레벨업] 공격력 증가
    // ex) player.AddAtk(10);
    void AddAtk(int Atkamount) { ATK += Atkamount; }
};
