// GameSystem.cpp

#include "GameSystem.h"

void GameSystem::GameStart()
{
	std::string NickName;

	std::cout << "플레이어의 이름 입력해주세요!" << std::endl;
	std::cout << "입력 : ";
	std::cin >> NickName;

	player = Player(NickName);
	std::cout << "플레이어가 생성 되었습니다!" << std::endl;

}

void GameSystem::RunBattle()
{
	BattleSystem BS;
	Structs::MonsterRewardInfo reward = {};
	BS.Battle(player, reward, *this);
	
}

void GameSystem::RunRest()
{
	std::cout << "분기점에서 소화를 시도합니다!" << std::endl;
	player.SkillDigestion();
}

int GameSystem::RandomMonsterSpawn()
{
	int Random = rand() % 4;
	
	return Random;
}