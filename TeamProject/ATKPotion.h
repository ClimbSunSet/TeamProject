// ATKPotion.h

#pragma once

#include <iostream>
#include <string>

#include "Item.h"

class ATKPotion : public Item
{
private:

public:
	void UseItem(Player& player) override;
};