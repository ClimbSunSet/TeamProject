// UISystem.h

#pragma once

#include <iostream>
#include <windows.h>

#include "Player.h"

class UISystem
{
public:
	void GameMain();
	void PrintStatus(Player player);

    void PrintMessage(std::string msg, int line); // TEST용(김준태)
    void SetCursor(int x, int y); // private에 있던거 위로 올림 (김준태)

//private:
//	void SetCursor(int x, int y);
};
