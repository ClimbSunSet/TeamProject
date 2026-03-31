// Item.h

#pragma once

#include <iostream>
#include <string>

class Player;

class Item
{
private:
	std::string Name;

public:
	virtual void UseItem(Player& player) = 0;
};

