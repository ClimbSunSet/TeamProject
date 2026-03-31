// UISystem.cpp

#include "UISystem.h"

void UISystem::SetCursor(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void UISystem::GameMain()
{
	SetCursor(0, 1);
	std::cout << "          " << "===================================================================================" << std::endl;

	SetCursor(0, 2);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 3);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 4);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 5);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 6);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 7);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 8);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 9);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 10);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  
	
	SetCursor(0, 11);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 12);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;  

	SetCursor(0, 13);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;

	SetCursor(0, 14);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;

	SetCursor(0, 15);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;

	SetCursor(0, 16);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;

	SetCursor(0, 17);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;

	SetCursor(0, 18);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;

	SetCursor(0, 19);
	std::cout << "          " << "|" << "                                                                                 " << "|" << std::endl;

	SetCursor(0, 20);
	std::cout << "          " << "===================================================================================" << std::endl;

	SetCursor(0, 22);
	std::cout << "          " << "====================  =============================================================" << std::endl;

	SetCursor(0, 23);
	std::cout << "          " << "|" << "                  |  |                                                           " << "|" << std::endl;

	SetCursor(0, 24);
	std::cout << "          " << "|" << "                  |  |                                                           " << "|" << std::endl;

	SetCursor(0, 25);
	std::cout << "          " << "|" << "                  |  |                                                           " << "|" << std::endl;

	SetCursor(0, 26);
	std::cout << "          " << "|" << "                  |  |                                                           " << "|" << std::endl;

	SetCursor(0, 27);
	std::cout << "          " << "|" << "                  |  |                                                           " << "|" << std::endl;

	SetCursor(0, 28);
	std::cout << "          " << "|" << "                  |  |                                                           " << "|" << std::endl;

	SetCursor(0, 29);
	std::cout << "          " << "====================  =============================================================" << std::endl;
}

void UISystem::PrintStatus(Player player)
{
	SetCursor(14, 23);
	std::cout << "  [ STAT ] " << std::endl;
	SetCursor(14, 24);
	std::cout << "HP = " << player.GetHP() << "/" << player.GetMaxHP() << std::endl;
	SetCursor(14, 25);
	std::cout << "ATK = " << player.GetATK() << std::endl;
	SetCursor(14, 26);
	std::cout << "EXP = " << player.GetEXP() << std::endl;
	SetCursor(14, 27);
	std::cout << "LUK = " << player.GetLUK() << std::endl;
	SetCursor(14, 28);
	std::cout << "GOLD = " << player.GetGOLD() << std::endl;
}