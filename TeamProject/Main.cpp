// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Player.h"
#include "Monster.h"
#include "BattleSystem.h"

int main(void)
{
	Player player1("가오나시");

	std::string NickName;
	std::cout << "캐릭터의 이름을 입력하세요" << std::endl;
	std::cout << "입력 : " ;
	
	std::cin >> NickName;
	player1.SetName(NickName);

	Monster Slime;

	Rewardinfo Reward = {};

	BattleSystem BS;

	std::cout << "캐릭터와 슬라임이 생성 되었습니다!" << std::endl;
	std::cout << "슬라임과 전투에 돌입합니다." << std::endl;

	BS.Battle(player1, Slime, Reward);

	return 0;
}