#include "BattleSystem.h"
#include "GameSystem.h"
#include "Monster.h"
#include "SewerRat.h"
#include "MiniPig.h"
#include "WildBoar.h"
#include "Goblin.h"
#include "HPPotion.h"
#include "ATKPotion.h"
#include <string> 
#include <windows.h> 

bool BattleSystem::Battle(Player& player, Structs::MonsterRewardInfo reward, GameSystem& random, UISystem& UI)
{
    UI.GameMain();
    int logLine = 0;
    bool isPlayerDead;

    // 1. 포션 사용 메뉴
    if (!player.GetInventory().empty())
    {
        UsePotion(player, UI);
        UI.GameMain();
    }

    // 몬스터 생성
    int monsterType = random.RandomMonsterSpawn();
    Monster* mons;
    if (monsterType == 0) mons = new SewerRat(player.GetLevel());
    else if (monsterType == 1) mons = new MiniPig(player.GetLevel());
    else if (monsterType == 2) mons = new WildBoar(player.GetLevel());
    else mons = new Goblin(player.GetLevel());

    UI.PrintMessage(mons->GetName() + "가 등장했습니다!", logLine++);
    Sleep(1000);

    // --- 전투 루프 ---
    while (player.GetHP() > 0 && mons->GetHP() > 0)
    {
        UI.PrintStatus(player);

        // [플레이어 턴]
        player.Attack(UI); // "공격했습니다" 출력 (박스 상단)
        int damage = player.GetATK();

        // ★ Monster.cpp 내부에서 logLine을 받아 공백 없이 출력하도록 수정됨
        mons->TakeDamage(damage, UI, logLine);
        // BattleSystem에서 중복으로 "데미지 입혔습니다"를 출력하던 코드는 삭제했습니다 (중복 제거)
        Sleep(1000);

        // 몬스터 사망 시 즉시 루프 탈출 (사망 메시지는 TakeDamage 안에서 이미 출력됨)
        if (mons->GetHP() <= 0) break;

        // [몬스터 턴]
        mons->Attack();
        player.TakeDamage(mons->GetATK(), UI); // 플레이어 피격 연출 (박스 상단)

        // 몬스터의 공격 기록을 로그창에 출력
        UI.PrintMessage(mons->GetName() + "의 공격! " + std::to_string(mons->GetATK()) + "의 피해를 입었습니다.", logLine++);
        Sleep(1000);

        // 로그가 꽉 차면 화면 초기화
        if (logLine >= 14) { UI.GameMain(); logLine = 0; }
    }

    // --- [전투 종료 후 시퀀스] 준태님 요청 순서 적용 ---

    // 1. 전투 종료 메시지 (가장 먼저)
    UI.PrintMessage("전투가 종료되었습니다!", logLine++);
    Sleep(1000);

    if (player.GetHP() <= 0)
    {
        isPlayerDead = true;
        UI.PrintMessage("캐릭터가 사망하여 처음으로 돌아갑니다!", logLine++);
    }
    else
    {
        isPlayerDead = false;

        // 2. 포식 발동 여부 확인 (전투 종료 1초 뒤 실행)
        if (mons->GetHP() <= (mons->GetMaxHP() * 0.15))
        {
            mons->isPredated = true;
            UI.PrintMessage(">> 포식 스킬을 발동합니다!", logLine++);
            Sleep(1000);

            // ★ Player.cpp 내부에서 logLine을 받아 "포식 성공/실패"를 공백 없이 출력
            player.SkillPredation(mons, UI, logLine);
            Sleep(1000);
        }

        // 3. 최종 보상 획득 (순차적으로)
        BattleReward(player, reward, UI, logLine);
    }

    // 버프 해제 (준태님 원본 방식 유지)
    if (player.GetIsAttackBuffActive() == true)
    {
        player.SetIsAttackBuffActive(false);
        int ATK = player.GetATK() - 10;
        player.SetATK(ATK);
    }

    if (!mons->isPredated)
    {
        delete mons;
        mons = nullptr;
    }

    UI.PrintStatus(player);
    return isPlayerDead;
}

// 보상 함수
Structs::MonsterRewardInfo BattleSystem::BattleReward(Player& player, Structs::MonsterRewardInfo reward, UISystem& UI, int& logLine)
{
    reward.EXP += 50;
    UI.PrintMessage("플레이어의 경험치가 50 증가했습니다!", logLine++);
    Sleep(1000);

    int RewardGOLD = rand() % 11 + 10;
    reward.GOLD = RewardGOLD;
    UI.PrintMessage("소지 GOLD가 " + std::to_string(RewardGOLD) + "만큼 추가되었습니다!", logLine++);
    Sleep(1000);

    int chance = rand() % 100;
    if (chance < 30)
    {
        int itemChance = rand() % 2;
        if (itemChance == 0) {
            player.AddItem(new HPPotion());
            UI.PrintMessage("HP포션을 발견하여 인벤토리에 추가했습니다!", logLine++);
        }
        else {
            player.AddItem(new ATKPotion());
            UI.PrintMessage("ATK포션을 발견하여 인벤토리에 추가했습니다!", logLine++);
        }
        Sleep(1000);
    }
    return reward;
}

void BattleSystem::UsePotion(Player& player, UISystem& UI)
{
    while (true)
    {
        int choice;
        UI.SetCursor(35, 23); std::cout << " [ 포션 사용 메뉴 ]          ";
        UI.SetCursor(35, 24); std::cout << " 1. HP포션                    ";
        UI.SetCursor(35, 25); std::cout << " 2. ATK포션                   ";
        UI.SetCursor(35, 26); std::cout << " 3. 사용안함                  ";
        UI.SetCursor(35, 27); std::cout << " 입력 :                       ";

        UI.SetCursor(43, 27);
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        }

        if (choice == 1 || choice == 2)
        {
            if (player.GetInventory().size() >= (size_t)choice)
            {
                player.GetInventory()[choice - 1]->UseItem(player);
                break;
            }
            else
            {
                UI.SetCursor(35, 28); std::cout << "아이템이 없습니다!            ";
                Sleep(1000);
            }
        }
        else if (choice == 3) break;
        else {
            UI.SetCursor(35, 28); std::cout << "잘못된 입력입니다!            ";
            Sleep(1000);
        }
    }
}
