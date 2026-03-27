#include "Player.h"
#include <iostream>

// 초기 스탯
Player::Player(std::string name)
    : Name(name), Level(1), HP(200), MaxHp(200), ATK(30), EXP(0), LUCK(10), GOLD(0)
{
    // [안전장치]
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
    std::cout << "\n========== 캐릭터 상태 ==========" << std::endl;
    std::cout << " 이름   : " << Name << std::endl;
    std::cout << " 레벨   : " << Level << std::endl;
    std::cout << " 체력   : " << HP << " / " << MaxHp << std::endl;
    std::cout << " 공격력 : " << ATK << std::endl;
    std::cout << " 경험치 : " << EXP << " / " << MaxExp << std::endl;
    std::cout << " 행운 : " << LUCK << std::endl;
    std::cout << " 골드   : " << GOLD << " G" << std::endl;
    std::cout << "=================================\n" << std::endl;
}
