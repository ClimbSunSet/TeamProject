// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>


#include "Player.h"
#include "Monster.h"
#include "GameSystem.h"
#include "BattleSystem.h"
#include "UISystem.h"


int main(void)
{
	//system("mode con cols=100 lines=40");
	//UISystem UI;
	//Player player;
	//UI.GameMain();
	//UI.PrintStatus(player);

	GameSystem GS;

	GS.GameStart();

	GS.RunBattle();

	GS.RunBattle();

	GS.RunBattle();

	GS.RunRest();
	

	return 0;
}

