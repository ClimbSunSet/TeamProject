//wildboar.h

#pragma once
#include "Monster.h"

class wildboar : public Monster
{
public:
	wildboar(int playerLevel);
	void Attack() override;
};

