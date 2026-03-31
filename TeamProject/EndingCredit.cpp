#include "EndingCredit.h"
#include <iostream>
#include <windows.h>          
#include <conio.h>
#include <iomanip>          

EndingCredit::EndingCredit()
{
    credits.push_back({ "플레이어 캐릭터 생성", "김준태" });
    credits.push_back({ "몬스터", "임기정" });
    credits.push_back({ "전투 시스템", "김승하" });
    credits.push_back({ "레벨업", "남다희" });
    credits.push_back({ "아이템", "유승서" });
    credits.push_back({ "게임로그확인", "황인성" });
}

EndingCredit::~EndingCredit() {}

void EndingCredit::gotoxy(int x, int y)
{
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void EndingCredit::setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void EndingCredit::ShowCredit()
{
    system("cls");

    setColor(11); // 하늘색
    gotoxy(50, 5); std::cout << "=== GAME CLEAR ===";

    setColor(14); // 노란색
    gotoxy(51, 7); std::cout << "[ ENDING CREDIT ]";

    int startY = 10;
    for (int i = 0; i < (int)credits.size(); i++)
    {
        gotoxy(40, startY + (i * 2));

        setColor(15); // 흰색
        std::cout << std::left << std::setw(30) << credits[i].role;

        setColor(10); // 연두색
        std::cout << " : " << credits[i].name;

        Sleep(600);
    }

    setColor(8);
    gotoxy(36, 23);
    std::cout << "감사합니다! 아무 키나 누르면 프로그램을 종료합니다.";

    (void)_getch();
}
