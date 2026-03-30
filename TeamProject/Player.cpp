#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include <algorithm>
#include <iostream>
#include <string>

Player::Player(std::string name)
    : Name(name), Level(1), HP(200), MaxHP(200), ATK(30), EXP(0), LUK(5), GOLD(0), isDead(0)
{
    std::cout << "\n[시스템] 주인공: '" << Name << "' 생성 완료되었습니다.\n" << std::endl;
}

Player::~Player()
{
    if (isDead)
    {
        std::cout << "[시스템] 사망 " << Name << " 캐릭터 HP가 0이되어 소멸됩니다." << std::endl;
    }
}

// --- Getter 구현 ---
std::string Player::GetName() const { return Name; }
int Player::GetLevel() const { return Level; }
int Player::GetHP() const { return HP; }
int Player::GetMaxHP() const { return MaxHP; }
int Player::GetATK() const { return ATK; }
int Player::GetLuk() const { return LUK; }
bool Player::GetisDead() const { return isDead; }

// --- Setter 구현 ---
void Player::SetName(const std::string& newName) { Name = newName; }
void Player::SetLevel(unsigned int newLevel) { Level = newLevel; }
void Player::SetHP(int newHP)
{
    HP = std::max(0, std::min(MaxHP, newHP));
    if (HP <= 0) { SetDead(); }
}
void Player::SetMaxHP(int newMaxHP) { MaxHP = newMaxHP; }
void Player::SetATK(int newAtk) { ATK = newAtk; }
void Player::SetLuk(int newLuk) { LUK = newLuk; }
void Player::SetisDead(bool dead) { isDead = dead; }


void Player::ShowStatus() const
{
    std::cout << "========== 캐릭터 상태 ==========" << std::endl;
    std::cout << " 이름    : " << Name << std::endl;
    std::cout << " 레벨    : " << Level << std::endl;
    std::cout << " 체력    : " << HP << " / " << MaxHP << std::endl;
    std::cout << " 공격력  : " << ATK << std::endl;
    std::cout << " 행운    : " << LUK << std::endl;
    std::cout << " 경험치  : " << EXP << " / " << MaxEXP << std::endl;
    std::cout << " 보유골드 : " << GOLD << " G" << std::endl;
    std::cout << "=================================" << std::endl;
}

void Player::SetDead()
{
    // 이미 죽어있는 상태라면 중복 실행 방지
    if (isDead) { return; }

    // 체력이 0 이하가 되었을 때 처음 한 번만 실행
    if (HP <= 0)
    {
        HP = 0;
        isDead = 1; // 바로 죽음 상태로 변경 

        std::cout << "\n[시스템] " << Name << "이(가) 폭주하며 괴로워합니다! [HP: 0]" << std::endl;
        //std::cout << "========================================" << std::endl;

        //// --- 1단계: 가오나시 기본 형태 (가면과 큰 몸집) ---
        //std::cout << "      .-------.      " << std::endl;
        //std::cout << "     /   _ _   \\     " << std::endl;
        //std::cout << "    |   (o|o)   |    " << std::endl;
        //std::cout << "    |    ---    |    " << std::endl;
        //std::cout << "    /           \\    " << std::endl;
        //std::cout << "   /             \\   " << std::endl;
        //std::cout << "  (               )  " << std::endl;

        //// --- 2단계: 먹었던 것들을 토해냄 (우웁!) ---
        //std::cout << "\n    우우웁... 커헉! (구에에엑)" << std::endl;
        //std::cout << "      .-------.      " << std::endl;
        //std::cout << "     /   x x   \\     " << std::endl;
        //std::cout << "    |    ---    |    " << std::endl;
        //std::cout << "    /    | |    \\    " << std::endl;
        //std::cout << "   /   vvvvvvv   \\   " << std::endl;
        //std::cout << "  (    ........   )  " << std::endl;

        //// --- 3단계: 몸이 작아짐 (원래의 그림자 형태로) ---
        //std::cout << "\n    ... 슈우우우 ... (작아지는 중)" << std::endl;
        //std::cout << "       .---.         " << std::endl;
        //std::cout << "      ( o o )        " << std::endl;
        //std::cout << "       '---'         " << std::endl;
        //std::cout << "      /     \\        " << std::endl;

        //// --- 4단계: 완전히 사라짐 ---
        //std::cout << "\n       .  .  .       " << std::endl;
        //std::cout << "          .          " << std::endl;

        std::cout << "\n [" << Name << "]가 먼지가 되어 사라졌습니다." << std::endl;
        //std::cout << "========================================\n" << std::endl;
    }
}

void Player::CheckAutoHeal()
{
    if (isDead == 1 || HP > 50) return;

    std::cout << "\n 따흑... 아프다..." << std::endl;

    // 인벤토리 에서 자동으로 포션을 찾아 쓰기
    int healAmount = myInventory.UsePotionAuto();

    if (healAmount > 0)
    {
        HealHP(healAmount);
    }
    else
    {
        std::cout << " (인벤토리에 쓸 만한 물약이 없다...) " << std::endl;
    }
}

