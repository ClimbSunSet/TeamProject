// UISystem.cpp

#include "UISystem.h"
#include <iostream>

void UISystem::SetCursor(int x, int y)
{
    // SHORT 캐스팅으로 안정성 확보 (김준태)
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 메시지 출력 함수 (이전 줄 지우기 포함)
void UISystem::PrintMessage(std::string msg, int line)
{
    // 로그 영역의 시작 위치 (김준태)
    int startX = 12;
    int startY = 3;

    SetCursor(startX, startY + line);
    // 70칸의 표준 공백으로 이전 텍스트를 깨끗하게 지움 (김준태)
    std::cout << "                                                                      ";

    SetCursor(startX, startY + line);
    std::cout << ">> " << msg;
}

void UISystem::GameMain()
{
    // 상단 로그 박스 가로선
    SetCursor(10, 1);
    std::cout << "=================================================================================";

    // 상단 로그 박스 세로벽 (2번부터 19번 라인까지 반복문으로 안전하게 출력)
    for (int i = 2; i <= 19; i++)
    {
        SetCursor(10, i);
        std::cout << "|"; // 왼쪽 벽
        SetCursor(91, i);
        std::cout << "|"; // 오른쪽 벽 (공백으로 밀지 않고 좌표로 직접 찍음 - 김준태)
    }

    // 상단 로그 박스 하단 가로선
    SetCursor(10, 20);
    std::cout << "=================================================================================";

    // 하단 스탯/명령창 상단 가로선
    SetCursor(10, 22);
    std::cout << "====================  ===========================================================";

    // 하단 박스 세로벽 (23번부터 28번 라인까지)
    for (int i = 23; i <= 28; i++)
    {
        SetCursor(10, i); std::cout << "|"; // 왼쪽 끝
        SetCursor(30, i); std::cout << "|"; // 스탯창 오른쪽
        SetCursor(32, i); std::cout << "|"; // 명령창 왼쪽
        SetCursor(91, i); std::cout << "|"; // 오른쪽 끝
    }

    // 하단 박스 최하단 가로선
    SetCursor(10, 29);
    std::cout << "====================  ===========================================================";
}

void UISystem::PrintStatus(Player player)
{
    // 스탯 창 내부 (X: 12~29 사이) 위치에 맞게 출력 (김준태)
    SetCursor(12, 23); std::cout << "  [ STAT ]";
    SetCursor(12, 24); std::cout << " HP  : " << player.GetHP() << "/" << player.GetMaxHP();
    SetCursor(12, 25); std::cout << " ATK : " << player.GetATK();
    SetCursor(12, 26); std::cout << " EXP : " << player.GetEXP();
    SetCursor(12, 27); std::cout << " LUK : " << player.GetLUK();
    SetCursor(12, 28); std::cout << " GOLD: " << player.GetGOLD();
}
