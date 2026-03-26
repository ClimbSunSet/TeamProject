#include "Player.h"
#include <iostream>

// 초기 스탯
Player::Player(std::string name)
    : Name(name), Level(1), Hp(200), MaxHp(200), ATK(30), EXP(0)
{
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

//void Player::GainExp(int exp) {
//    // 1. 경험치 추가
//    EXP += exp;
//    std::cout << "\n[EXP] " << exp << "의 경험치를 획득했습니다. (현재: " << EXP << "/" << MaxExp << ")" << std::endl;
//
//    // 2. 레벨업 로직 경험치가 MaxExp 이상이고, 레벨이 10 미만일 때 반복
//    while (EXP >= MaxExp && Level < 10) {
//        EXP -= MaxExp; // 경험치 소모
//        Level++;       // 레벨업
//
//        // 체크리스트 규칙 적용
//        MaxHp += (Level * 20); // 레벨당 20씩 최대 체력 증가
//        ATK += (Level * 5);    // 레벨당 5씩 공격력 증가
//        Hp = MaxHp;           // 체력 풀 회복
//
//        std::cout << "\n================================" << std::endl;
//        std::cout << " 축하합니다! 레벨 " << Level << "이 되었습니다! " << std::endl;
//        std::cout << "스탯 상승: MaxHP +" << (Level * 20) << " / ATK +" << (Level * 5) << std::endl;
//        std::cout << "================================\n" << std::endl;
//    }
//
//    // 만약 만렙이라면
//    if (Level >= 10) {
//        EXP = 0; // 더 이상 경험치가 쌓이지 않게 처리
//    }
//}