// 데미지 입는 로직
void Player::TakeDamage(int damage)
{
    if (isDead) { return; }
    HP = std::max(0, HP - damage);
    std::cout << Name << "이(가) " << damage << "의 데미지를 입었습니다.(현재: " << HP << ")" << std::endl;
    if (HP <= 0) { SetDead(); }
}


// 회복 로직
void Player::HealHP(int HPamount)
{
    if (isDead == 1)
    {
        std::cout << "사망한 상태에서는 회복할 수 없습니다." << std::endl;
        return;
    }
    HP = std::min(MaxHP, HP + HPamount);
    std::cout << "체력을 " << HPamount << "만큼 회복했습니다. (현재 체력: " << HP << ")" << std::endl;
}

// Attack함수
void Player::Attack(Monster* target)
{
    // [안전 장치] 내가 죽었거나 공격 대상이 없으면 중단
    if (isDead == 1 || target == nullptr) return;

    // 공격 메시지 출력
    std::cout << "\n" << Name << "이(가) " << target->GetName() << "을(를) 공격합니다!" << std::endl;

    // 몬스터에게 내 공격력만큼 데미지 입히기
    target->TakeDamage(ATK); // 상대방의 TakeDamage 함수에 내 ATK를 보냄

    // 공격 후 결과 출력
    std::cout << " -> " << target->GetName() << "에게 " << ATK << "의 피해를 주었습니다." << std::endl;
}


// 포식 스킬 로직
void Player::SkillPredation(Monster* target)
{
    if (isDead == 1 || target == nullptr) return;

    std::string mName = target->GetName();
    int mCurrentHP = target->GetHP();
    int mMaxHP = target->GetMaxHP();

    // 15% 미만이면서 살아있을 때만 처형 UI 출력
    bool isExecutable = (mCurrentHP > 0 && (mCurrentHP * 100 / mMaxHP) < 15);

    if (isExecutable == 1)
    {
        std::cout << "\n[ 가오나시의 눈이 붉게 일렁입니다... ]" << std::endl;
        std::cout << " ( " << mName << "은(는) 지쳐 있다... 지금이라면 먹을 수 있을 것 같다... )" << std::endl;
        std::cout << ">> [처형 표식 활성화] <<" << std::endl;
    }

    int successChance = 50 + LUK;
    int roll = rand() % 100;
    bool isSuccess = false;

    // 판정 로직
    if (mCurrentHP <= 0)
    {
        isSuccess = true;
        std::cout << "\n [시스템] " << mName << "의 시체에서 영혼을 추출합니다." << std::endl;
    }
    else if (isExecutable && roll < successChance)
    {
        isSuccess = true;
        target->TakeDamage(mCurrentHP); // 처형 피를 0으로 만듦
        std::cout << "\n [처형 성공] " << mName << "의 숨통을 끊고 영혼을 삼켰습니다!" << std::endl;
    }

    // 결과 처리
    if (isSuccess)
    {
        std::cout << "\n [포식 성공!] " << Name << "이(가) " << mName << "을(를) 통째로 삼켰습니다!" << std::endl;

        // 이름, 타입("2"), HP(0), MaxHP(0), ATK(0), 개수(1), 몬스터포인터(target)
        Item* monsterSoul = new Item(mName + "의 영혼", "2", 0, 0, 0, 1, target);

        myInventory.addItem(monsterSoul);

        std::cout << " [" << mName << "의 영혼]이 인벤토리에 보관되었습니다." << std::endl;
    }
    else
    {
        if (isExecutable == 1)
            std::cout << "\n [포식 실패] " << mName << "이(가) 거세게 저항하여 삼키지 못했습니다!" << std::endl;
        else
            std::cout << "\n [포식 불가] 아직 몬스터가 너무 강합니다! (체력 15% 이상)" << std::endl;
    }
}

// 소화 스킬 로직
void Player::SkillDigestion(Item* targetItem)
{
    if (isDead || targetItem == nullptr) return;

    std::cout << "\n[소화 중] " << targetItem->getName() << "을(를) 깊숙이 삼킵니다..." << std::endl;

    // 50% 확률 로직 적용
    if (rand() % 2 == 0)
    {
        // 소화 성공
        std::cout << " >> 옴뇸뇸~ 우마이~" << std::endl;
        std::cout << " [시스템] 전리품의 힘이 온몸으로 퍼집니다!" << std::endl;
        targetItem->Use(this); // 아이템에 저장된 몬스터 능력치 흡수
    }
    else
    {
        // 소화 실패
        std::cout << " >> 카악 퉷!" << std::endl;
        std::cout << " [시스템] 몸에 맞지 않아 영혼을 토해냈습니다.(추가 능력치 0)" << std::endl;
    }
}
