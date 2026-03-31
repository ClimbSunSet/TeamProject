//// Main.cpp
//
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <windows.h>
//
//
//#include "Player.h"
//#include "Monster.h"
//#include "GameSystem.h"
//#include "BattleSystem.h"
//#include "UISystem.h"
//
//
//int main(void)
//{
//	//system("mode con cols=100 lines=40");
//	//UISystem UI;
//	//Player player;
//	//UI.GameMain();
//	//UI.PrintStatus(player);
//
//	GameSystem GS;
//
//	GS.GameStart();
//
//	GS.RunBattle();
//
//	GS.RunBattle();
//
//	GS.RunBattle();
//
//	GS.RunRest();
//	
//
//	return 0;
//}



// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <conio.h> // _getch() 사용을 위해 추가 (김준태)

#include "Player.h"
#include "GameSystem.h"
#include "BattleSystem.h"
#include "UISystem.h"
#include "Title.h"
#include "EndingCredit.h"

int main(void)
{
    // 0. 랜덤 시드 및 콘솔 설정
    srand((unsigned int)time(NULL));
    system("mode con cols=110 lines=35"); // UI 박스 크기에 맞게 조절 (김준태)

    // 1. 타이틀 화면 출력
    Title title;
    title.DrawTitle(); // 내부에서 system("cls")와 _getch()가 작동하도록 수정됨

    // 2. 게임 시스템 초기화
    GameSystem GS;
    GS.GameStart(); // 이름 입력 및 플레이어 생성

    // 3. 메인 게임 루프 (김준태)
    // 바로 엔딩으로 넘어가는 것을 방지하기 위해 루프를 구성합니다.
    bool isGameOver = false;
    int stage = 1;
    const int maxStage = 3; // 총 3번의 전투 후 엔딩

    while (!isGameOver && stage <= maxStage)
    {
        // 전투 실행 (GameSystem 내부에서 BS.Battle(..., UI)를 호출함)
        // RunBattle이 사망 여부를 반환하도록 설계했다면 여기서 체크 가능합니다.
        GS.RunBattle();

        // 전투 종료 후 플레이어 상태 체크
        if (GS.player.GetHP() <= 0)
        {
            isGameOver = true;
            std::cout << "\n 게임 오버... 아무 키나 누르면 종료됩니다." << std::endl;
            (void)_getch();
            break;
        }

        // 전투 사이 휴식 및 정비
        GS.RunRest();

        std::cout << "\n 다음 스테이지로 이동하려면 아무 키나 누르세요... (" << stage << "/" << maxStage << ")" << std::endl;
        (void)_getch();

        stage++;
    }

    // 4. 엔딩 크레딧 출력
    system("cls");
    EndingCredit ending;
    ending.ShowCredit();

    return 0;
}
