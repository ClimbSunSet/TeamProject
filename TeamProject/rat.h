//rat.h

#pragma once
#include "Monster.h"

class rat : public Monster
{
public:
	rat(int playerLevel);
	void Attack() override;
};

