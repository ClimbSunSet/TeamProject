// HPPotion.h

#pragma once

#include <iostream>
#include <string>

#include "Item.h"

class HPPotion : public Item
{
private:
	
public:
	void UseItem(Player& player) override;
};