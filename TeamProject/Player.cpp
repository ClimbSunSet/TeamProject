#include "Player.h"
#include <iostream>

// 초기 스탯
Player::Player(std::string name)
    : Name(name), Level(1), Hp(200), MaxHp(200), ATK(30), EXP(0)
{
    // [안전장치] Level 잘못 들어와도 생성시 1로 고정
    if (Level < 1)
    {
        Level = 1;
    }

    std::cout << "\n주인공: '" << Name << "'이(가) 생성 완료되었습니다.\n" << std::endl;
}

// 소멸
Player::~Player()
{
    std::cout << " 사망 " << Name << "' 캐릭터 HP가 0이되어 소멸됩니다." << std::endl;
}

// 캐릭터 상태
void Player::ShowStatus() const
{
    std::cout << "========== 캐릭터 상태 ==========" << std::endl;
    std::cout << " 이름   : " << Name << std::endl;
    std::cout << " 레벨   : " << Level << std::endl;
    std::cout << " 체력   : " << Hp << " / " << MaxHp << std::endl;
    std::cout << " 공격력 : " << ATK << std::endl;
    std::cout << " 경험치 : " << EXP << " / " << MaxExp << std::endl;
    std::cout << "=================================" << std::endl;
}

// Level test
//void Player::GainExp(int exp)
//{
//    // [안전 장치] 음수 경험치가 들어오는 것을 방지
//    if (exp <= 0) return;
//
//    // 1. 만렙 체크: 이미 만렙이면 경험치를 쌓지 않음
//    if (Level >= 10)
//    {
//        std::cout << "[MAX] 이미 최대 레벨(10)입니다." << std::endl;
//        return;
//    }
//
//    // 2. 경험치 추가
//    EXP += exp;
//    std::cout << "\n[EXP] " << exp << "의 경험치를 획득했습니다. (현재: " << EXP << "/" << MaxExp << ")" << std::endl;
//
//    // 3. 레벨업 로직 경험치가 MaxExp 이상이고, 레벨이 10 미만일 때 반복
//    while (EXP >= MaxExp && Level < 10)
//    {
//        EXP -= MaxExp; // 경험치 소모
//        Level++;       // 레벨업
//
//        // 레벨이 오를 때마다 최대 체력과 공격력 상승
//        int hpBonus = Level * 20;
//        int atkBonus = Level * 5;
//
//        MaxHp += hpBonus; 
//        ATK += atkBonus;   
//        Hp = MaxHp; // 체력 풀 회복
//
//        std::cout << "\n========================================" << std::endl;
//        std::cout << " 레벨업!! 레벨 " << Level << "이 되었습니다!" << std::endl;
//        ShowStatus();
//
//        // 레벨업 직후 만렙이 되었다면 경험치 초기화 후 루프 탈출
//        if (Level >= 10)
//        {
//            EXP = 0;
//            std::cout << "최대 레벨에 도달하여 경험치가 오르지않습니다." << std::endl;
//            break; 
//        }
//    }
//}
