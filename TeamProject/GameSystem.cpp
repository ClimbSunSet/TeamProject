// GameSystem.cpp

#include "GameSystem.h"
#include <windows.h>

void ShowMonsterLoading();

void GameSystem::GameStart()
{
	std::string NickName;

    UI.GameMain(); // 1. 먼저 UI 틀을 그려줍니다 (김준태

    system("cls"); // 이름 입력 전 화면 정리 (김준태)

	//std::cout << "플레이어의 이름 입력해주세요!" << std::endl;
	//std::cout << "입력 : ";
    UI.SetCursor(45, 10); std::cout << "============================";
    UI.SetCursor(45, 11); std::cout << " 플레이어의 이름을 입력하세요 ";
    UI.SetCursor(45, 12); std::cout << "============================";
    UI.SetCursor(45, 13); std::cout << " 입력 : ";

	std::cin >> NickName;

    ShowMonsterLoading();

	player = Player(NickName);

    UI.GameMain();  // (김준태)
    UI.PrintMessage(NickName + " 플레이어가 생성 되었습니다!", 0); // (김준태)

}

void GameSystem::RunBattle()
{
	BattleSystem BS;
	Structs::MonsterRewardInfo reward = {};
	BS.Battle(player, reward, *this, UI); // , UI추가 (김준태)
	
}

void GameSystem::RunRest()
{
	/*std::cout << "분기점에서 소화를 시도합니다!" << std::endl;*/
    UI.PrintMessage("분기점에서 소화를 시도합니다!", 0);
	player.SkillDigestion(UI); // UI 추가 (김준태)
}

int GameSystem::RandomMonsterSpawn()
{
	int Random = rand() % 4;
	
	return Random;
}
