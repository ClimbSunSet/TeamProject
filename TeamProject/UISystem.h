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

private:
	void SetCursor(int x, int y);
};