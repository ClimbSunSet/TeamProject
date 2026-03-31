#include "Title.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

Title::Title() : gameTitle("가오나시 키우기") {}
Title::~Title() {}

// 좌표 이동 함수 (SHORT 형변환 추가)
void Title::gotoxy(int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 색상 변경 함수
void Title::setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Title::DrawTitle() {
    system("mode con cols=120 lines=30");
    system("cls");

    // 2. 대형 영어 로고 출력 (노란색: 14)
    setColor(14);
    gotoxy(25, 6);  std::cout << " d888b   .d8b.   .d88b.  d8b   db  .d8b.  .d888b. db   db d888888b";
    gotoxy(25, 7);  std::cout << "88' Y8b d8' `8b .8P  Y8. 888o  88 d8' `8b 88'  YP 88   88   `88'  ";
    gotoxy(25, 8);  std::cout << "88      88ooo88 88    88 88V8o 88 88ooo88 `8bo.   88ooo88    88   ";
    gotoxy(25, 9);  std::cout << "88  ooo 88~~~88 88    88 88 V8o88 88~~~88   `Y8b. 88~~~88    88   ";
    gotoxy(25, 10); std::cout << "88. ~8~ 88   88 `8b  d8' 88  V888 88   88 db   8D 88   88   .88.  ";
    gotoxy(25, 11); std::cout << " Y888P  YP   YP  `Y88P'  VP   V8P YP   YP `8888Y' YP   YP Y888888P";

    // 3. 한글 부제 출력 (흰색: 15)
    setColor(15);
    gotoxy(48, 13); std::cout << "★ " << gameTitle << " ★";

    // 4. 안내 문구 (회색: 8)
    setColor(8);
    gotoxy(43, 17); std::cout << "--- PRESS ANY KEY TO START ---";

    // 5. 키 입력 대기 (반환값 무시 처리)
    (void)_getch();

    system("cls");
}
