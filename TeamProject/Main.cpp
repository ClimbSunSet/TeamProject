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
#include <conio.h>

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
    system("mode con cols=120 lines=35"); // UI 박스 크기에 맞게 조절

    // 1. 타이틀 화면 출력
    Title title;
    title.DrawTitle();

    // 2. 게임 시스템 초기화
    GameSystem GS;
    GS.GameStart(); // 이름 입력 및 플레이어 생성

    // 3. 메인 게임 루프
    bool isGameOver = false;
    int stage = 1;
    const int maxStage = 3;

    while (!isGameOver && stage <= maxStage)
    {
        // 전투 실행
        GS.RunBattle();

        // 전투 종료 후 플레이어 상태 체크
        if (GS.player.GetHP() <= 0)
        {
            isGameOver = true;
            /* std::cout << "\n 게임 오버... 아무 키나 누르면 종료됩니다." << std::endl; */
            // 박스 안 로그 영역(예: 10번 줄)에 출력 (김준태)
            GS.UI.PrintMessage("게임 오버... 아무 키나 누르면 종료됩니다.", 10);
            (void)_getch();
            break;
        }

        // 전투 사이 휴식 및 정비 소화 시도 메시지는 RunRest 내부에서 처리됨
        GS.RunRest();

        // [수정] 박스 밖으로 나가던 다음 스테이지 메시지를 박스 안으로 넣음 (김준태)
        std::string stageMsg = "다음 스테이지로 이동하려면 아무 키나 누르세요... (" + std::to_string(stage) + "/" + std::to_string(maxStage) + ")";
        GS.UI.PrintMessage(stageMsg, 12); // 로그 창 12번 라인쯤에 출력

        (void)_getch();

        GS.UI.GameMain();

        stage++;
    }

    // 4. 엔딩 크레딧 출력
    system("cls");
    EndingCredit ending;
    ending.ShowCredit();

    return 0;
}
