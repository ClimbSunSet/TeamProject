#include "Player.h"
#include "Monster.h"

Player::Player(std::string name)
    : Name(name), Level(1), HP(200), MaxHp(200), ATK(30), EXP(0), LUCK(5), GOLD(0), isDead(0)
{
    std::cout << "\n주인공: '" << Name << "' 생성 완료되었습니다.\n" << std::endl;
}

Player::~Player()
{
    if (isDead)
    {
        std::cout << " 사망 " << Name << " 캐릭터 HP가 0이되어 소멸됩니다." << std::endl;
    }
}

// --- Getter 구현 ---
std::string Player::GetName() const { return Name; }
int Player::GetLevel() const { return Level; }
int Player::GetHP() const { return HP; }
int Player::GetMaxHp() const { return MaxHp; }
int Player::GetAtk() const { return ATK; }
int Player::GetLuck() const { return LUCK; }
bool Player::GetisDead() const { return isDead; }

// --- Setter 구현 ---
void Player::SetName(const std::string& newName) { Name = newName; }
void Player::SetLevel(unsigned int newLevel) { Level = newLevel; }
void Player::SetHP(int newHP)
{
    HP = std::min(MaxHp, newHP);
    CheckDeath();
}
void Player::SetMaxHp(int newMaxHp) { MaxHp = newMaxHp; }
void Player::SetAtk(int newAtk) { ATK = newAtk; }
void Player::SetLuck(int newLuck) { LUCK = newLuck; }
void Player::SetisDead(bool dead) { isDead = dead; }


void Player::ShowStatus() const
{
    std::cout << "========== 캐릭터 상태 ==========" << std::endl;
    std::cout << " 이름    : " << Name << std::endl;
    std::cout << " 레벨    : " << Level << std::endl;
    std::cout << " 체력    : " << HP << " / " << MaxHp << std::endl;
    std::cout << " 공격력  : " << ATK << std::endl;
    std::cout << " 경험치  : " << EXP << " / " << MaxExp << std::endl;
    std::cout << " 보유골드: " << GOLD << " G" << std::endl;
    std::cout << "=================================" << std::endl;
}

void Player::CheckDeath()
{
    if (HP <= 0)
    {
        HP = 0;
        if (isDead == 1)
        {
            isDead = 1;
            //std::cout << "\n[!] 가오나시가 폭주하며 괴로워합니다! [HP: 0]" << std::endl;
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
            //std::cout << "   /   vvvvvvv   \\   " << std::endl; // 토해내는 묘사
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

            //std::cout << "\n [" << Name << "]가 먼지가 되어 사라졌습니다." << std::endl;
            //std::cout << "========================================\n" << std::endl;
        }
    }
}

// 자동 회복 체크 함수 로직 (아직 미구현 인벤토리 헤더 필요)
//void Player::CheckAutoHeal()
//{
//    if (isDead == 1 || HP > 50) { return; } // 죽었거나 체력이 50 넘으면 패스
//
//    std::cout << "\n 우웁... 아프다..." << std::endl;
//}

// 데미지 입는 로직
void Player::TakeDamage(int damage)
{
    HP = std::max(0, HP - damage);
    std::cout << Name << "이(가) " << damage << "의 데미지를 입었습니다.(현재: " << HP << ")" << std::endl;
    CheckDeath();
}


// 회복 로직
void Player::HealHp(int Hpamount)
{
    if (isDead == 1)
    {
        std::cout << "사망한 상태에서는 회복할 수 없습니다." << std::endl;
        return;
    }
    HP = std::min(MaxHp, HP + Hpamount);
    std::cout << "체력을 " << Hpamount << "만큼 회복했습니다. (현재 체력: " << HP << ")" << std::endl;
}

// Attack함수
void Player::Attack(Monster* target)
{
    // [안전 장치] 내가 죽었거나 공격 대상이 없으면 중단
    if (isDead == 1 || target == nullptr) return;

    // 공격 메시지 출력
    std::cout << "\n" << Name << "이(가) " << target->GetName() << "을(를) 공격합니다!" << std::endl;

    // 몬스터에게 내 공격력(ATK)만큼 데미지 입히기
    target->TakeDamage(ATK); // 상대방의 TakeDamage 함수에 내 ATK를 보냄

    // 공격 후 결과 출력
    std::cout << " -> " << target->GetName() << "에게 " << ATK << "의 피해를 주었습니다." << std::endl;

    // 몬스터가 죽었으면 포식 시도
    if (target->isDead())
    {
        std::cout << "\n[!] " << target->GetName() << "이(가) 쓰러졌습니다! 포식을 시도합니다!" << std::endl;
        
        SkillPredation(target); // 몬스터가 죽었으니 확정 포식
    }

    // 아직 안 죽었지만 15% 미만인 경우 (기존 힌트 유지)
    else
    {
        int mHp = target->GetHP();
        int mMaxHp = target->GetMaxHP();
        if ((mHp * 100 / mMaxHp) < 15)
        {
            std::cout << "( 몬스터가 몹시 지쳐 보입니다. 지금 포식을 사용해 처형할 수 있습니다!" << std::endl;
        }
    }
}

// 포식 로직
void Player::SkillPredation(Monster* target)
{
    if (isDead == 1 || target == nullptr) return;

    std::string mName = target->GetName();
    int mCurrentHp = target->GetHP();
    int mMaxHp = target->GetMaxHP();

    // 15% 미만이면서 '살아있을 때'만 처형 UI 출력
    bool isExecutable = (mCurrentHp > 0 && (mCurrentHp * 100 / mMaxHp) < 15);

    if (isExecutable == 1)
    {
        std::cout << "\n[ 가오나시의 눈이 붉게 일렁입니다... ]" << std::endl;
        std::cout << " ( " << mName << "은(는) 지쳐 있다... 지금이라면 먹을 수 있을 것 같다... )" << std::endl;
        std::cout << ">> [처형 표식 활성화] <<" << std::endl;
    }

    int successChance = 50 + LUCK;
    int roll = rand() % 100;
    bool isSuccess = false;

    // --- 판정 로직 분리 ---
    if (mCurrentHp <= 0)
    {
        // 이미 죽은 경우: 무조건 성공 영혼 수습)
        isSuccess = 1;
        std::cout << "\n [!] " << mName << "의 몬스터에서 영혼을 추출합니다." << std::endl;
    }
    else if (isExecutable && roll < successChance)
    {
        // 살아있지만 처형 성공한 경우
        isSuccess = 1;
        target->TakeDamage(target->GetHP()); // 처형
        std::cout << "\n [처형 성공] " << mName << "의 숨통을 끊고 영혼을 삼켰습니다!" << std::endl;
    }

    // 결과 처리
    if (isSuccess == 1)
    {
        std::cout << "\n [포식 성공!] " << Name << "이(가) " << mName << "을(를) 통째로 삼켰습니다!" << std::endl;

        // 인벤토리로 영혼? 보관 아직 미완



    }
    else
    {
        if (isExecutable == 1)
        {
            std::cout << "\n [포식 실패] " << mName << "이(가) 거세게 저항하여 삼키지 못했습니다!" << std::endl;
        }
        else
        {
            std::cout << "\n [포식 불가] 아직 몬스터가 너무 강합니다! (체력 15% 이상입니다.)" << std::endl;
        }
    }
}
